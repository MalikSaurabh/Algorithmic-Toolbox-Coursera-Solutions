#include <iostream>

long long helper(long long m) 
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) 
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) 
{
    long long rem = n % helper(m);

    long long first = 0;
    long long second = 1;

    long long ans = rem;

    for (int i = 1; i < rem; i++) 
    {
        ans = (first + second) % m;
        first = second;
        second = ans;
    }

    return ans % m;
}

int main() 
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}