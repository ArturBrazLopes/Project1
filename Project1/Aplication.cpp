#include <iostream>
#include "Functions.hpp"

int main()
{
    std::cout << "Please select player\n" << "Player1 = x\n" << "Player2 = o\n";
    std::cout << "Player1 play first";
    resetGrid();
    gamePlay();

    return 0;
}