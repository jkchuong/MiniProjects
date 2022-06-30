#include <iomanip>
#include <iostream>

#include "TicTacToe.h"

int main(int argc, char* argv[])
{
    std::cout
    << std::setw(2) << std::right << "3"
    << std::setw(4) << std::right << " [ ]"
    << std::setw(4) << std::right << " [ ]"
    << std::setw(4) << std::right << " [ ]"
    << std::endl;

    
    TicTacToe ticTacToe{};

    ticTacToe.PlayGame();
    
    return 0;
}
