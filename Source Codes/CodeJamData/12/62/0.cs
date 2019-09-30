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
        int K = cin.nextInt();
        List<double> ld = new List<double>();
        for (int i = 0; i < n; i++)
        {
            string[] st = cin.next().Split('/');
            int a = int.Parse(st[0]);
            int b = int.Parse(st[1]);
            double nowd = (double)a / b;
            int num = cin.nextInt();
            for (int j = 0; j < num; j++)
            {
                ld.Add(nowd);
            }
        }
        double[] d = ld.ToArray();
        ld.Clear();
        Array.Sort(d);
        Array.Reverse(d);
        double ret = 1;
        for (int i = 0; i <= K; i++)
        {
            double first = 1;
            double second = 0;
            double fall = 0;
            for (int j = 0; j < i; j++)
            {
                double move;
                move = second * d[j];
                fall += move;
                second -= move;
                move = first * (1 - d[j]);
                second += move;
                first -= move;
            }
            for (int j = d.Length - (K - i); j < d.Length; j++)
            {
                double move;
                move = second * d[j];
                fall += move;
                second -= move;
                move = first * (1 - d[j]);
                second += move;
                first -= move;
            }
            ret = Math.Min(ret, fall);
        }
        Console.WriteLine("{0:0.00000000000000}",ret);
    }
}
