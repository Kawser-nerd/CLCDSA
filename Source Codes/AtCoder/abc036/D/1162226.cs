using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    const int MOD = 1000000007;
    List<long>[] dp;

    public void calc()
    {
        cin = new Scanner();
        long N = cin.nextLong();

        dp = new List<long>[N];
        for (long i = 0; i < N; i++) dp[i] = new List<long>();

        for(long i = 0;i<N-1;i++)
        {
            long a = cin.nextLong()-1;
            long b = cin.nextLong()-1;

            dp[a].Add(b);
            dp[b].Add(a);
        }

        Tuple<long, long> ret = dfs(0, -1);
        long ans = (ret.Item1 + ret.Item2) % MOD;
        Console.WriteLine(ans);
        Console.Read();
    }

    Tuple<long,long> dfs(long root,long from)
    {
        long white, black;
        white = black = 1;

        foreach(long node in dp[root])
        {
            if (node == from) continue;
            Tuple<long, long> p = dfs(node, root);
            
            // root ? white ?? node ??????????
            // root ? black ?? node ??
            white = white * (p.Item1 + p.Item2) % MOD;
            black = black * p.Item1 % MOD;
        }

        return new Tuple<long, long>(white, black);
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