using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int M = cin.Int();
        var l = new int[N];
        var r = new int[N];
        var s = new int[N];
        int point = 0;
        for (int i = 0; i < N; i++) {
            l[i] = cin.Int();
            r[i] = cin.Int();
            s[i] = cin.Int();
            point += s[i];
        }

        var tmp = new int[M + 2];
        for (int i = 0; i < N; i++) {
            tmp[l[i]] += s[i];
            tmp[r[i] + 1] -= s[i];
        }
        var sum = new int[M + 2];
        for(int i = 1; i <= M; i++) {
            sum[i] = tmp[i] + sum[i - 1];
        }
        sum[0] = int.MaxValue;
        sum[M + 1] = int.MaxValue;

        Console.WriteLine(point - sum.Min());
        Console.ReadLine();
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