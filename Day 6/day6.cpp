#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.in");

void solve(int numberOfDays)
{

    string input;
    int number = 0;
    long long fishPerState[9] = {0};

    while (fin >> input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != ',')
                number = number * 10 + (input[i] - '0');
            else
            {
                fishPerState[number]++;
                number = 0;
            }
        }

        fishPerState[number]++;

        long long sum = 0;

        for (int i = 0; i < numberOfDays; i++)
            fishPerState[(i + 7) % 9] += fishPerState[i % 9];

        for (int i = 0; i < 9; i++)
            sum += fishPerState[i];

        cout << sum;
    }
}

int main()
{
    solve(256);
    return 0;
}