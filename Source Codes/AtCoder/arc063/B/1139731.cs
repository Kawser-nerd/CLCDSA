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
        int N = cin.nextInt();
        int T = cin.nextInt();

        int[] A = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
        }

        int[] back_max = new int[N - 1];
        int max = -1;

        for(int i = N-2;i>=0;i--)
        {
            max = Math.Max(max, A[i + 1]);
            back_max[i] = max;
        }

        //profits[i] := ??i??????????????
        int[] profits = new int[N - 1];
        for(int i = 0;i<N-1;i++)
        {
            profits[i] = back_max[i] - A[i];
        }

        int max_profit = profits.Max();
        int max_cnt = profits.Count(x => x == max_profit);

        Console.WriteLine(max_cnt);
        Console.Read();     
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