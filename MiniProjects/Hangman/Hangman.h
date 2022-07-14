#pragma once
#include <set>
#include <string>
#include <unordered_map>

class Hangman
{
public:
    void PlayGame();

private:
    const int numberOfWords_{58109}; // Think of more performant way to get number of lines at runtime
    const int wordLengthCap_{30};
    const int maxGuesses_{6};
    std::string hiddenWord_;
    int incorrectGuesses_{0};
    std::set<char> guessedChars_;
    std::string GetRandomWord() const;
    void PrintHangman() const;
    void PrintWord() const;
    void PrintGuesses() const;
};

/*
 * Read random line from word.txt file 
 * Set that word as the word to be guessed
 * Print hangman with word blanked out
 * Ask player to guess a letter
 * Check if letter is part of the word
 * If yes then update hangman 
 * Use ordered multimap? e.g apple, they guess P
 * {
 *   {A -> false},
 *   {P -> true},
 *   {P -> true},
 *   {L -> false},
 *   {E -> false},
 * }
 * For each key check if value is true, then print key, else print _
 * 7 guesses -> separate the guessed with a space
 * Guessed: C D H I K Q R S V W
 * Word: _PP__
 *     +-----+
 *     |     0
 *     |    /|\
 *     |     |
 *     |    | \
 *     |
 *  -------   
*/