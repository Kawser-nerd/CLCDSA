using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    public void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int K = cin.nextInt();

        long[] s = new long[N];

        for (int i = 0; i < N; i++)
        {
            s[i] = cin.nextLong();
        }

        if (s.Any(x => x == 0))
        {
            Console.WriteLine(N);
            Console.Read();
            return;
        }

        if (K == 0)
        {
            Console.WriteLine(0);
            Console.Read();
            return;
        }

        int l = 0;
        int r = 0;
        int res = 0;
        long prod = 1;

        while (r < N)
        {
            prod *= s[r++];
            while (l < r && prod > K)
            {

                prod /= s[l++];
            }
            res = Math.Max(res, r - l);
        }

        Console.WriteLine(res);
        Console.Read();
    }
}


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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }
}