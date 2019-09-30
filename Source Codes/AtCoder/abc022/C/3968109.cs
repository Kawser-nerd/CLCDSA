using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static Scanner cin = new Scanner();
    static void Main(string[] args) {

        const int INF = (int)1e8;
        int N = cin.Int();
        int M = cin.Int();

        var d = new int[N, N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) d[i, j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            int u = cin.Int();
            int v = cin.Int();
            int l = cin.Int();
            d[u - 1, v - 1] = l;
            d[v - 1, u - 1] = l;
        }

        var WF = new int[N, N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                WF[i, j] = d[i, j];
            }
        }
        for (int i = 1; i < N; i++) { //??????
            for (int j = 1; j < N; j++) { //??????
                for (int k = 1; k < N; k++) { //?????
                    //Warshall-Floyd?
                    WF[j, k] = Math.Min(WF[j, k], WF[j, i] + WF[i, k]); 
                }
            }
        }

        long min = long.MaxValue;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                min = Math.Min(min, d[0, i] + WF[i, j] + d[j, 0]);
            }
        }

        Console.WriteLine(min < INF ? min : -1);
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