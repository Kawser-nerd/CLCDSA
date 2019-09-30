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
    private int N;
    private int[] m, d;

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        m = new int[N];
        d = new int[N];
        for (int i = 0; i < N; i++)
        {
            var line = Console.ReadLine().Split('/');
            m[i] = int.Parse(line[0]);
            d[i] = int.Parse(line[1]);
        }
    }

    public void Solve()
    {

        Scan();
        int[] day = new int[12] { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

        bool[] b = new bool[366];
        for (int i = 0; i < 366; i++)
        {
            if (i % 7 == 0 || i % 7 == 6)
            {
                b[i] = true;
            }
        }
        for (int i = 0; i < N; i++)
        {
            int dd = d[i] - 1;
            for (int j = 0; j < m[i]; j++)
            {
                dd += day[j];
            }
            while (dd < 366 && b[dd])
            {

                dd++;
            }
            if (dd < 366)
                b[dd] = true;
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < 366; i++)
        {
            if (b[i])
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            ans = Math.Max(ans, cnt);
        }
        Console.WriteLine(ans);

    }
}