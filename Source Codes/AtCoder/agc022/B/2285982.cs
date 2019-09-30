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
        calc2(N);
    }

    List<int> myon = new List<int>();

    void calc2(int N)
    {
        if(N == 3)
        {
            Console.WriteLine("2 5 63");
            return;
        }

        if(N <= 15002)
        {
            calc3(N);
            return;
        }

        myon = new List<int>();
        for (int i = 2; i <= 30000; i+= 2)
        {
            myon.Add(i);
        }
        for (int i = 3; i <= 30000; i += 3)
        {
            if (i % 2 != 0) myon.Add(i);
        }

        long ss = 0;
        foreach (var item in myon)
        {
            ss += item;
        }

        List<int> num = new List<int>();
        long sum = 0;
        for (int i = 0; i < N - 1; i++)
        {
            num.Add(myon[i]);
            sum += myon[i];
        }

        int start = N - 1;
        if(N % 2 == 1)
        {
            sum -= myon[14999];
            sum += myon[N - 1];
            num[14999] = myon[N - 1];
            start = N;
        }


        for (int j = start; j < myon.Count; j++)
        {
            if ((sum + myon[j]) % 6 == 0)
            {
                num.Add(myon[j]);
                break;
            }
        }

        
        Console.WriteLine(string.Join(" ", num));

    }

    void calc3(int N)
    {
        if (N == 3)
        {
            Console.WriteLine("2 5 63");
            return;
        }
        List<int> num = new List<int>();
        long sum = 0;
        for (int i = 0; i < N - 2; i++)
        {
            num.Add((i + 1) * 2);
            sum += (i + 1) * 2;
        }
        while (sum % 3 != 0)
        {
            num[num.Count - 1] += 2;
            sum += 2;
        }
        num.Add(3);
        num.Add(9);
        Console.WriteLine(string.Join(" ", num));
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