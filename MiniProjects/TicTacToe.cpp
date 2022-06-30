#include "TicTacToe.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

void TicTacToe::PlayGame()
{
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
            
        }
        else
        {
            
        }

        
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
    
    std::cout << "Printing Board...\n";
}

void TicTacToe::PlayPiece(const char c1, const int c2)
{
    // Call generic play piece method
    PlayPiece(c1, c2, true);
}

void TicTacToe::PlayPiece(const char c1, const int c2, bool isPlayer)
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

    // REPLACED WITH BOOL
    // Static table with program-wide duration
    // No need to recreate table each time method is called
    // For converting from string to enum
    // static std::unordered_map<std::string, Player> const table =
    // {
    //     {"NOUGHTS", NOUGHTS},    
    //     {"CROSSES", CROSSES}    
    // };
    
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

bool TicTacToe::CheckWin()
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
}

TicTacToe::~TicTacToe()
{
    std::cout << "Ending game...\n";
}
