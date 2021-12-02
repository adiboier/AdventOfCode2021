#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.in");

int reverseNumber(int n)
{
    int rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

void part1()
{
    int depth = 0, horizontal = 0;

    string input = "";
    while (getline(fin, input))
    {

        int number = 0;
        for (int i = input.length() - 1; i >= 0; i--)
            if (input[i] != ' ')
                number = number * 10 + (input[i] - '0');
            else
                break;

        number = reverseNumber(number);
        if (input[0] == 'f')
            horizontal += number;
        else if (input[0] == 'd')
            depth += number;
        else
            depth -= number;
    }

    cout << depth * horizontal;
}

void part2()
{

    long long depth = 0, horizontal = 0, aim = 0;

    string input = "";
    while (getline(fin, input))
    {

        int number = 0;
        for (int i = input.length() - 1; i >= 0; i--)
            if (input[i] != ' ')
                number = number * 10 + (input[i] - '0');
            else
                break;

        number = reverseNumber(number);
        if (input[0] == 'f')
        {
            horizontal += number;
            depth += aim * number;
        }
        else if (input[0] == 'd')
            aim += number;
        else
            aim -= number;
    }

    cout << depth * horizontal;
}

int main()
{
    part2();
    return 0;
}