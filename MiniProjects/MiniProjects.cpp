#include "TicTacToe.h"

#include <iostream>

#include "Hangman/Hangman.h"


int main(int argc, char* argv[])
{
    bool playing = true;
    
    while (playing)
    {
        // Ask which game to play
        std::cout << "Which game would you like to play?\n";
        std::cout << "Input '1' for Tic Tac Toe\n";
        std::cout << "Input '2' for Hangman\n";
        std::cout << "Input '3' for Minesweeper\n";
        std::cout << "Input '4' for Match 3\n";
        std::cout << "Input '9' to quit\n";
        std::cout << "Make your choice: ";
    
        int choice{};
        std::cin >> choice;
    
        // Start that game
        switch (choice)
        {
            case 1:
            {
                std::cout << "\nPlaying Tic Tac Toe...\n";
                TicTacToe ticTacToe{};
                ticTacToe.PlayGame();
                ticTacToe.Reset();
                break;
            }
            case 2:
            {
                std::cout << "\nPlaying Hangman...\n";
                Hangman hangman{};
                hangman.PlayGame();
                hangman.Reset();
                break;
            }
            case 3:
            {
                std::cout << "\nMinesweeper not yet implemented\n";
                break;
            }
            case 4:
            {
                std::cout << "\nMatch 3 not yet implemented\n";
                break;
            }
            case 9:
            {
                playing = false;
                std::cout << "\nQuitting...\n";
                break;
            }
            
            default:
                std::cout << "\nThat wasn't a valid choice\n";
        }
    
        std::cout << "\n============================\n";
    }
    
    
    
    return 0;
}
