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
    int[] sec;
    int[] per;

    long[] P, S;

    void calc()
    {
        long M = cin.nextLong();
        long F = cin.nextLong();
        int N = cin.nextInt();
        P = new long[N];
        S = new long[N];
        int[] num = new int[N];
        for (int i = 0; i < N; i++)
        {
            P[i] = cin.nextLong();
            S[i] = cin.nextLong() + 1;
            num[i] = i;
        }
        Array.Sort(num, compare);

        List<long> ls = new List<long>();
        List<long> lp = new List<long>();

        long precost = long.MaxValue;
        foreach (var item in num)
        {
            //Console.WriteLine("test {0} {1}", S[item], P[item]);
            if (P[item] >= precost) continue;
            precost = P[item];
            ls.Add(S[item]);
            lp.Add(P[item]);
        }

        long[] cost = lp.ToArray();
        long[] time = ls.ToArray();
        Array.Reverse(cost);
        Array.Reverse(time);
        for (int i = time.Length - 1; i > 0; i--)
        {
            time[i] -= time[i - 1];
        }
        for (int i = 0; i < time.Length; i++)
        {
            //Console.WriteLine("myon " + cost[i] + " " + time[i]);
        }

        long mi = 1;
        long ma = M / F + 1;
        while (ma - mi > 10000)
        {
            long mid1 = (mi + mi + ma) / 3;
            long mid2 = (mi + ma + ma) / 3;
            if (getcost(mid2, F, M, cost, time) > getcost(mid1, F, M, cost, time))
            {
                mi = mid1;
            }
            else
            {
                ma = mid2;
            }
        }
        Console.Error.WriteLine(mi + " " + ma);
        long ret = 0;
        for (long i = Math.Max(1, mi - 100000); i < ma + 100000; i++)
        {
            ret = Math.Max(ret, getcost(i, F, M, cost, time));
        }
        Console.WriteLine(ret);
    }

    int compare(int a, int b)
    {
        if (S[a] != S[b]) return -(S[a].CompareTo(S[b]));
        if (P[a] != P[b]) return (P[a].CompareTo(P[b]));
        return a.CompareTo(b);
    }

    long getcost(long a, long f, long m, long[] cost, long[] time)
    {
        long ret = 0;
        if ((double)f * a * 0.999999 > m) return ret;
        if (f * a >= m) return 0;
        m -= f * a;
        for (int i = 0; i < cost.Length; i++)
        {
            long use;
            if ((double)time[i] * a > 1e18 + 100) use = m / cost[i];
            else use = Math.Min(m / cost[i], time[i] * a);
            m -= use * cost[i];
            ret += use;
        }
        if (m < 0) Console.Error.WriteLine("!?");
        //Console.Error.WriteLine(a + " " + ret);
        return ret;
    }

}
