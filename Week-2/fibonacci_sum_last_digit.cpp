#include <iostream>
using namespace std;
#define max_num (int)1e5

int fibonacci_sum_naive(long long n) 
{
    if (n <= 1)
        return n;

    long long sum[max_num];
    long long previous = 0;
    long long current  = 1;
    sum[0] = 0;
    sum[1] = 1;
    int count = 2;

    for (long long i = 2; i <= n; ++i) 
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum[i] = (sum[i - 1] + current) % 10;
        if (sum[i] == 1 && sum[i - 1] == 0) 
	{
            count--;
            break;
        }
        count++;
    }

    n = n % count;
    return sum[n] % 10;
}
int main() 
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << endl;
}