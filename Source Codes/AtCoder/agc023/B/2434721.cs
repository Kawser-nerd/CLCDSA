using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using System.Numerics;
class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        var S = new int[N * 2, N * 2];
        for (int i = 0; i < N; i++)
        {
            var line = ReadLine();
            for (int j = 0; j < N; j++)
            {
                S[i, j] = line[j];
                S[N + i, j] = line[j];
                S[i, N + j] = line[j];
                S[N + i, N + j] = line[j];
            }
        }

        var ans = 0;
        for (int b = 0; b < N; b++)
        {
            if (IsGood(N, S, 0, b)) ans += N;
        }


        WriteLine(ans);
    }

    static bool IsGood(int N, int[,] B, int h, int w)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (B[h + i, w + j] != B[h + j, w + i]) return false;
            }
        }
        return true;
    }
}