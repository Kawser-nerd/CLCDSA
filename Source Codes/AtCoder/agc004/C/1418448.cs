using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int H, W;
    private char[][] A;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        H = int.Parse(line[0]);
        W = int.Parse(line[1]);
        A = new char[H][];
        for (int i = 0; i < H; i++)
        {
            A[i] = Console.ReadLine().ToArray();
        }
    }

    private void WriteA()
    {
        var sb = new StringBuilder();
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                bool a = j == 0;
                bool b = (i % 2 == 0) && (j != W - 1);
                bool c = A[i][j] == '#';
                if (a || b || c)
                {
                    sb.Append('#');
                }
                else
                {
                    sb.Append('.');
                }
            }
            sb.AppendLine();
        }
        Console.Write(sb.ToString());
    }

    private void WriteB()
    {
        var sb = new StringBuilder();
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                bool a = j == W - 1;
                bool b = (i % 2 == 1) && (j != 0);
                bool c = A[i][j] == '#';
                if (a || b || c)
                {
                    sb.Append('#');
                }
                else
                {
                    sb.Append('.');
                }
            }
            sb.AppendLine();
        }
        Console.Write(sb.ToString());
    }

    public void Solve()
    {
        Scan();
        WriteA();
        Console.WriteLine();
        WriteB();
    }
}