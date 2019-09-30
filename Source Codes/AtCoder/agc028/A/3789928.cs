using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        Scanner cin = new Scanner();
        int N = cin.Int();
        int M = cin.Int();
        string S = Console.ReadLine();
        string T = Console.ReadLine();

        int n = N / GCD(N, M);
        int m = M / GCD(N, M);
        bool flag = true;
        for (int a = 0; a < GCD(N, M); a++)
        {
            if (S[a * n] != T[a * m]) flag = false;
        }

        Console.WriteLine(flag ? LCM(N, M) : -1);
        Console.ReadLine();
    }

    static int GCD(int a, int b) //a,b??????
    {
        if (a < b)
            // ??????????????
            return GCD(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    static long LCM(int a, int b) //a,b??????
    {
        return (long)a / GCD(a, b) * b;
    }
}

class Scanner //????
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

    public int Int()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Long() + add;
        }
        return Array;
    }

    public double Double()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Double() + add;
        }
        return Array;
    }
}