#include "TicTacToe.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void TicTacToe::PlayGame()
{
    // Initialize random generator engine
    std::random_device rd;
    const std::mt19937 gen(rd());
    const std::uniform_int_distribution<int> randInt(1, 9);

    // Instructions
    
    // Request move first or second
    RequestMove();

    // Request Noughts or crosses
    RequestOx();
    
    // Create board - 3x3 array
    PrintBoard();

    bool playing = true;

    // Play game loop
    while (playing)
    {
        if (playerTurn_)
        {
            DoPlayerTurn(playing);
        }
        else
        {
            // Could make it play strategically instead of randomly?
            DoCpuTurn(gen, randInt, playing);
        }
        
        PrintBoard();
    }
}

void TicTacToe::RequestMove()
{
    std::string input;
    bool inputValid = false;

    while (!inputValid)
    {
        std::cout << "Move first or second?: ";
        std::cin >> input;

        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

        if (input == "FIRST")
        {
            playerTurn_ = true;
            inputValid = true;   
        }
        else if (input == "SECOND")
        {
            playerTurn_ = false;
            inputValid = true;
        }   
        else
            std::cout << "Try again.\n";
    }
}

void TicTacToe::RequestOx()
{
    std::string input;
    bool inputValid = false;
    
    while (!inputValid)
    {
        std::cout << "NOUGHTS or CROSSES?: ";
        std::cin >> input;

        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

        if (input == "CROSSES")
        {
            isCross_ = true;
            inputValid = true;
        }
        else if (input == "NOUGHTS")
        {
            isCross_ = false;
            inputValid = true;
        }
        else
            std::cout << "Try again.\n";
    }
}

void TicTacToe::PrintBoard()
{
    std::cout << "Printing Board...\n";
    
    /*
     *  3 [ ] [ ] [ ]      3 [O] [ ] [X]
     *  2 [ ] [ ] [ ]  ->  2 [O] [ ] [ ]
     *  1 [ ] [ ] [ ]      1 [X] [ ] [ ]
     *     a   b   c          a   b   c
     */

    // From a3, b3, c3, a2.... check if one of the players have it
    // if so, replace the space with X or O
    for (int i{0}; i < static_cast<int>(table_.size()); i++)
    {
        // Print line numbers
        if (i % 3 == 0)
        {
            std::cout
            << '\n' << std::setw(2) << std::right << -(i / 3) + 3;
        }

        // Maybe more optimised to use pointer here to avoid string copies?
        const std::string* position{&table_.at(i + 1)};

        // Check if CPU contains that string and continue if so
        if (CheckTaken(*position, CPU))
        {
            std::cout << " [" << (isCross_ ? "O" : "X") << "]";
            continue;
        }

        // Check if Player contains that string and continue if so
        if (CheckTaken(*position, USER))
        {
            std::cout << " [" << (isCross_ ? "X" : "O") << "]";
            continue;
        }
        
        // If no one then print normal
        std::cout << " [ ]";
    }

    std::cout << "\n    a   b   c \n";
}

bool TicTacToe::PlayPiece(const std::string& position, Players player)
{
    // Check that neither player has taken that piece
    if (!CheckTaken(position, CPU) && !CheckTaken(position, USER))
    {
        // Add to player
        playState_[player].emplace(position);
        return true;
    }
    
    return false;
}

void TicTacToe::DoPlayerTurn(bool& playing)
{
    std::string input;
    std::cout << "Enter your move (letter followed by number): ";
    std::cin >> input;

    // Check valid input and move was successful
    if (CheckValid(input) && PlayPiece(input, USER))
    {
        // Check if winning condition
        if(CheckWin(USER))
        {
            std::cout << "You've won!\n";
            playing = false;
        }
                    
        // Change turn
        playerTurn_ = !playerTurn_;
    }
    else
    {
        std::cout << "Invalid input. Try again.\n";
    }
}

void TicTacToe::DoCpuTurn(std::mt19937 gen, const std::uniform_int_distribution<int> randInt, bool& playing)
{
    std::cout << "Doing CPU turn...\n";

    // Select random move until valid
    bool valid = false;
    while (!valid)
    {
        std::string input = table_.at(randInt(gen));

        // Check valid input and move was successful
        if (CheckValid(input) && PlayPiece(input, CPU))
        {
            // Check if winning condition
            if(CheckWin(CPU))
            {
                std::cout << "You've lost!\n";
                playing = false;
            }
                    
            // Change turn
            playerTurn_ = !playerTurn_;

            // Set valid
            valid = true;
        }
    }
}

// Check the player has taken that piece
bool TicTacToe::CheckTaken(const std::string& position, const Players player)
{
    return playState_[player].find(position) != playState_[player].end();
}

// Check input is valid for table
bool TicTacToe::CheckValid(const std::string& position)
{
    return std::any_of(table_.begin(), table_.end(), [&](const auto& value) -> bool
    {
       if (value.second == position)
           return true;
        return false;
    });
    
}

// Check if play has caused a win
bool TicTacToe::CheckWin(const Players player)
{
    // Static table with program-wide duration
    // No need to recreate table each time method is called
    // Only needs scope limited to this method
    static const std::set<std::set<std::string>> winningTable
    {
        // columns
        {"a1", "a2", "a3"},
        {"b1", "b2", "b3"},
        {"c1", "c2", "c3"},
        // rows
        {"a1", "b1", "c1"},
        {"a2", "b2", "c2"},
        {"a3", "b3", "c3"},
        // diagonals
        {"a1", "b2", "c3"},
        {"a3", "b2", "c1"},
    };

    auto selectedList = playState_[player];

    // Check if any winning position is a subset of selected list
    for (const auto& winCombo : winningTable)
    {
        if (std::includes(selectedList.begin(), selectedList.end(),
            winCombo.begin(), winCombo.end()))
        {
            return true;
        }
    }
    
    return false;
}

TicTacToe::TicTacToe()
{
    std::cout << "Starting game... \n";
    
    /*
     * map O -> {a2, a3}
     * map X -> {a1, c3)
     * ---> std::map<Player, std::set<std::string>>
     */

    // Start tracking play state with both sides empty
    playState_.emplace(USER, std::set<std::string>{});
    playState_.emplace(CPU, std::set<std::string>{});
}

TicTacToe::~TicTacToe()
{
    std::cout << "Ending game...\n";
}
