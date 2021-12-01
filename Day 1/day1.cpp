#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.in");

void part1()
{

    int x, prev;
    bool isFirst = true;
    int result = 0;
    while (fin >> x)
    {
        if (!isFirst)
        {
            if (x > prev)
                result++;
        }
        else
            isFirst = false;

        prev = x;
    }

    cout << result;
}

void part2()
{
    int x, result = 0;
    vector<int> partialSums;
    bool isFirst = true;

    while (fin >> x)
    {

        if (isFirst)
        {
            partialSums.push_back(x);
            isFirst = false;
        }
        else
            partialSums.push_back(x + partialSums.back());
    }

    for (int i = 3; i < partialSums.size(); i++)
    {
        if (i > 3 && (partialSums[i] - partialSums[i - 3] > partialSums[i - 1] - partialSums[i - 4]))
            result++;
        else if (i == 3 && (partialSums[i] - partialSums[i - 3] > partialSums[i - 1]))
            result++;
    }

    cout << result;
}

int main()
{
    part2();

    return 0;
}