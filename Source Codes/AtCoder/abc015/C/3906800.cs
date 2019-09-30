using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static int N = cin.Int();
    static int K = cin.Int();
    static int[,] T = new int[N, K];
    static List<int> list = new List<int>();

    static void Main() {
        for (int i = 0; i < N; i++) {
            var input = cin.ArrayInt(K);
            for (int j = 0; j < K; j++) {
                T[i, j] = input[j];
            }
        }

        Console.WriteLine(hoge(0, 0) ? "Found" : "Nothing");
        Console.ReadLine();
    }

    static bool hoge(int n, int value) {
        if (n == N) return value == 0;
        for (int i = 0; i < K; i++) {
            if (hoge(n + 1, value ^ T[n, i])) return true;
        }
        return false;
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