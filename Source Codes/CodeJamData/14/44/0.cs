using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }



    void run()
    {
        int M = cin.nextInt();
        int N = cin.nextInt();
        string[] S = new string[M];
        for (int i = 0; i < M; i++)
        {
            S[i] = cin.next();
        }

        int[] add = new int[1 << M];
        for (int i = 0; i < (1<<M); i++)
        {
            Dictionary<string, int> dic = new Dictionary<string, int>();
            dic[""] = 1;
            for (int j = 0; j < M; j++)
            {
                if ((i >> j) % 2 == 0) continue;
                for (int k = 0; k < S[j].Length; k++)
                {
                    dic[S[j].Substring(0, k + 1)] = 1;
                }
            }
            add[i] = dic.Count;
        }

        int[] dp = new int[1 << M];
        long[] dpcount = new long[1 << M];
        long mod = 1000000007;
        dpcount[0] = 1;
        for (int t = 0; t < N; t++)
        {
            int[] nextdp = new int[1 << M];
            long[] nextdpcount = new long[1 << M];

            for (int i = 0; i < (1 << M); i++)
            {
                if (dpcount[i] == 0) continue;

                int target = (1 << M) - 1 - i;
                for (int j = target; j >= 1; j--)
                {
                    j &= target;
                    if (j == 0) break;

                    int next = i + j;
                    int nextnum = dp[i] + add[j];
                    if (nextdp[next] < nextnum)
                    {
                        nextdp[next] = nextnum;
                        nextdpcount[next] = dpcount[i];
                    }
                    else if (nextdp[next] == nextnum)
                    {
                        nextdpcount[next] += dpcount[i];
                        nextdpcount[next] %= mod;
                    }
                }
            }
            dp = nextdp;
            dpcount = nextdpcount;
        }
        Console.WriteLine("{0} {1}", dp[(1 << M) - 1], dpcount[(1 << M) - 1]);

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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
