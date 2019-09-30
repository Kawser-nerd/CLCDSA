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

    long mod = 1000000007;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();
        int[] l = new int[M];
        int[] r = new int[M];
        int[] num = new int[M];
        
        for (int i = 0; i < M; i++)
        {
            l[i] = cin.nextInt() - 1;
            r[i] = cin.nextInt() - 1;
            num[i] = cin.nextInt();
        }
        List<int>[] last = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            last[i] = new List<int>();
        }

        for (int i = 0; i < M; i++)
        {
            last[r[i]].Add(i);
        }

        long[,,] dp = new long[3, N, N];
        dp[0, 0, 0] = 1;

        int[] maxBack = new int[N];
        for (int i = 0; i < N; i++)
        {
            maxBack[i] = i - 1;
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                maxBack[j] = Math.Min(maxBack[j], l[i] - 1);
            }
        }

        for (int t = 0; t < N; t++)
        {
            long[,,] nextdp = new long[3, N, N];

            for (int a = 0; a < 3; a++)
            {
                for (int i = 0; i <= t; i++)
                {
                    for (int j = 0; j <= t; j++)
                    {
                        if (dp[a, i, j] == 0) continue;
                        int R, G, B;
                        if (a == 0) { R = t - 1; G = i - 1; B = j - 1; }
                        else if (a == 1) { G = t - 1; B = i - 1; R = j - 1; }
                        else { B = t - 1; R = i - 1; G = j - 1; }

                        //Console.WriteLine(t + " " + R + " " + G + " " + B + " " + dp[a, i, j] + " " + a + " " + i + " " + j);

                        for (int k = 0; k < 3; k++)
                        {
                            int NR = R, NG = G, NB = B;
                            if (k == 0) NR = t;
                            if (k == 1) NG = t;
                            if (k == 2) NB = t;

                            bool flag = true;
                            foreach (var id in last[t])
                            {
                                int cnt = 0;
                                if (NR >= l[id]) cnt++;
                                if (NG >= l[id]) cnt++;
                                if (NB >= l[id]) cnt++;
                                if(num[id] != cnt)
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (!flag) continue;

                            NR = Math.Max(NR, maxBack[t]);
                            NG = Math.Max(NG, maxBack[t]);
                            NB = Math.Max(NB, maxBack[t]);

                            int x, y, z;
                            x = k;
                            if (k == 0) {y = NG; z = NB;}
                            else if (k == 1) {y = NB; z = NR;}
                            else {y = NR; z = NG; }
                            y++;z++;
                            nextdp[x, y, z] += dp[a, i, j];
                            if (nextdp[x, y, z] >= mod) nextdp[x, y, z] -= mod;

                            //Console.WriteLine(x + " " + y + " " + z);
                        }
                    }
                }
            }
            dp = nextdp;
        }

        long ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    ans += dp[i, j, k];
                }
            }
        }
        ans %= mod;
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