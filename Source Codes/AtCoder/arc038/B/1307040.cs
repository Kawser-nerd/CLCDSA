using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
using System.Linq.Expressions;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int H, W;
    private string[] S;
    private int[,] Array;

    private void Scan()
    {
        var l = Console.ReadLine().Split(' ');
        H = int.Parse(l[0]);
        W = int.Parse(l[1]);
        S = new string[H];
        for (int i = 0; i < H; i++)
        {
            S[i] = Console.ReadLine();
        }
    }

    private bool Ans(int i, int j)
    {
        if (Array[i, j] != -1)
        {
            return Array[i, j] == 1;
        }
        bool res = false;
        if (i < H - 1 && S[i + 1][j] != '#')
        {
            res |= !Ans(i + 1, j);
        }
        if (j < W - 1 && S[i][j + 1] != '#')
        {
            res |= !Ans(i, j + 1);
        }
        if (i < H - 1 && j < W - 1 && S[i + 1][j + 1] != '#')
        {
            res |= !Ans(i + 1, j + 1);
        }
        Array[i, j] = res ? 1 : 0;
        return res;
    }

    public void Solve()
    {
        Scan();
        Array = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                Array[i, j] = -1;
            }
        }
        Console.WriteLine(Ans(0, 0) ? "First" : "Second");
    }
}