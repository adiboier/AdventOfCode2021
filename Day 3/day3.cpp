#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

ifstream fin("input.in");

int convertFromBinaryToInt(string binary)
{
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

void part1()
{
    string input;
    map<int, int[2]> frequenciesPerPosition;

    while (fin >> input)
    {

        for (int i = 0; i < input.length(); i++)
            if (frequenciesPerPosition.find(i) == frequenciesPerPosition.end())
            {
                if (input[i] == '0')
                    frequenciesPerPosition[i][0]++;
                else
                    frequenciesPerPosition[i][1]++;
            }
            else
            {
                if (input[i] == '0')
                    frequenciesPerPosition[i][0]++;
                else
                    frequenciesPerPosition[i][1]++;
            }
    }

    string gammaRateBinary = "";
    string epsilonRateBinary = "";

    for (auto it = frequenciesPerPosition.begin(); it != frequenciesPerPosition.end(); ++it)
        if (it->second[0] > it->second[1])
        {
            gammaRateBinary += "0";
            epsilonRateBinary += "1";
        }
        else
        {
            gammaRateBinary += "1";
            epsilonRateBinary += "0";
        }

    int gammaRate = convertFromBinaryToInt(gammaRateBinary);
    int epsilonRate = convertFromBinaryToInt(epsilonRateBinary);

    cout << gammaRate * epsilonRate;
}

int computeOxigenGeneratorOrScrubberRating(vector<pair<string, bool>> inputArray, int remainCount, int currentBitIndex, int mode)
{
    while (remainCount > 1)
    {
        pair<int, int> frequenciesPerPosition;
        for (int i = 0; i < inputArray.size(); i++)
            if (inputArray[i].second)
            {
                if (inputArray[i].first[currentBitIndex] == '0')
                    frequenciesPerPosition.first++;
                else
                    frequenciesPerPosition.second++;
            }

        char bitToKeep;
        if (mode == 0)
            bitToKeep = (frequenciesPerPosition.first > frequenciesPerPosition.second) ? '0' : '1';
        else
            bitToKeep = (frequenciesPerPosition.first <= frequenciesPerPosition.second) ? '0' : '1';

        int howManyRemain = 0;

        for (int i = 0; i < inputArray.size(); i++)
            if (inputArray[i].second)
            {
                if (inputArray[i].first[currentBitIndex] != bitToKeep)
                    inputArray[i].second = false;
                else
                    howManyRemain++;
            }

        remainCount = howManyRemain;
        currentBitIndex++;
    }

    for (int i = 0; i < inputArray.size(); i++)
        if (inputArray[i].second)
            return convertFromBinaryToInt(inputArray[i].first);

    return 0;
}

void part2()
{

    string input;
    vector<pair<string, bool>> inputArray;

    while (fin >> input)
    {
        pair<string, bool> newPair;
        newPair.first = input;
        newPair.second = true;
        inputArray.push_back(newPair);
    }

    int oxigenGeneratorRating = computeOxigenGeneratorOrScrubberRating(inputArray, inputArray.size(), 0, 0);
    int scrubberRating = computeOxigenGeneratorOrScrubberRating(inputArray, inputArray.size(), 0, 1);
    cout << oxigenGeneratorRating * scrubberRating;
}

int main()
{
    //part1();
    part2();
    return 0;
}