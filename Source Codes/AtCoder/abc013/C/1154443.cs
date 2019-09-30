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

    long N;
    long H;

    long A;
    long B;
    long C;
    long D;
    long E;

    public void calc()
    {
        cin = new Scanner();
        N = cin.nextLong();
        H = cin.nextLong();

        A = cin.nextLong();
        B = cin.nextLong();
        C = cin.nextLong();
        D = cin.nextLong();
        E = cin.nextLong();

        long ans = long.MaxValue / 2;

        for(long X = 0;X<=N;X++)
        {
            long Y = calcY(X);
            ans = Math.Min(ans, A * X + C * Y);
        }

        Console.WriteLine(ans);
        Console.Read();
    }

    long calcY(long X)
    {
        if ((N - X) * E - H - B * X < 0)
            return 0;

        return ((N - X) * E - H - B * X) / (D + E) + 1;
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