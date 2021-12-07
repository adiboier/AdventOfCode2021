#include <iostream>
#include <fstream>
#include <map>
using namespace std;

ifstream fin("input.in");

void processInput(int &x1, int &x2, int &y1, int &y2, string input)
{
    int numberIndex = 1;
    int currentNumber = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            if (numberIndex == 1)
            {
                x1 = currentNumber;
                currentNumber = 0;
                numberIndex++;
            }
            else
            {
                x2 = currentNumber;
                currentNumber = 0;
                numberIndex++;
            }
        }
        else if (input[i] == ' ')
        {
            if (numberIndex == 2)
            {
                y1 = currentNumber;
                currentNumber = 0;
                numberIndex++;
            }
        }
        else if (input[i] >= '0' && input[i] <= '9')
            currentNumber = currentNumber * 10 + (input[i] - '0');
    }

    y2 = currentNumber;
}

void part1()
{
    string input;

    map<pair<int, int>, int> pointMap;

    while (getline(fin, input))
    {

        int x1, x2, y1, y2;
        processInput(x1, x2, y1, y2, input);
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        if (x1 == x2)
        {
            for (int y = y1; y <= y2; y++)
                pointMap[make_pair(x1, y)]++;
        }
        else if (y1 == y2)
        {
            for (int x = x1; x <= x2; x++)
                pointMap[make_pair(x, y1)]++;
        }
    }

    int intersections = 0;

    for (auto it = pointMap.begin(); it != pointMap.end(); it++)
        if (it->second > 1)
            intersections++;

    cout << intersections;
}

void part2()
{
    string input;

    map<pair<int, int>, int> pointMap;

    while (getline(fin, input))
    {
        int x1, x2, y1, y2;
        processInput(x1, x2, y1, y2, input);

        if (x1 == x2)
        {
            if (y1 > y2)
                swap(y1, y2);
            for (int y = y1; y <= y2; y++)
                pointMap[make_pair(x1, y)]++;
        }
        else if (y1 == y2)
        {
            if (x1 > x2)
                swap(x1, x2);
            for (int x = x1; x <= x2; x++)
                pointMap[make_pair(x, y1)]++;
        }
        else if (x1 < x2 && y1 < y2)
        {
            for (int x = x1, y = y1; x <= x2 && y <= y2; x++, y++)
                pointMap[make_pair(x, y)]++;
        }
        else if (x1 < x2 && y1 > y2)
        {
            for (int x = x1, y = y1; x <= x2 && y >= y2; x++, y--)
                pointMap[make_pair(x, y)]++;
        }
        else if (x1 > x2 && y1 < y2)
        {
            for (int x = x1, y = y1; x >= x2 && y <= y2; x--, y++)
                pointMap[make_pair(x, y)]++;
        }
        else if (x1 > x2 && y1 > y2)
        {
            for (int x = x1, y = y1; x >= x2 && y >= y2; x--, y--)
                pointMap[make_pair(x, y)]++;
        }
    }

    int intersections = 0;

    for (auto it = pointMap.begin(); it != pointMap.end(); it++)
        if (it->second > 1)
            intersections++;

    cout << intersections;
}

int main()
{
    part2();
    return 0;
}