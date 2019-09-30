using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        var N = cin.Long();
        var M = cin.Long();

        for (int i = 0; i <= M / 3 && i <= N; i++) {
            if((M / 2.0 - N - i / 2.0) % 1 == 0&&(2 * N - M / 2.0 - i / 2.0) % 1 == 0&& M / 2.0 - N - i / 2.0 >= 0&& 2 * N - M / 2.0 - i / 2.0 >= 0) {
                Console.WriteLine((long)(2 * N - M / 2.0 - i / 2.0) + " " + i + " " + (long)(M / 2.0 - N - i / 2.0));
                return;
            }
        }
        Console.WriteLine(-1 + " " + -1 + " " + -1);
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