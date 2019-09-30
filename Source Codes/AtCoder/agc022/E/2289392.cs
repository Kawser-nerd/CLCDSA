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

    long mod = 1000000007;

    void calc()
    {
        cin = new Scanner();
        //string S = new string('?', 99999);//cin.next();
        string S = cin.next();
        int N = S.Length;
        long[,] dp = new long[N + 1, 5]; //0 -> 0start 1-> 0totyu 2->1start 3->1totyu 
        dp[0, 0] = 1;

        if(S.Length == 1)
        {
            if (S == "0") Console.WriteLine(0);
            else Console.WriteLine(1);
            return;
        }

        for (int i = 0; i < S.Length; i++)
        {
            if (S[i] == '?')
            {
                //4
                dp[i + 1, 4] += dp[i, 4] * 2;
                dp[i + 1, 4] %= mod;
            }
            else
            {
                dp[i + 1, 4] += dp[i, 4];
                dp[i + 1, 4] %= mod;
            }
            if (i%2 == 0)
            {
                //0
                int pattern1 = 1;
                if (S[i] == '?') pattern1 *= 2;

                int activePattern1 = pattern1;
                if(S[i] == '1' || S[i] == '?')
                {
                    dp[i + 1, 2] += dp[i, 0];
                    dp[i + 1, 2] %= mod;
                    activePattern1--;
                }
                dp[i + 1, 1] += dp[i, 0] * (activePattern1);
                dp[i + 1, 1] %= mod;

                //3
                if (i != S.Length - 1)
                {
                    int pattern2 = pattern1;
                    if (S[i + 1] == '?')
                    {
                        pattern2 *= 2;
                    }
                    int activePattern2 = pattern2;

                    if ((S[i] == '1' || S[i] == '?') && (S[i + 1] == '1' || S[i + 1] == '?'))
                    {
                        dp[i + 2, 4] += dp[i, 3];
                        dp[i + 2, 4] %= mod;
                        activePattern2--;
                    }
                    dp[i + 2, 3] += dp[i, 3] * activePattern2;
                    dp[i + 2, 3] %= mod;
                }
                else
                {
                    if (S[i] == '1' || S[i] == '?')
                    {
                        dp[i + 1, 4] += dp[i, 3];
                        dp[i + 1, 4] %= mod;
                    }
                }
            }
            else
            {

                int pattern1 = 1;
                if (S[i] == '?') pattern1 *= 2;

                //1

                if (i != S.Length - 2)
                {
                    int pattern2 = pattern1;
                    if (S[i + 1] == '?')
                    {
                        pattern2 *= 2;
                    }
                    int activePattern2 = pattern2;

                    if ((S[i] == '1' || S[i] == '?') && (S[i + 1] == '1' || S[i + 1] == '?'))
                    {
                        dp[i + 2, 2] += dp[i, 1];
                        dp[i + 2, 2] %= mod;
                        activePattern2--;
                    }
                    dp[i + 2, 1] += dp[i, 1] * activePattern2;
                    dp[i + 2, 1] %= mod;
                }
                else
                {
                    if ((S[i] == '1' || S[i] == '?') && (S[i + 1] == '1' || S[i + 1] == '?'))
                    {
                        dp[i + 2, 4] += dp[i, 1];
                        dp[i + 2, 4] %= mod;
                    }
                }


                //2
                int activePattern1 = pattern1;
                if (S[i] == '1' || S[i] == '?')
                {
                    dp[i + 1, 4] += dp[i, 2];
                    dp[i + 1, 4] %= mod;
                    activePattern1--;
                }
                dp[i + 1, 3] += dp[i, 2] * (activePattern1);
                dp[i + 1, 3] %= mod;
            }

        }

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                //Console.Write(dp[i,j] + " ");
            }
            //Console.WriteLine();
        }

        Console.WriteLine(dp[N, 4] % mod);
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