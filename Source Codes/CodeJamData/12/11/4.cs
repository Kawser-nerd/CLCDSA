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
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }


    void calc()
    {
        Scanner cin = new Scanner();
        int A = cin.nextInt();
        int B = cin.nextInt();
        double[] p = new double[A];
        for (int i = 0; i < A; i++)
        {
            p[i] = cin.nextDouble();
        }
        double ret = 2 + B;
        double pp = 1;
        for (int i = 0; i <= A; i++)
        {
            double sum = (A - i) + (B - i) + 1;
            sum += (1 - pp) * (B + 1);
            ret = Math.Min(sum, ret);
            if (i != A)
            {
                pp *= p[i];
            }
        }
        Console.WriteLine(string.Format("{0:0.0000000000000000}", ret));

    }

}

