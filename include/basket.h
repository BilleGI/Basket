#pragma once
#include <map>
#include <exception>

class Basket
{
public:
    Basket();
    void add(int& article, int& count);
    void remove(int& article, int& count);
    void print();
    static void basketOperation();
    static void list();
private:
    Basket(const Basket&);
    std::map<int, int> products;

    class ExistingElement: public std::exception
    {
    public:
        const char* what() const noexcept override;
    };

    class CountByZero: public std::exception
    {
    public:
        const char* what() const noexcept override;
    };

    class NoExistingElement: public std::exception
    {
    public:
        const char* what() const noexcept override;
    };
};
