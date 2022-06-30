#pragma once
#include <map>
#include <set>
#include <string>

class TicTacToe
{
public: 
    void PlayGame();
    void PrintBoard();
    enum Player {NOUGHTS, CROSSES};

    // Constructors/Destructors
    TicTacToe();
    ~TicTacToe();

private:
    void RequestMove();
    void RequestOX();
    bool CheckWin();
    void PlayPiece(const char c1, const int c2);
    void PlayPiece(const char c1, const int c2, bool isPlayer);

    std::map<Player, std::set<std::string>> playState_;
    bool playerTurn_ = true;
    bool isCross_ = true;
};

