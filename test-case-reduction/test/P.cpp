#include <iostream>

int main()
{
    int a ,b;
    std:: cin >> a >> b;

    auto sum = [](int a, int b) {
        return a + b;
    };

    auto square = [](int a) {
        return a * a;
    };

    auto cube = [](int a) {
        return a * a * a;
    };

    if (a%2 == 0 )
    {
        if (b%2==0)
        {
            std::cout << "[message] a & b both even"
                      << "\n";
        }
        else
        {
            std::cout << "[message] a even , b odd"
                      << "\n";
            if (cube(b) > 3*a*b)
                std::cout << "[message] b^3 is > 3ab and = " << cube(b)
                          << "\n";
        }
    }
    else
    {
        if (a%3 == 0)
        {
            std::cout << "[message] a div by 3 and odd"
                      << "\n";
        }
        else
        {
            std::cout << "[message] a not div by 3"
                      << "\n";
            if (sum(a, b) > 0)
                std::cout << "[message] sum(a, b) is " << sum(a, b)
                          << "\n";
        }
    }

    if (a%5 == 0 )
    {
        if (b%5==0)
        {
            std::cout << "[message] a & b both div by 5"
                      << "\n";
        }
        else
        {
            std::cout << "[message] a div by 5 , b not"
                      << "\n";
            if (a%2==0)
                std::cout << "[message] a div by 10 " 
                          << "\n";
        }
    }
    else
    {
        if (b%2 == 0 && b%5 == 0)
        {
            std::cout << "[message] b div by 10"
                      << "\n";
        }
        else
        {
            std::cout << "[message] b not div by 10"
                      << "\n";
            if (sum(a, b) > a - b)
                std::cout << "[message] b is positive"
                          << "\n";
        }
    }

    if (square(a) > square(b))
        std::cout << "[message] square(a) > square(b)"
                  << "\n";

     
     if (a%7 == 0 )
    {
        if (b%7==0)
        {
            std::cout << "[message] a & b both div by 7"
                      << "\n";
        }
        else
        {
            std::cout << "[message] a div by 7 , b not"
                      << "\n";
            if (b%6==0)
                std::cout << "[message] b div by 6" 
                          << "\n";
        }
    }
    else
    {
        if (b%11 == 0 && b%13 == 0)
        {
            std::cout << "[message] b div by 11&13"
                      << "\n";
        }
        else
        {
            std::cout << "[message] b not div by either"
                      << "\n";
            if (sum(a, b) > a - b)
                std::cout << "[message] b is positive"
                          << "\n";
        }
    }

    return 0;
}
