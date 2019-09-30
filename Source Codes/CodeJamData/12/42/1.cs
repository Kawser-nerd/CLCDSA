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

    void calc()
    {
        int n = cin.nextInt();
        int w = cin.nextInt();
        int h = cin.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; i++)
        {
            num[i] = cin.nextInt() * 1000 + i;
        }
        Array.Sort(num);
        Array.Reverse(num);
        int[] r = new int[n];
        int[] number = new int[n];
        double[] retx = new double[n];
        double[] rety = new double[n];
        for (int i = 0; i < n; i++)
        {
            r[i] = num[i] / 1000;
            number[i] = num[i] % 1000;
        }

        while (true)
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                flag = false;
                for (int kk = 0; kk < 30; kk++)
                {
                    double x = rnd.NextDouble() * w;
                    if (i == 0) x = 0;
                    double miny = 0;
                    double maxy = h;
                    bool check = true;
                    for (int j = 0; j < 30; j++)
                    {
                        double midy = (miny + maxy) / 2;
                        bool f = true;
                        for (int k = 0; k < i; k++)
                        {
                            if (hipot(retx[k] - x, rety[k] - midy) <= r[k] + r[i] + 1e-4)
                            {
                                f = false; break;
                            }
                        }
                        if (f)
                        {
                            check = false;
                            maxy = midy;
                        }
                        else
                        {
                            miny = midy;
                        }
                    }
                    if (check) continue;
                    flag = true;
                    retx[i] = x;
                    rety[i] = maxy;
                }
                if (!flag) break;
            }
            if (flag)
            {
                double[] ry = new double[n];
                double[] rx = new double[n];
                for (int i = 0; i < n; i++)
                {
                    ry[number[i]] = rety[i];
                    rx[number[i]] = retx[i];
                }
                for (int i = 0; i < n; i++)
                {
                    Console.Write("{0:0.0000000} {1:0.0000000} ", rx[i], ry[i]);
                }
                Console.WriteLine();
                return;
            }
            Console.Error.WriteLine("test");
        }
    }

    double hipot(double a, double b)
    {
        return Math.Sqrt(a * a + b * b);
    }



}
