using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static void Main() {
        Scanner cin = new Scanner();
        int N = cin.Int();
        var F = new int[N, 10];
        var P = new int[N, 11];

        for (int i = 0; i < N; i++) {
            var tmp = cin.ArrayInt(10);
            for (int j = 0; j < 10; j++) {
                F[i, j] = tmp[j];
            }
        }
        for (int i = 0; i < N; i++) {
            var tmp = cin.ArrayInt(11);
            for (int j = 0; j < 11; j++) {
                P[i, j] = tmp[j];
            }
        }

        int ans = int.MinValue;
        for (int i = 1; i < (1 << 10); i++) {
            int tmp = 0;
            for (int j = 0; j < N; j++) {
                int cnt = 0;
                for (int k = 0; k < 10; k++) {
                    if ((i >> k & 1)==1 && F[j, k]==1) cnt++;
                }
                tmp += P[j, cnt];
            }
            ans = Math.Max(ans, tmp);
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