#include <iostream>

int getFibonacciLastDigit(long n) 
{
    if (n <= 1)
        return n;

    int prev = 0;
    int curr = 1;
    for (long i = 2; i <= n; i++) 
    {
        int next = (prev + curr) % 10;
        prev = curr;
        curr = next;
    }
    return curr % 10;
}

int fibonacci_sum_squares_naive(long long n) 
{
    int verticalSide = getFibonacciLastDigit(n % 60);
    int horizontalSide = getFibonacciLastDigit((n + 1) % 60);
    int sumSquares = verticalSide * horizontalSide;
    return sumSquares % 10;
}


int main() 
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
