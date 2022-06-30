#include "TicTacToe.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

void TicTacToe::PlayGame()
{
    // Instructions
    
    // Request move first or second
    RequestMove();

    // Request Noughts or crosses
    RequestOX();
    
    // Create board - 3x3 array
    PrintBoard();

    bool playing = true;
    
    while (playing)
    {
        // Game loop
        if (playerTurn_)
        {
            std::string input;
            std::cout << "Enter your move (letter followed by number): ";
            std::cin >> input;
        }
        else
        {
            
        }

        PrintBoard();
        
        playing = false;
    }
}

void TicTacToe::PrintBoard()
{
    /*
     *  3 [ ] [ ] [ ]      3 [O] [ ] [X]
     *  2 [ ] [ ] [ ]  ->  2 [O] [ ] [ ]
     *  1 [ ] [ ] [ ]      1 [X] [ ] [ ]
     *     a   b   c          a   b   c
     */

    // Static table with program-wide duration
    // No need to recreate table each time method is called
    // For converting from string to array position
    static std::map<std::string, int> const table =
    {
        {"a3", 1},
        {"b3", 2},
        {"c3", 3},
        
        {"a2", 4},
        {"b2", 5},
        {"c2", 6},
        
        {"a1", 7},
        {"b1", 8},
        {"c1", 9}
    };

    // From a3, b3, c3, a2.... check if one of the players have it
    // if so, replace the space with X or O

    for (unsigned int i{0}; i < table.size(); i++)
    {
        // Print line numbers
        if (i % 3 == 0)
        {
            std::cout
            << std::setw(2) << std::right << (i / 3);
        }

        // TODO: FIGURE OUT HOW TO PRINT THE BOARD
    }
    
    std::cout << "Printing Board...\n";
}

void TicTacToe::PlayPiece(const std::string c)
{
    // Call generic play piece method
    PlayPiece(c, true);
}

void TicTacToe::PlayPiece(const std::string c, bool isPlayer)
{
    
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

void TicTacToe::RequestOX()
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

bool TicTacToe::CheckWin(Players player)
{
    /* Check if player or CPU has winning position
    * {
    *   {a1, a2, a3},
    *   {b1, b2, b3},
    *   {c1, c2, c3},
    *   {a1, b2, c3},
    *   ...
    * }
    */

    auto selectedList = playState_[player];

    // Check if any winning position is a subset of selected list
    
    return true;
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
    playState_.emplace(PLAYER, std::set<std::string>{});
    playState_.emplace(CPU, std::set<std::string>{});
}

TicTacToe::~TicTacToe()
{
    std::cout << "Ending game...\n";
}
