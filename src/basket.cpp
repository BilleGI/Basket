#include "basket.h"
#include <iostream>

const char* Basket::ExistingElement::what() const noexcept
{
    return "Existing element";
}

const char* Basket::CountByZero::what() const noexcept
{
    return "Count by zero";
}

const char* Basket::NoExistingElement::what() const noexcept
{
    return " No existing element";
}

Basket::Basket(){}


void correctQuantity(const int& article,const int& count)
{
    if(article < 0 || count < 0)
    {
        throw std::invalid_argument(article < 0 ? "article" : " count");
    }
}

void value(int& article, int& count)
{
    std::cout << "Enter the correct values" << std::endl;
    std::cout << "Article: ";
    std::cin >> article;
    std::cout << "Count: ";
    std::cin >> count;
}

void Basket::add(int& article, int& count)
{
    while(true)
    {
        try
        {
            if(products.find(article) != products.end()) throw ExistingElement();
            else if (count == 0) throw CountByZero();
            correctQuantity(article, count);
            products[article] = count;
            break;
        }
        catch(const ExistingElement& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
        }
        catch(const CountByZero& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
            break;
        }
        catch(const std::invalid_argument& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "Some kind of exception has happend..." << std::endl;
        }
        value(article, count);
    }
}

void Basket::remove(int& article, int& count)
{
    while(true)
    {
        try
        {
            if(products.find(article) == products.end()) throw NoExistingElement();
            else if(products[article] < count ) throw std::invalid_argument("count");
            else if(count == 0) throw CountByZero();
            correctQuantity(article, count);
            if(count == products[article]) products.erase(article);
            else products[article] -= count;
            break;
        }
        catch (const NoExistingElement& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
        }
        catch(const std::invalid_argument& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
        }
        catch(const CountByZero& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
            break;
        }
        catch(...)
        {
            std::cerr << "Some kind of exception has happend..." << std::endl;
        }
        value(article, count);
    }
}

void Basket::print()
{
    for(const auto&[article, count] : products)
    {
        for(int i = 0 ; i < 40; ++i)
            std::cout << "-";
        std::cout << "\nArticle - " << article << " , count - " << count << std::endl;
    }
}

void Basket::basketOperation()
{
    std::cout << "\nList opeartion: " << std::endl;
    std::cout << "1 - Add an item to the cart." << std::endl;
    std::cout << "2 - Remove an item from the shopping cart." << std::endl;
    std::cout << "3 - Print the shopping cart." << std::endl;
    std::cout << "4 - Exet." << std::endl;
}
