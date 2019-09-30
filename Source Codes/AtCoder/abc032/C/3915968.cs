using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main(string[] args) {
        int N = cin.Int();
        long K = cin.Long();
        var s = new long[N];
        for (int i = 0; i < N; i++) s[i] = cin.Long();

        if (s.Contains(0)) Console.WriteLine(N);
        else {
            int begin = 0, end = 0, ans = 0;
            long product = 1;
            while (end <= N - 1) {
                if (product * s[end] <= K) {
                    product *= s[end];
                    ans = Math.Max(ans, end - begin + 1);
                    end++;
                }
                else if (end > begin) {
                    product /= s[begin];
                    begin++;
                }
                else {
                    begin++;
                    end++;
                }
            }
            Console.WriteLine(ans);
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