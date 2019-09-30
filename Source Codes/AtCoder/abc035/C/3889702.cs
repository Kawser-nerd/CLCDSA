using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int Q = cin.Int();
        var l = new int[Q + 1];
        var r = new int[Q + 1];

        for (int i = 0; i < Q; i++) {
            l[i] = cin.Int();
            r[i] = cin.Int();
        }

        var sum = new int[N + 2];
        for (int i = 0; i < Q; i++) {
            sum[l[i]]++;
            sum[r[i] + 1]--;
        }

        var SUM = new int[N + 2];
        for(int i = 1; i <= N; i++) {
            SUM[i] = SUM[i - 1] + sum[i];
            if (SUM[i] % 2 == 0) Console.Write(0);
            else Console.Write(1);
        }

        Console.WriteLine();
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