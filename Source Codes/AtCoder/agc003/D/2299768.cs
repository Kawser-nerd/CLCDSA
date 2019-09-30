using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }


    Scanner cin;

    bool isPrime(long a)
    {
        if (a < 2) return false;
        long i;
        for (i = 2; i * i <= a; i++)
        {
            if (a % i == 0) return false;
        }
        return true;
    }


    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        long[] A = cin.ArrayLong(N);
        long[] B = new long[N];
        long[] C = (long[])A.Clone();
        for (int i = 0; i < N; i++)
        {
            B[i] = 1;
        }
        for (int i = 2; (long)i * i * i <= (long)1e10; i++)
        {
            if (isPrime(i))
            {
                for (int j = 0; j < N; j++)
                {
                    long mul = (long)i * i * i;
                    while (A[j] % mul == 0)
                    {
                        A[j] /= mul;
                        C[j] /= mul;
                    }
                    if (A[j] % i == 0)
                    {
                        B[j] *= mul;
                        //Console.WriteLine(j + " " + A[j] + " " + B[j] + " " + C);
                        while (C[j] % i == 0)
                        {
                            C[j] /= i;
                            B[j] /= i;
                        }

                        //Console.WriteLine(j+ " " + A[j] + " " + B[j] + " " + C);
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            long sq = (long)Math.Sqrt(C[i] + 1);
            if (sq * sq == C[i])
            {
                B[i] *= sq;
            }
            else B[i] *= C[i] * C[i];
        }

        int ans = 0;
        Dictionary<long, int> dic = new Dictionary<long, int>();
        for (int i = 0; i < N; i++)
        {
            //Console.WriteLine(A[i] + " " + B[i]);
            if (!dic.ContainsKey(A[i])) dic[A[i]] = 0;
            if (!dic.ContainsKey(B[i])) dic[B[i]] = 0;
            dic[A[i]]++;
            if (dic[A[i]] > dic[B[i]]) ans++;
            if (A[i] == 1 && dic[A[i]] == 1) ans++;
        }

        Console.WriteLine(ans);
    }

    int[] uni;
    void init(int N)
    {
        uni = new int[N];
        for (int i = 0; i < N; i++)
        {
            uni[i] = -1;
        }
    }

    int root(int a)
    {
        if (uni[a] < 0) return a;
        else return uni[a] = root(uni[a]);
    }

    bool connect(int a, int b)
    {
        a = root(a);
        b = root(b);
        if (a == b) return false;
        if (uni[a] > uni[b]) swap(ref a, ref b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }

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