using System;
using static System.Console;

class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        var S = new int[N, N * 2];
        for (int i = 0; i < N; i++)
        {
            var line = ReadLine();
            for (int j = 0; j < N; j++)
            {
                S[i, j] = line[j];
                S[i, N + j] = line[j];
            }
        }

        var c = 0;
        for (int b = 0; b < N; b++)
        {
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (S[i, b + j] != S[j, b + i]) goto a;
            c++;
        a:;
        }

        WriteLine(c * N);
    }
}