#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("input.in");

void processInput(string input, vector<int> &crabPositions)
{
    while (getline(fin, input))
    {
        int number = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == ',')
            {
                crabPositions.push_back(number);
                number = 0;
            }
            else
                number = number * 10 + (input[i] - '0');
        }

        crabPositions.push_back(number);
    }
}

int gaussSum(int n)
{
    return n * (n + 1) / 2;
}

void part1()
{

    string input;
    vector<int> crabPositions;
    processInput(input, crabPositions);

    sort(crabPositions.begin(), crabPositions.end());
    int middleCrab = crabPositions[crabPositions.size() / 2];

    int totalFuel = 0;
    for (int i = 0; i < crabPositions.size(); i++)
        totalFuel += abs(crabPositions[i] - middleCrab);

    cout << totalFuel;
}

void part2()
{
    string input;
    vector<int> crabPositions;
    processInput(input, crabPositions);

    float crabPositionSum = 0.0;
    for (int i = 0; i < crabPositions.size(); i++)
        crabPositionSum += crabPositions[i];

    int averageCrabPosition = (int)(crabPositionSum / crabPositions.size());

    int totalFuel = 0;
    for (int i = 0; i < crabPositions.size(); i++)
        totalFuel += gaussSum(abs(crabPositions[i] - averageCrabPosition));

    cout << totalFuel;
}

int main()
{
    part2();
    return 0;
}