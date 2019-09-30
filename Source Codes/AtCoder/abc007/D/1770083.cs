using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;


class Iroha
{
    public Iroha() { }
    public static int Main()
    {
        new Iroha().calc();
        return 0;
    }

    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        long A = cin.nextLong();
        long B = cin.nextLong();
        Console.WriteLine(calc2(B) - calc2(A-1));
    }
    
    long calc2(long N)
    {
        string S = N.ToString();
        long[,] dp = new long[2, 2];
        dp[0, 1] = 1;
        for (int i = 0; i < S.Length; i++)
        {
            long[,] nextdp = new long[2, 2];
            int target = S[i] - '0';
            for (int k = 0; k < 2; k++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (dp[j, k] == 0) continue;

                    for (int l = 0; l < 10; l++)
                    {
                        if (k == 1 && l > target) continue;
                        int nextj = j;
                        int nextk = k;
                        if (l != target) nextk = 0;
                        if (l == 4 || l == 9) nextj = 1;
                        nextdp[nextj, nextk] += dp[j, k];
                    }
                }
            }
            dp = nextdp;
        }
        long ans = dp[1, 0] + dp[1, 1];
        return ans;
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