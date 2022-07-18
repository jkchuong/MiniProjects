#pragma once
#include <map>
#include <random>
#include <set>
#include <string>
#include <unordered_map>

/**
 * Class for creating and playing Tic Tac Toe
 */
class TicTacToe
{
public:
    // Default special member functions
    TicTacToe(const TicTacToe& other) = default;
    TicTacToe(TicTacToe&& other) noexcept = default;
    TicTacToe& operator=(const TicTacToe& other) = default;
    TicTacToe& operator=(TicTacToe&& other) noexcept = default;
    
    void PlayGame();
    void Reset();
    enum Players {USER, CPU};

    // Constructors/Destructors
    TicTacToe();
    ~TicTacToe();

private:
    void RequestMove();
    void RequestOx();
    void PrintBoard();
    void DoPlayerTurn(bool& playing);
    void DoCpuTurn(std::mt19937 gen, std::uniform_int_distribution<int> randInt, bool& playing);
    bool PlayPiece(const std::string& position, Players player);
    bool CheckWin(Players player);
    bool CheckTaken(const std::string& position, Players player);
    bool CheckValid(const std::string& position);


    std::unordered_map<Players, std::set<std::string>> playState_;
    bool playerTurn_ = true;
    bool isCross_ = true;

    // probably didn't need a map, could just use set 
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