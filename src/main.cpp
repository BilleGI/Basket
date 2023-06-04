#include <iostream>
#include <map>
#include <cmath>
#include "basket.h"

enum LISTCOMMAND
{
    ADD = 1,
    REMOVE = 2,
    PRINT = 4,
    EXET = 8,
};

LISTCOMMAND numberCommand()
{
    int num;
    std::cout << "Enter the command: ";
    while(true)
    {
        std::cin >> num;
        num = pow(2, num -1);
        if(std::cin.good() && (num == ADD || num == REMOVE || num == PRINT || num == EXET)) break;
        std::cout << "Error. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return static_cast<LISTCOMMAND>(num);
}

void checkInput(int& mean)
{
    std::cout << "Enter the mean argument: ";
    while(!(std::cin >> mean))
    {
        std::cout << "Enter the correct mean: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'n');
    }
}

int main()
{
    Basket basket;
    LISTCOMMAND list;
    std::cout << "The program - online store shopping cart." << std::endl;
    while(true)
    {
        Basket::basketOperation();
        list = numberCommand();
        if(list == LISTCOMMAND::ADD)
        {
            int article;
            int count;
            checkInput(article);
            checkInput(count);
            basket.add(article, count);
        }
        else if(list == LISTCOMMAND::REMOVE)
        {
            int article;
            int count;
            checkInput(article);
            checkInput(count);
            basket.remove(article,count);
        }
        else if(list == LISTCOMMAND::PRINT) basket.print();
        else if(list == LISTCOMMAND::EXET) break;
    }
    return 0;
}
