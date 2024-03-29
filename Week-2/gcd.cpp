#include <iostream>

int gcd_naive(int a, int b) 
{
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) 
    {
        if (a % d == 0 && b % d == 0) 
	{
            if (d > current_gcd) 
	    {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast_calc(int a, int b) 
{
    return a % b == 0 ? b : gcd_fast_calc(b % a, a);
}

int main() 
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_fast_calc(a, b) << std::endl;
    return 0;
}