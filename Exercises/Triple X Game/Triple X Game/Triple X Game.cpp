#include <ctime>
#include <string>
#include <iostream>

void ClearScreen();
bool PlayGameWithDifficulty(const uint8_t);

template<typename ...Args>
void GetInputData(Args&... args)
{
    (std::cin >> ... >> args);
}

template<typename ...Args>
void Print(const std::string& message, Args&... args)
{
    std::cout << message;
    (std::cout << ... << args);
}

template<typename ...Args>
void PrintLine(const std::string& message, Args&... args)
{
    std::cout << message;
    (std::cout << ... << args) << std::endl;
}

int main()
{
    uint8_t Difficulty = 1;
    uint8_t MaxDifficulty = 10;

    bool success = false;

    srand(time(NULL));

    while (Difficulty < MaxDifficulty)
    {
        success = PlayGameWithDifficulty(Difficulty);

        if (!success) break;

        std::cin.clear();
        std::cin.ignore();

        ClearScreen();

        PrintLine("+ You escaped the room. Now is the next Room! +");

        ++Difficulty;
    }

    if (success) PrintLine("+ WOW! You're free to explore the world! +");
    else PrintLine("+ You missed and now you're locked forever! +");

    return 0;
}

void ClearScreen()
{
    system("CLS");
    std::cout << std::flush;
}

bool PlayGameWithDifficulty(const uint8_t difficulty)
{
    const int CodeA = std::rand() % (2 * difficulty) + difficulty;
    const int CodeB = std::rand() % (2 * difficulty) + difficulty;
    const int CodeC = std::rand() % (2 * difficulty) + difficulty;
    const char VerificationCharacter = (std::rand() % 25) + 97;

    const auto SolutionProduct = CodeA * CodeB * CodeC;
    const auto SolutionSum = CodeA + CodeB + CodeC;

    {
        auto level = static_cast<int>(difficulty);
        PrintLine("+ You're locked inside a room and there's one door protected by a password. You need to escape! This is Level ", level, " +");
    }

    PrintLine("");
    PrintLine("+ You have to type a 3 numbers code follow by the letter ", VerificationCharacter);
    PrintLine("+ The product of those numbers is ", SolutionProduct);
    PrintLine("+ The numbers add-up to ", SolutionSum);

    Print("+ Password (1st 2nd 3rd ", VerificationCharacter, "): ");

    int GuessA = 0;
    int GuessB = 0;
    int GuessC = 0;
    char PlayerCharacter = 'a';

    GetInputData(GuessA, GuessB, GuessC, PlayerCharacter);

    auto Product = GuessA * GuessB * GuessC;
    auto Sum = GuessA + GuessB + GuessC;

    return SolutionProduct == Product && SolutionSum == Sum && VerificationCharacter == PlayerCharacter;
}