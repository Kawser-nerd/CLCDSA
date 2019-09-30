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
    
    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
        }

        var a = calc2(A);
        Array.Reverse(A);
        var b = calc2(A);
        Array.Reverse(b);
        Array.Reverse(A);

        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans += (a[i]) * (long)(b[i]) * A[i];
        }
        Console.WriteLine(ans);
    }

    int[] calc2(int[] A)
    {
        int[] ans = new int[A.Length];
        int N = A.Length;
        int[] num = new int[N + 1];
        int[] pos = new int[N + 1];
        int cnt = 0;
        num[0] = -1;
        pos[0] = -1;


        for (int i = 0; i < A.Length; i++)
        {
            while (num[cnt] > A[i]) cnt--;
            ans[i] = i - pos[cnt];
            cnt++;
            num[cnt] = A[i];
            pos[cnt] = i;
        }
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}