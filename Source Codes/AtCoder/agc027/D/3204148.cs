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

    int P = 500;
    List<long> plist;

    int[] vy = { 1, 0, -1, 0 };
    int[] vx = { 0, 1, 0, -1 };

    long[] xar, yar;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();

        plist = new List<long>();
        for (int i = 2; plist.Count < P * 4; i++)
        {
            if(isPrime(i)) plist.Add(i);
        }

        xar = new long[P * 2];
        yar = new long[P * 2];

        for (int i = 0; i < P; i++)
        {
            xar[(i * 4 % (P * 2)) + ((i * 4) / (P * 2)) * 2] = plist[i];
            yar[i * 2] = plist[P * 2 + i];
        }


        long[,] ans = new long[P, P];

        for (int i = 0; i < P; i++)
        {
            for (int j = 0; j < P; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    ans[i, j] = yar[i + j] * xar[(i - j) + P];
                }
            }
        }



        long maxnext = 0;
        for (int i = 0; i < P; i++)
        {
            for (int j = 0; j < P; j++)
            {
                if (ans[i,j] == 0)
                {
                    long next = 1;
                    int A = i + j;
                    int B = (i - j) + P;
                    if (A != 0) next *= yar[A - 1];
                    next *= yar[A + 1];

                    if (B != 0) next *= xar[B - 1];
                    if( B != xar.Length - 1) next *= xar[B + 1];

                    next += 1;
                    ans[i, j] = next;
                    maxnext = Math.Max(next, maxnext);
                }
            }
        }

        Dictionary<long, int> dic = new Dictionary<long, int>();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    if (dic.ContainsKey(ans[i, j]))
                    {
                        Console.WriteLine("!?1 " + ans[i, j]);
                    }
                    dic[ans[i, j]] = 1;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    if (dic.ContainsKey(ans[i, j]))
                    {
                        Console.WriteLine("!?2 " + ans[i, j]);
                    }
                    dic[ans[i, j]] = 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                long MAX = Math.Max(ans[i, j], ans[i, j + 1]);
                long MIN = Math.Min(ans[i, j], ans[i, j + 1]);
                if (MAX % MIN != 1) Console.WriteLine("!? " + MAX + " " + MIN + " " + (MAX % MIN));
            }
        }


        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N; j++)
            {
                long MAX = Math.Max(ans[i, j], ans[i + 1, j]);
                long MIN = Math.Min(ans[i, j], ans[i + 1, j]);
                if (MAX % MIN != 1) Console.WriteLine("!? " + MAX + " " + MIN + " " + (MAX % MIN));
            }
        }


        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Console.Write(ans[i,j] + " ");
            }
            Console.WriteLine();
        }

        //Console.WriteLine(maxnext);
        //Console.WriteLine((long)1e15);
    }

    bool inside(int y, int x)
    {
        return y >= 0 && x >= 0 && y < P && x < P;
    }
    
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

    long gcd(long a, long b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long lcm(long a, long b)
    {
        return a / gcd(a, b) * b;
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