using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int whiteN = vals[0];
        int blackN = vals[1];

        int n = 100;

        var field = Enumerable.Range(0, n).Select(_ => new char[n]).ToArray();
        whiteN--;
        blackN--;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                field[i][j] = '#';
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                field[i][j] = '.';
            }
        }

        for (int i = 0; i < n / 2; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                if (whiteN > 0)
                {
                    field[i][j] = '.';
                    whiteN--;
                }
                else
                {
                    goto black;
                }
            }
        }

        black:
        for (int i = 1 + n / 2; i < n; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                if (blackN > 0)
                {
                    field[i][j] = '#';
                    blackN--;
                }
                else
                {
                    goto end;
                }
            }
        }

        end:
        var answer = new StringBuilder();

        for (int i = 0; i < n; i++)
        {
            answer.AppendLine(new string(field[i]));
        }

        Console.WriteLine($"{n} {n}");
        Console.WriteLine(answer);
    }
}