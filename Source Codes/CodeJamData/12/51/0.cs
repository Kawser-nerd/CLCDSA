using System;
using System.Collections.Generic;


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Random rnd;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        rnd = new Random();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }
    int[] sec;
    int[] per;

    void calc()
    {
        int n = cin.nextInt();
        sec = new int[n];
        per = new int[n];
        int[] num = new int[n];
        for (int i = 0; i < n; i++)
        {
            sec[i] = cin.nextInt();
        }
        for (int i = 0; i < n; i++)
        {
            per[i] = cin.nextInt();
        }
        for (int i = 0; i < n; i++)
        {
            num[i] = i;
        }
        Array.Sort(num, compare);
        for (int i = 0; i < n; i++)
        {
            Console.Write(num[i] + " ");
        }
        Console.WriteLine();
    }

    int compare(int a, int b)
    {
        if (sec[a] * per[b] != sec[b] * per[a])
        {
            return (sec[a] * per[b]).CompareTo(sec[b] * per[a]);
        }
        else
        {
            return a.CompareTo(b);
        }
    }

}
