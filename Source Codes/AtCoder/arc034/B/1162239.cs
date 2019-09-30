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
    
    public void calc()
    {

        cin = new Scanner();
        long N = cin.nextLong();
        List<long> ans = new List<long>();

        // N <= 10^18 ? f(N) <= f(10^8 - 1) = 9 * 17 = 153
        // ??? N - 153 ?? N ?????????
        for(long i = Math.Max(1,N-153);i<=N;i++)
        {
            if (test(i,N)) ans.Add(i);
        }

        Console.WriteLine(ans.Count);
        foreach (long i in ans) Console.WriteLine(i);
        Console.Read();
    }

    bool test(long n,long N)
    {
        string str_n = n.ToString();
        long f = 0;
        for (int i = 0; i < str_n.Length; i++) f += long.Parse(str_n[i].ToString());

        return (n + f) == N;
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