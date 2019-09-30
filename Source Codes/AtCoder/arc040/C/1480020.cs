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

    int N;
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        bool[,] ok = new bool[N, N];
        for (int i = 0; i < N; i++)
        {
            string S = cin.next();
            for (int j = 0; j < N; j++)
            {
                if (S[j] == 'o') ok[i, j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (!ok[i, j])
                {
                    ans++;
                    for (int k = 0; k <= j; k++)
                    {
                        ok[i, k] = true;
                    }
                    if (i != N - 1)
                    {
                        for (int k = j; k < N; k++)
                        {
                            ok[i + 1, k] = true;
                        }
                    }
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