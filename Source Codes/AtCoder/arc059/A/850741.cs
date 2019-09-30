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

        int[] a = new int[N];
        for (int i = 0; i < N; i++) a[i] = cin.nextInt();

        int min = int.MaxValue / 2;
        for(int i = - 100;i<=100;i++)
        {
            int sum = 0;
            for (int j = 0; j < N; j++) sum += (a[j] - i) * (a[j] - i);

            min = Math.Min(sum, min);
        }

        Console.WriteLine(min);
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