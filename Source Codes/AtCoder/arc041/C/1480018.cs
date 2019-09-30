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

    int N, L;
    void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        L = cin.nextInt();
        int[] x = new int[N];

        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt() * 2;
            if (cin.next() == "L") x[i]++;
        }

        List<int> a = new List<int>();
        List<int> b = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if(x[i] % 2 == 0)
            {
                if(b.Count != 0)
                {
                    ans += add(a, b);
                    a.Clear();
                    b.Clear();
                }
                a.Add(x[i] / 2);
            }
            else
            {
                b.Add(x[i] / 2);
            }
        }
        if (a.Count != 0 || b.Count != 0) ans += add(a, b);
        Console.WriteLine(ans);
    }

    long add(List<int> a, List<int> b)
    {
        long ans = 0;

        long diff;
        if(b.Count == 0)
        {
            diff = L - a[a.Count - 1];
        }
        else if(a.Count == 0)
        {
            diff = b[0] - 1;
        }
        else
        {
            diff = b[0] - a[a.Count - 1] - 1;
        }

        for (int i = a.Count - 2; i >= 0; i--)
        {
            ans += a[a.Count - 1] - a[i] - (a.Count - 1 - i);
        }
        for (int i = 1; i < b.Count; i++)
        {
            ans += b[i] - b[0] - i;
        }
        ans += diff * Math.Max(a.Count, b.Count);
        return ans;
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