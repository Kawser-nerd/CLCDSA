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

    long mod = 998244353;
    void calc()
    {
        cin = new Scanner();
        string S = cin.next();
        dic = new Dictionary<string, long>();
        Console.WriteLine(dfs(S));
    }

    Dictionary<string, long> dic;

    long dfs(string S)
    {
        if (dic.ContainsKey(S)) return dic[S];
        if (S == "") return 1;
        if (S == "0") return 1;
        if (S == "1") return 2;
        //Console.WriteLine(S);

        long ans = (long)(S[0] - '0' + 1) * dfs(S.Substring(1));
        for (int r = 1; r < S.Length; r++)
        {
            StringBuilder sb = new StringBuilder(S.Substring(0, r));
            int cnt = 0;
            while(cnt + r <= S.Length)
            {
                for (int k = 0; k < r; k++)
                {
                    if (S[cnt] == '0') sb[k] = '0';
                    cnt++;
                }
                if (cnt != r)
                {
                    ans += dfs(sb.ToString()) * dfs(S.Substring(cnt));
                    ans %= mod;
                }
            }
        }
        return dic[S] = ans;
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