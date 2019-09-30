using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int K = cin.Int();
        var a = cin.ArrayLong(N);

        long ans = 0;
        if (N >= 2 * K - 2) {
            for (int i = 0; i < K - 1; i++) {
                ans += a[i] * (i + 1);
            }
            for (int i = N - K + 1; i < N; i++) {
                ans += a[i] * (N - i);
            }
            for (int i = K - 1; i <= N - K; i++) {
                ans += a[i] * K;
            }
        }
        else {
            for (int i = 0; i < N - K + 1; i++) {
                ans += a[i] * (i + 1);
            }
            for (int i = K - 1; i < N; i++) {
                ans += a[i] * (N - i);
            }
            for (int i = N - K + 1; i <= K - 2; i++) {
                ans += a[i] * (N - K + 1);
            }
        }
        Console.WriteLine(ans);
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