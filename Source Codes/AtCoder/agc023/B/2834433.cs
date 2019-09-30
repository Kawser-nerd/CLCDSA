using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(ReadLine());
        char[,] table = new char[N, N];
        for (int i = 0; i < N; i++)
        {
            var line = ReadLine();
            for (int j = 0; j < N; j++)
            {
                table[i, j] = line[j];
            }
        }
        int count = 0;
        for (int B = 0; B < N; B++)
        {
            if (isGoodTable(table, N, 0, B)) count++;
        }
        WriteLine(count*N);
    }
    static bool isGoodTable(char[,] table, int N, int offsetX, int offsetY)
    {
        char[,] tmp = new char[N, N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                var tmpI = (i + offsetX) % N;
                var tmpJ = (j + offsetY) % N;
                tmp[i, j] = table[tmpI, tmpJ];
                if (j<i)
                {
                    if (tmp[i, j] != tmp[j, i]) return false;
                }
            }
        }
        return true;
    }
}