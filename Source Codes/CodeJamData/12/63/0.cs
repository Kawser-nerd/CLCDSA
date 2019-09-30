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
        cin = new Scanner();
        rnd = new Random();
        int T = cin.nextInt();
        for (int c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    void calc()
    {
        int n = cin.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        bool[] memo = new bool[n];
        for (int i = 0; i < n; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
            memo[i] = (cin.next() == "#");
        }
        long bestdist = long.MaxValue;
        long bestx = 0;
        long besty = 0;
        for (int ty = -201; ty <= 201; ty++)
        {
            for (int tx = -201; tx <= 201; tx++)
            {
                int tempdist = Math.Abs(tx) + Math.Abs(ty);
                if (tempdist > bestdist) continue;
                if (tempdist == bestdist && bestx > tx) continue;
                if (tempdist == bestdist && bestx == tx && besty > ty) continue;
                bool flag = true;
                for (int i = 0; i < n; i++)
                {
                    if (memo[i] == (((Math.Max(Math.Abs(tx - x[i]), Math.Abs(ty - y[i])) % 2)) == 0))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    bestdist = tempdist;
                    bestx = tx;
                    besty = ty;
                }
            }
        }
        if (bestdist == long.MaxValue) Console.WriteLine("Too damaged");
        else Console.WriteLine("{0} {1}", bestx, besty);
    }
}
