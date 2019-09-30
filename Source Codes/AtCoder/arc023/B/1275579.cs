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
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

struct P
{
    public int X, Y;
    public P(int x, int y)
    {
        X = x;
        Y = y;
    }
}

public class Magatro
{
    int R, C, D;
    int[][] A;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        R = int.Parse(line[0]);
        C = int.Parse(line[1]);
        D = int.Parse(line[2]);
        A = new int[R][];
        for(int i = 0; i < R; i++)
        {
            A[i] = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }
    }

    public void Solve()
    {

        Scan();
        int ans = -1;
        for(int j = 0; j < C; j++)
        {
            for(int i = 0; i < R; i++)
            {
                if (i + j <= D)
                {
                    if ((D - i - j) % 2 == 0)
                    {
                        ans = Math.Max(ans, A[i][j]);
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }
}