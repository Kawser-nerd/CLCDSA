using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        Scanner cin = new Scanner();
        int N = cin.Int();
        int M = cin.Int();

        var a = new int[N + 1];
        var b = new int[N + 1];
        var c = new int[M + 1];
        var d = new int[M + 1];
        for(int i = 1; i <= N; i++)
        {
            a[i] = cin.Int();
            b[i] = cin.Int();
        }
        for(int i = 1; i <= M; i++)
        {
            c[i] = cin.Int();
            d[i] = cin.Int();
        }

        for(int i = 1; i <= N; i++)
        {
            int min_index = M;
            int min = int.MaxValue;
            for (int j = M; j >= 1; j--)
            {
                int tmp = Math.Abs(a[i] - c[j]) + Math.Abs(b[i] - d[j]);
                if(tmp <= min)
                {
                    min = tmp;
                    min_index = j;
                }
            }
            Console.WriteLine(min_index);
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