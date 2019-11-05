#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const vector<int> &numbers) 
{
    int n = numbers.size();

    int first = -1;
    for (int i = 0; i < n; ++i)
        if ((first == -1) || (numbers[i] > numbers[first]))
            first = i;

    int second = -1;
    for (int j = 0; j < n; ++j)
        if ((j != first) && ((second == -1) || (numbers[j] > numbers[second])))
            second = j;


    return ((long long) (numbers[first])) * numbers[second];
}

int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << endl;
    return 0;
}