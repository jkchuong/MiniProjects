#include "Hangman.h"

#include <fstream>
#include <iostream>
#include <random>

void Hangman::PlayGame()
{
    // Instructions
    std::cout << "Welcome to Hangman!\n";
    std::cout << "Rules are simple\n";
    std::cout << "Just enter a letter you think is part of the word\n";
    std::cout << "If you're right, the letter will show up\n";
    std::cout << "If you're wrong, be careful, once the man is complete, you will lose!\n";
    std::cout << "Now starting game...\n\n";

    hiddenWord_ = GetRandomWord();
    bool wordComplete = false;
    
    while (incorrectGuesses_ < maxGuesses_ && !wordComplete)
    {
        char guess{};
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // Don't allow user to input invalid characters
        if (!isalpha(guess))
        {
            std::cout << "Not in the alphabet, try again.\n";
            continue;
        }

        guess = static_cast<char>(toupper(guess));

        // Don't allow user to input letters they've already guessed
        if (guessedChars_.find(guess) != guessedChars_.end())
        {
            std::cout << "You've already guessed that letter, try again.\n";
            continue;
        }
        
        guessedChars_.emplace(guess);

        // Increment incorrect guesses if incorrect guess
        if (hiddenWord_.find(guess) == std::string::npos)
        {
            incorrectGuesses_++;
        }

        // Check if win
        wordComplete = std::all_of(hiddenWord_.begin(), hiddenWord_.end(),
                                          [this](const char c)
                                          {
                                              return guessedChars_.find(c) != guessedChars_.end();
                                          });

        PrintGuesses();
        PrintWord();
        PrintHangman();
    }

    // Exiting while loops means that the user has maxed out their allowed guesses and loses
    if (wordComplete)
    {
        std::cout << "You win! ";
    }
    else
    {
        std::cout << "You lose! ";
    }

    std::cout << "The hidden word was: " << hiddenWord_ << '\n';
}

void Hangman::Reset()
{
    guessedChars_.clear();
    hiddenWord_.clear();
    incorrectGuesses_ = 0;
}

std::string Hangman::GetRandomWord() const
{
    // Get random word from text document to be the hidden word
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> randInt(1, numberOfWords_);

    std::ifstream wordFile{"Hangman/words.txt"};
    const int randomLine{randInt(gen)};
    std::string line{};
    line.reserve(wordLengthCap_); // For performance

    for (int i{0}; i < randomLine; i++)
    {
        std::getline(wordFile, line);
    }

    std::transform(line.begin(), line.end(), line.begin(), toupper);
    
    return line;
}

void Hangman::PrintGuesses() const
{
    std::cout << "Guessed: ";

    for (const char c : guessedChars_)
    {
        std::cout << c << " ";
    }

    std::cout << '\n';
}

void Hangman::PrintWord() const
{
    std::cout << "Word: ";

    for (const char c : hiddenWord_)
    {
        if (guessedChars_.find(c) == guessedChars_.end())
        {
            std::cout << "_";
        }
        else
        {
            std::cout << c;
        }
    }
        
    std::cout << '\n';
}

void Hangman::PrintHangman() const
{
    std::cout << "\t+--------+\n";

    static const std::string blankLine = "\t|\n";

    // Could use fallthrough somehow?
    switch (incorrectGuesses_)
    {
        case 1:
        {
            std::cout << "\t|        0\n";
            std::cout << blankLine << blankLine << blankLine;
            break;
        }
        case 2:
        {
            std::cout << "\t|        0\n";
            std::cout << "\t|        |\n";
            std::cout << "\t|        |\n";
            std::cout << blankLine << blankLine;
            break;
        }
        case 3:
        {
            std::cout << "\t|        0\n";
            std::cout << "\t|       /|\n";
            std::cout << "\t|        |\n";
            std::cout << blankLine;
            break;
        }
        case 4:
        {
            std::cout << "\t|        0\n";
            std::cout << "\t|       /|\\ \n";
            std::cout << "\t|        |\n";
            std::cout << blankLine;
            break;
        }
        case 5:
        {
            std::cout << "\t|        0\n";
            std::cout << "\t|       /|\\ \n";
            std::cout << "\t|        |\n";
            std::cout << "\t|       / \n";
            break;
        }
        case 6:
        {
            std::cout << "\t|        0\n";
            std::cout << "\t|       /|\\ \n";
            std::cout << "\t|        |\n";
            std::cout << "\t|       / \\ \n";
            break;
        }
        
        default:
            std::cout << blankLine << blankLine << blankLine << blankLine;
            break;
    }

    std::cout << blankLine << "---------\n";
}
