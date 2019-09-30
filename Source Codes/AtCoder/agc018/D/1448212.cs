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
    List<Tuple<int, int>>[] es;

    long ans;

    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        es = new List<Tuple<int, int>>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<Tuple<int, int>>();
        }
        for (int i = 0; i < N - 1; i++)
        {
            int A = cin.nextInt() - 1;
            int B = cin.nextInt() - 1;
            int C = cin.nextInt();
            es[A].Add(Tuple.Create(B, C));
            es[B].Add(Tuple.Create(A, C));
        }
        int start = 0;
        for (int i = 0; i < N; i++)
        {
            if (es[i].Count <= 1) start = i;
        }
        dec = 999999999;
        num = new int[N];
        center = -1;
        maxDep = -1;
        maxPos = -1;
        ans = 0;
        dfs(start, -1, 0);

        if (need != -1) dec = need;
        else
        {
            foreach (var item in es[center])
            {
                dec = Math.Min(dec, item.Item2);
            }
        }
        Console.WriteLine(ans - dec);
    }

    int[] num;
    int dec;
    int maxDep;
    int maxPos;
    int need = -1;
    int center = -1;

    int dfs(int now, int pre, int d)
    {
        if (num[now] != 0) return num[now];
        if (maxDep < d)
        {
            maxDep = d;
            maxPos = now;
        }
        int ret = 1;
        bool check = true;
        foreach (var item in es[now])
        {
            if (item.Item1 == pre) continue;
            int sum = dfs(item.Item1, now, d + 1);
            ret += sum;
            if (sum * 2 >= N) check = false;
        }
        num[now] = ret;
        if (num[now]  * 2 < N) check = false;
        foreach (var item in es[now])
        {
            if (item.Item1 == pre) continue;
            int down = num[item.Item1];
            int up = N - down;
            ans += Math.Min(down * 2, up * 2) * (long)item.Item2;

            if (Math.Min(down * 2, up * 2) == N) need = item.Item2;
        }
        if (check) center = now;
        return ret;
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