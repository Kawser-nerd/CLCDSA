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

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        long[] X = cin.ArrayLong(N);
        int M = cin.nextInt();
        long K = cin.nextLong();

        int[] A = cin.ArrayInt(M, -2);

        int[] pos = new int[N - 1];
        for (int i = 0; i < N - 1; i++)
        {
            pos[i] = i;
        }

        for (int i = 0; i < M; i++)
        {
            int a = A[i];
            int b = A[i] + 1;
            swap(ref pos[a], ref pos[b]);
        }
        //i -> pos[i]???????????

        bool[] used = new bool[N - 1];
        for (int i = 0; i < N - 1; i++)
        {
            if (used[i]) continue;
            List<int> l = new List<int>();
            l.Add(i);

            int now = pos[i];
            while(now != i)
            {
                l.Add(now); now = pos[now];
            }

            int step = (int)(K % l.Count);

            for (int j = 0; j < l.Count; j++)
            {
                pos[l[j]] = l[(j + step) % l.Count]; 
            }

            foreach (var j in l)
            {
                used[j] = true;
            }
        }

        long[] diff = new long[N - 1];
        for (int i = 0; i < N - 1; i++)
        {
            int P = pos[i];
            diff[i] = X[P + 1] - X[P];
        }

        long[] ans = new long[N];
        ans[0] = X[0];
        for (int i = 0; i < N - 1; i++)
        {
            ans[i + 1] = ans[i] + diff[i];
        }

        for (int i = 0; i < N; i++)
        {
            Console.WriteLine(ans[i]);
        }


    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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