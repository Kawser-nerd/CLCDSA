using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_025
    {
        static int[,] bs, cs;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input;
            bs = new int[2, 3];
            input = Console.ReadLine().Split(' ');
            bs[0, 0] = int.Parse(input[0]);
            bs[0, 1] = int.Parse(input[1]);
            bs[0, 2] = int.Parse(input[2]);
            input = Console.ReadLine().Split(' ');
            bs[1, 0] = int.Parse(input[0]);
            bs[1, 1] = int.Parse(input[1]);
            bs[1, 2] = int.Parse(input[2]);

            cs = new int[3, 2];
            input = Console.ReadLine().Split(' ');
            cs[0, 0] = int.Parse(input[0]);
            cs[0, 1] = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            cs[1, 0] = int.Parse(input[0]);
            cs[1, 1] = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            cs[2, 0] = int.Parse(input[0]);
            cs[2, 1] = int.Parse(input[1]);

            var gridInfo = new GridState[3, 3];
            for (int i = 0; i < 9; i++)
            {
                gridInfo[i / 3, i % 3] = GridState.undefined;
            }
            int[] score = DFS(1, gridInfo);
            Console.WriteLine(score[0]);
            Console.WriteLine(score[1]);
        }

        //?????
        static int[] DFS(int turnCnt, GridState[,] gridInfo)
        {
            var bestScore = new int[2] { 10000, 0 };
            bool isChokudai = turnCnt % 2 == 1;
            for (int i = 0; i < 9; i++)
            {
                int x = i % 3;
                int y = i / 3;
                if (gridInfo[y, x] != GridState.undefined) continue;

                gridInfo[y, x] = isChokudai
                    ? GridState.chokudai : GridState.naoko;

                int[] score = DFS(turnCnt + 1, gridInfo);
                int scoreMargin = score[0] - score[1];
                int bestMargin = bestScore[0] - bestScore[1];

                if (bestScore[0] == 10000
                    || (isChokudai && scoreMargin > bestMargin)
                    || (!isChokudai && scoreMargin < bestMargin))
                {
                    bestScore = score;
                }

                gridInfo[y, x] = GridState.undefined;
            }
            if (bestScore[0] == 10000)//?????????
            {
                return GetScore(gridInfo);
            }
            else
            {
                return bestScore;
            }
        }

        static int[] GetScore(GridState[,] gridInfo)
        {
            int chokudai = 0, naoko = 0;
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (gridInfo[j,k]!=GridState.undefined
                        &&gridInfo[j, k] == gridInfo[j + 1, k])
                    {
                        chokudai += bs[j, k];
                    }
                    else
                    {
                        naoko += bs[j, k];
                    }
                }
            }
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (gridInfo[j, k] != GridState.undefined
                        && gridInfo[j, k] == gridInfo[j, k + 1])
                    {
                        chokudai += cs[j, k];
                    }
                    else
                    {
                        naoko += cs[j, k];
                    }
                }
            }
            return new int[2] { chokudai, naoko };
        }
    }

    enum GridState
    {
        undefined = 0, chokudai = 1, naoko = 2
    }
}