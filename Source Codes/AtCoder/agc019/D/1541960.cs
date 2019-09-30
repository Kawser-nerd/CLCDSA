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


    void calc()
    {
        cin = new Scanner();
        string A = cin.next();
        string B = cin.next();
        int N = A.Length;

        if(A == B)
        {
            Console.WriteLine(0);
            return;
        }
        if (B.IndexOf("1") == -1)
        {
            Console.WriteLine(-1);
            return;
        }

        int[] left = new int[N];
        int[] right = new int[N];
        int MAX = 9999;

        for (int i = 0; i < N; i++)
        {
            if(B[i] == '1')
            {
                left[i] = right[i] = 0;
            }
            else
            {
                left[i] = right[i] = MAX;
            }
        }

        for (int i = 0; i < N - 1; i++)
        {
            left[i + 1] = Math.Min(left[i + 1], left[i] + 1);
            right[i] = Math.Min(right[i], right[i + 1] + 1);
        }

        left[0] = Math.Min(left[0], left[N - 1] + 1);
        right[N - 1] = Math.Min(right[N - 1], right[0] + 1);

        for (int i = N - 2; i >= 0; i--)
        {
            left[i + 1] = Math.Min(left[i + 1], left[i] + 1);
            right[i] = Math.Min(right[i], right[i + 1] + 1);
        }

        left[0] = Math.Min(left[0], left[N - 1] + 1);
        right[N - 1] = Math.Min(right[N - 1], right[0] + 1);

        for (int i = 0; i < N - 1; i++)
        {
            left[i + 1] = Math.Min(left[i + 1], left[i] + 1);
            right[i] = Math.Min(right[i], right[i + 1] + 1);
        }

        left[0] = Math.Min(left[0], left[N - 1] + 1);
        right[N - 1] = Math.Min(right[N - 1], right[0] + 1);


        for (int i = N - 2; i >= 0; i--)
        {
            left[i + 1] = Math.Min(left[i + 1], left[i] + 1);
            right[i] = Math.Min(right[i], right[i + 1] + 1);
        }

        left[0] = Math.Min(left[0], left[N - 1] + 1);
        right[N - 1] = Math.Min(right[N - 1], right[0] + 1);


        int best = 99999999;

        for (int i = 0; i < N; i++)
        {
            int swapCost = 0;

            List<int> lbase = new List<int>();

            for (int j = 0; j < N; j++)
            {
                if(A[j] != B[(i + j) % N])
                {
                    swapCost++;
                    lbase.Add(((left[j] << 16) + (right[j])));
                }
            }
            lbase.Sort();
            lbase.Reverse();

            int moveCost = MAX;

            int l = MAX;
            int r = 0;
            foreach (var item in lbase)
            {
                int L = item >> 16;
                int R = item & 0xFFFF;
                l = L;
                moveCost = Math.Min(moveCost, calcPos(l, r, i, N));
                r = Math.Max(r, R);
            }
            l = 0;
            moveCost = Math.Min(moveCost, calcPos(l, r, i, N));

            best = Math.Min(best, swapCost + moveCost);

        }
        Console.WriteLine(best);
    }

    int calcPos(int l, int r, int m, int N)
    {
        int ans = 999999;
        //lr
        int rdist = Math.Abs(r - m);
        ans = Math.Min(ans, l + l + r + Math.Min(rdist, N - rdist));
        //rl
        int ldist = Math.Abs((N - l) - m);
        ans = Math.Min(ans, r + r + l + Math.Min(ldist, N - ldist));

        return ans;
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