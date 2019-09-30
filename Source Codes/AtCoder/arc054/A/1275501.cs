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
    private int L, X, Y, S, D;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        L = int.Parse(line[0]);
        X = int.Parse(line[1]);
        Y = int.Parse(line[2]);
        S = int.Parse(line[3]);
        D = int.Parse(line[4]);
    }

    public void Solve()
    {
        Scan();
        int sp = Y + X;
        int dist = D - S;
        if (dist < 0)
        {
            dist += L;
        }
        double time = (double)dist / sp;

        sp = Y - X;
        if (sp <= 0)
        {
            goto A;
        }
        dist = S - D;
        if (dist < 0)
        {
            dist += L;
        }
        time = Math.Min(time, (double)dist / sp);

        A:;
        Console.WriteLine(time);
    }
}