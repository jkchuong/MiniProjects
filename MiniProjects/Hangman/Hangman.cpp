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

    while (guessedInt_ < maxGuesses_)
    {
        char guess{};
        std::cout << "Guess a letter: ";
        std::cin >> guess;
        
        if (!isalpha(guess))
        {
            std::cout << "Not in the alphabet, try again.\n";
            continue;
        }

        guess = static_cast<char>(toupper(guess));
        
    }
    
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
    line.reserve(wordLengthCap_);

    for (int i{0}; i < randomLine; i++)
    {
        std::getline(wordFile, line);
    }

    std::transform(line.begin(), line.end(), line.begin(), toupper);
    
    return line;
}

void Hangman::PrintHangman()
{
    std::cout << "\t+--------+\n";

    static const std::string blankLine = "\t|\n";
    
    static std::vector<std::string> hangedman
    {
        "\t|        0\n",
        "\t|       /|\\n",
        "\t|        |\n",
        "\t|       / \\n"
    };

    switch (guessedInt_)
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
