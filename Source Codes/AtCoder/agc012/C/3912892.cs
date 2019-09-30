using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;

    List<int>[] es;

    void calc()
    {
        cin = new Scanner();
        long N = cin.nextLong();
        int num = 1;
        while ((1L << (num + 1)) - 1 <= N)
        {
            num++;
        }

        N -= (1L << num) - 1;
        
        int next = num + 1;
        List<int>[] pos = new List<int>[num + 1];
        for (int i = 0; i < num + 1; i++)
        {
            pos[i] = new List<int>();
        }

        for (int i = num; i >= 0; i--)
        {
            long plus = 1 + (1L << i) - 1;
            while (plus <= N)
            {
                pos[i].Add(next++);
                N -= plus;
            }
        }

        List<int> ans = new List<int>();
        for (int i = 0; i < next - 1; i++)
        {
            ans.Add(i + 1);
        }

        for (int i = 0; i < num; i++)
        {
            for (int j = pos[i].Count - 1; j >= 0; j--)
            {
                ans.Add(pos[i][j]);
            }
            ans.Add(i + 1);
        }

        Console.WriteLine(ans.Count);
        Console.WriteLine(string.Join(" ", ans));


    }
}




class Scanner
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

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}