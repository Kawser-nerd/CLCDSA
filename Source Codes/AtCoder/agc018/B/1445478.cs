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
        int M = cin.nextInt();
        int[,] A = new int[N, M];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                A[i, j] = cin.nextInt() - 1;
            }
        }

        bool[] dead = new bool[M];
        int[] cnt = new int[N];
        int ans = N;
        for (int t = 0; t < M; t++)
        {
            int[] sum = new int[M];
            for (int i = 0; i < N; i++)
            {
                while (dead[A[i, cnt[i]]]) cnt[i]++;
                sum[A[i, cnt[i]]]++;
            }
            int num = -1;
            int best = -1;
            for (int i = 0; i < M; i++)
            {
                if(sum[i] > best)
                {
                    num = i;
                    best = sum[i];
                }
            }
            ans = Math.Min(ans, best);
            dead[num] = true;
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