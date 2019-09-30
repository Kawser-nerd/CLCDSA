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

        int[] T = new int[N];
        int[] A = new int[N];

        for(int i = 0;i<N;i++)
        {
            T[i] = cin.nextInt();
            A[i] = cin.nextInt();
        }

        long now_T = T[0];
        long now_A = A[0];

        for (int i = 1; i < N; i++)
        {
            long pd = Math.Max(prod(now_T, T[i]), prod(now_A, A[i]));
            now_T = T[i] * pd;
            now_A = A[i] * pd;           
        }

        Console.WriteLine(now_T + now_A);
        Console.Read();
    }

    long prod(long x,long y)
    {
        if (x < y) return 1;
        if (x % y == 0) return x / y;
        return x / y + 1;
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