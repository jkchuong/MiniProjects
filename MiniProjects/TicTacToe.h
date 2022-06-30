#pragma once
#include <map>
#include <set>
#include <string>
#include <unordered_map>

class TicTacToe
{
public: 
    void PlayGame();
    void PrintBoard();
    enum Players {PLAYER, CPU};

    // Constructors/Destructors
    TicTacToe();
    ~TicTacToe();

private:
    void RequestMove();
    void RequestOX();
    bool CheckWin(Players player);
    void PlayPiece(const std::string c);
    void PlayPiece(const std::string c, bool isPlayer);

    std::unordered_map<Players, std::set<std::string>> playState_;
    bool playerTurn_ = true;
    bool isCross_ = true;
};

