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
        int[] C = new int[N];
        int[] S = new int[N];
        int[] F = new int[N];
        for(int i = 0; i < N - 1; i++)
        {
            int[] input = cin.ArrayInt(3);
            C[i] = input[0];
            S[i] = input[1];
            F[i] = input[2];
        }

        for(int i = 0; i < N; i++)
        {
            int t = 0; //t????j????????
            for(int j = i; j < N - 1; j++)
            {
                if (t < S[j]) t = S[j];
                else if (t % F[j] == 0) ;
                else t = t + F[j] - (t % F[j]);
                t += C[j];
            }
            Console.WriteLine(t);
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