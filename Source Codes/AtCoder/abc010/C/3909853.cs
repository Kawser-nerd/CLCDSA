using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int txa = cin.Int();
        int tya = cin.Int();
        int txb = cin.Int();
        int tyb = cin.Int();
        int T = cin.Int();
        int V = cin.Int();
        int n = cin.Int();
        var x = new int[n];
        var y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = cin.Int();
            y[i] = cin.Int();
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (Math.Sqrt(Math.Pow(txa - x[i], 2) + Math.Pow(tya - y[i], 2)) + Math.Sqrt(Math.Pow(txb - x[i], 2) + Math.Pow(tyb - y[i], 2)) <= T * V) flag = true;
        }
        Console.WriteLine(flag ? "YES" : "NO");
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