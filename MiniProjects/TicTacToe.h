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
    enum Players {USER, CPU};

    // Constructors/Destructors
    TicTacToe();
    ~TicTacToe();

private:
    void RequestMove();
    void RequestOX();
    bool PlayPiece(const std::string& position, Players player);
    bool CheckWin(Players player);
    bool CheckTaken(const std::string& position, Players player);
    bool CheckValid(const std::string& position);

    std::unordered_map<Players, std::set<std::string>> playState_;
    bool playerTurn_ = true;
    bool isCross_ = true;


    std::map<unsigned int, std::string> table_
    {
        {1, "a3"},
        {2, "b3"},
        {3, "c3"},
        
        {4, "a2"},
        {5, "b2"},
        {6, "c2"},
        
        {7, "a1"},
        {8, "b1"},
        {9, "c1"}
    };
};