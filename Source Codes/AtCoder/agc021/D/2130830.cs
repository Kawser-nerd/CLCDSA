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
        string S = cin.next();
        int K = cin.nextInt();
        int N = S.Length;
        int ans = 0;

        
        int[,,] dp = new int[N, N, K + 1];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < K + 1; k++)
                {
                    dp[i, j, k] = -1;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            dp[i, i, 0] = 1;
            ans = 1;
        }

        for (int i = 0; i < N - 1; i++)
        {
            if(S[i] == S[i + 1])
            {
                dp[i, i + 1, 0] = 2;
                ans = 2;
            }
            else
            {
                dp[i, i + 1, 0] = 1;
                if(K >= 1)
                {
                    dp[i, i + 1, 1] = 2;
                    ans = 2;
                }
            }
        }
        
        for (int l = 0; l < N; l++)
        {
            for (int i = 0; i < N - l; i++)
            {
                int j = i + l;
                for (int k = 0; k < K + 1; k++)
                {
                    if (dp[i, j, k] == -1) continue;
                    int c = dp[i, j, k];
                    ans = Math.Max(ans, c);
                    if (i > 0) dp[i - 1, j, k] = Math.Max(dp[i - 1, j, k], c);
                    if (j < N - 1) dp[i, j + 1, k] = Math.Max(dp[i, j + 1, k], c);
                    if (i > 0 && j < N - 1)
                    {
                        if(S[i - 1] == S[j + 1])
                        {
                            dp[i - 1, j + 1, k] = Math.Max(dp[i - 1, j + 1, k], c + 2);
                        }
                        else
                        {
                            //dp[i - 1, j + 1, k] = Math.Max(dp[i - 1, j + 1, k], c);
                            if(k != K)
                            {
                                dp[i - 1, j + 1, k + 1] = Math.Max(dp[i - 1, j + 1, k + 1], c + 2);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < K + 1; k++)
                {
                    ans = Math.Max(ans, dp[i, j, k]);
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