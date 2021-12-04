#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.in");

void readInput(vector<int> &moves, vector<vector<vector<int>>> &matrices)
{

    string input;
    bool firstLine = true;

    while (getline(fin, input))
    {
        if (firstLine)
        {
            firstLine = false;

            int number = 0;
            for (int i = 0; i < input.size(); i++)
                if (input[i] != ',')
                    number = number * 10 + (input[i] - '0');
                else
                {
                    moves.push_back(number);
                    number = 0;
                }
        }
        else
        {
            if (input != "")
            {
                int number = 0;
                matrices[matrices.size() - 1].push_back(vector<int>());
                for (int i = 0; i < input.size(); i++)
                    if (input[i] != ' ')
                        number = number * 10 + (input[i] - '0');
                    else if ((i != 0 && input[i] == ' ' && input[i - 1] != ' ') || (i == 0 && input[i] != ' '))
                    {
                        matrices[matrices.size() - 1][matrices[matrices.size() - 1].size() - 1].push_back(number);
                        number = 0;
                    }

                matrices[matrices.size() - 1][matrices[matrices.size() - 1].size() - 1].push_back(number);
            }
            else
                matrices.push_back(vector<vector<int>>());
        }
    }
}

void part1(vector<int> moves, vector<vector<vector<int>>> matrices)
{

    readInput(moves, matrices);

    bool foundWinner = false;
    int moveIndex = 0;
    int winningMatrixIndex = 0;

    while (!foundWinner)
    {

        int calledNum = moves[moveIndex];

        for (int i = 0; i < matrices.size(); i++)
            for (int j = 0; j < matrices[i].size(); j++)
                for (int k = 0; k < matrices[i][j].size(); k++)
                    if (matrices[i][j][k] == calledNum)
                    {
                        matrices[i][j][k] = -1;
                        if (matrices[i][0][k] + matrices[i][1][k] + matrices[i][2][k] + matrices[i][3][k] + matrices[i][4][k] == -5)
                        {
                            foundWinner = true;
                            winningMatrixIndex = i;
                        }
                        else if (matrices[i][j][0] + matrices[i][j][1] + matrices[i][j][2] + matrices[i][j][3] + matrices[i][j][4] == -5)
                        {
                            foundWinner = true;
                            winningMatrixIndex = i;
                        }
                    }
        moveIndex++;
        int winningUnmarkedSum = 0;

        if (foundWinner)
        {
            for (int i = 0; i < matrices[winningMatrixIndex].size(); i++)
                for (int j = 0; j < matrices[winningMatrixIndex][i].size(); j++)
                    if (matrices[winningMatrixIndex][i][j] != -1)
                        winningUnmarkedSum += matrices[winningMatrixIndex][i][j];

            cout << winningUnmarkedSum * calledNum;
        }
    }
}

void part2(vector<int> moves, vector<vector<vector<int>>> matrices)
{

    int moveIndex = 0;
    bool hasMatrixWon[matrices.size()] = {false};
    int winnerCount = 0;
    int lastWinnerIndex = -1;

    while (winnerCount != matrices.size())
    {
        int calledNum = moves[moveIndex];

        for (int i = 0; i < matrices.size(); i++)
            if (!hasMatrixWon[i])
                for (int j = 0; j < matrices[i].size(); j++)
                    for (int k = 0; k < matrices[i][j].size(); k++)
                        if (matrices[i][j][k] == calledNum)
                        {
                            matrices[i][j][k] = -1;
                            if (matrices[i][j][0] + matrices[i][j][1] + matrices[i][j][2] + matrices[i][j][3] + matrices[i][j][4] == -5)
                            {
                                hasMatrixWon[i] = true;
                                winnerCount++;
                            }
                            else if (matrices[i][0][k] + matrices[i][1][k] + matrices[i][2][k] + matrices[i][3][k] + matrices[i][4][k] == -5)
                            {
                                hasMatrixWon[i] = true;
                                winnerCount++;
                            }

                            if (hasMatrixWon[i])
                                lastWinnerIndex = i;
                        }

        if (winnerCount == matrices.size())
        {
            int unmarkedSum = 0;
            for (int t = 0; t < matrices[lastWinnerIndex].size(); t++)
                for (int u = 0; u < matrices[lastWinnerIndex][t].size(); u++)
                    if (matrices[lastWinnerIndex][t][u] != -1)
                        unmarkedSum += matrices[lastWinnerIndex][t][u];

            cout << unmarkedSum * calledNum;
        }
        moveIndex++;
    }
}

int main()
{
    vector<int> moves;
    vector<vector<vector<int>>> matrices;

    readInput(moves, matrices);

    //part1(moves, matrices);
    part2(moves, matrices);
    return 0;
}