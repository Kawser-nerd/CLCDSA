using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

class Myon
{
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        //Console.SetOut(new Printer(Console.OpenStandardOutput()));
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }


    public void calc()
    {
        int N = cin.nextInt();
        long x = cin.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
        }
        long[] B = (long[])A.Clone();
        Array.Reverse(B);
        long ans = Math.Min(calc2(N, x, A), calc2(N, x, B));
        Console.WriteLine(ans);
    }

    long calc2(int N, long x, long[] A)
    {
        long ans = 0;

        for (int i = 1; i < N; i++)
        {
            long dec = A[i - 1] + A[i] - x;
            if (dec > 0)
            {
                ans += dec;
                long dec2 = Math.Min(dec, A[i]);
                A[i] -= dec2;
            }
        }
        return ans;
    }
}

class Printer : StreamWriter
{
    public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
    public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    public Printer(Stream stream, Encoding encoding) : base(stream, encoding) { }
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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