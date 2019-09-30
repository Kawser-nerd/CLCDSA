using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[,] dist = new int[N, N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i, j] = cin.nextInt();
            }
        }

        long ans = 0;

        for (int i = 0; i < N; i++)
        {
            if (dist[i, i] != 0)
            {
                Console.WriteLine("-1");
                return;
            }
            for (int j = i + 1; j < N; j++)
            {
                if(dist[i,j] != dist[j, i])
                {
                    Console.WriteLine("-1");
                    return;
                }
                int minDist = int.MaxValue;

                for (int k = 0; k < N; k++)
                {
                    if (k == i || k == j) continue;
                    minDist = Math.Min(minDist, dist[i, k] + dist[k, j]);
                }

                if(minDist < dist[i, j])
                {
                    Console.WriteLine("-1");
                    return;
                }
                else if(minDist == dist[i, j])
                {
                    continue;
                }
                else
                {
                    ans += dist[i, j];
                }
            }
        }
        Console.WriteLine(ans);
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}