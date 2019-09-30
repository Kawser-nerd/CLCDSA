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
        int[] A = new int[N];
        int[] B = new int[N];
        long[] C = new long[2 * N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
            B[i] = cin.nextInt();
            C[i] = (long)A[i] * N * 2 + i * 2; 
            C[N + i] = (long)B[i] * N * 2 + i * 2 + 1;
        }

        Array.Sort(C);

        int[] cnt = new int[N];
        int[] num = new int[2 * N];
        int[] pos = new int[2 * N];
        int[] flag = new int[2 * N];
        bool find2 = false;

        for (int i = 0; i < 2 * N; i++)
        {
            num[i] = (int)(C[i] / (2 * N));
            pos[i] = (int)(C[i] / 2 % N);
            flag[i] = (int)(C[i] % 2);
        }

        long sum = 0;
        int flagsum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += num[i];
            cnt[pos[i]]++;
            if (cnt[pos[i]] == 2) find2 = true;
            flagsum += flag[i];
        }

        long ans = long.MaxValue;
        if (find2 || flagsum == 0 || flagsum == N) ans = sum;

        for (int i = Math.Max(0, N - 4); i < N; i++)
        {
            for (int j = N; j < Math.Min(2 * N, N + 4); j++)
            {
                long newSum = sum + num[j] - num[i];
                bool newFind2 = find2 | (cnt[pos[j]] == 1 && pos[i] != pos[j]);
                int newFlagSum = flagsum - flag[i] + flag[j];

                if (newFind2 || newFlagSum == 0 || newFlagSum == N) ans = Math.Min(ans, newSum);
            }
        }

        Console.WriteLine(ans);
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