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
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }


    int N;
    public bool calc2(long[] A)
    {
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        if ((sum - N) % 2 == 1) return true;
        if (N % 2 == 0) return false;

        int oddcnt = 0;
        int oddpos = -1;
        for (int i = 0; i < N; i++)
        {
            if(A[i] % 2 == 1)
            {
                oddpos = i;
                oddcnt++;
            }
        }

        if (oddcnt != 1) return false;
        if (A[oddpos] == 1) return false;
        A[oddpos]--;

        long g = A[0];
        for (int i = 1; i < N; i++)
        {
            g = gcd(A[i], g);
        }
        for (int i = 0; i < N; i++)
        {
            A[i] /= g;
        }

        return !calc2(A);
    }

    long gcd(long a, long b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public void calc()
    {
        long[] A;
        N = cin.nextInt();
        A = new long[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextLong();
        }
        if (calc2(A)) Console.WriteLine("First");
        else Console.WriteLine("Second");
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