#include <iostream>


int sum_of_two_digits(int x, int y) 
{
    return x + y;
}

int main() 
{
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b);
    return 0;
}