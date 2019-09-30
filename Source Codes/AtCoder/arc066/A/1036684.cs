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
        int[] Cnts = new int[N + 1];

        for (int i = 0; i < N; i++)
        {
            int a = cin.nextInt();
            Cnts[a]++;
        }

        for (int i = 0; i < N + 1; i++)
        {
            if (N % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    if (Cnts[i] == 0) continue;
                }
                else
                {
                    if (Cnts[i] == 2) continue;
                }
            }
            else
            {
                if (i == 0)
                {
                    if (Cnts[i] == 1) continue;
                }
                else if (i % 2 == 0)
                {
                    if (Cnts[i] == 2) continue;
                }
                else
                {
                    if (Cnts[i] == 0) continue;
                }
            }
            Console.WriteLine(0);
            return;
        }

        Console.WriteLine(pow2(N / 2));
    }

    private int pow2(int n)
    {
        int ret = 1;
        int mod = 1000000007;

        for (int i = 0; i < n; i++)
        {
            ret *= 2;
            ret %= mod;
        }
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