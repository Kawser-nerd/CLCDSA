using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main() {
        int N = cin.Int();
        int D = cin.Int();
        int K = cin.Int();
        var L = new int[D];
        var R = new int[D];
        for (int i = 0; i < D; i++) {
            L[i] = cin.Int();
            R[i] = cin.Int();
        }
        var S = new int[K];
        var T = new int[K];
        for (int i = 0; i < K; i++) {
            S[i] = cin.Int();
            T[i] = cin.Int();
        }

        for (int i = 0; i < K; i++) { //i: ??
            int position = S[i], day = 0;
            for (int j = 0; j < D; j++) { //j:??
                if (S[i] < T[i]) {
                    if (L[j] <= position && position <= R[j]) {
                        position = R[j];
                        day = j + 1;
                        if (position >= T[i]) break;
                    }
                }
                else {
                    if (L[j] <= position && position <= R[j]) {
                        position = L[j];
                        day = j + 1;
                        if (position <= T[i]) break;
                    }
                }
            }
            Console.WriteLine(day);
        }
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