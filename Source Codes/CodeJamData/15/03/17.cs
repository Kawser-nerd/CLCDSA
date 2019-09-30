using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class C
{

    // 1 i j k = 1 2 3 4
    static readonly int[,] M = {
                          {0, 0, 0, 0, 0},
                          {0, 1, 2, 3, 4},
                          {0, 2, -1, 4, -3},
                          {0, 3, -4, -1, 2},
                          {0, 4, 3, -2, -1}
                      };
    static readonly int i = q2int('i');
    static readonly int j = q2int('j');
    static readonly int k = q2int('k');

    static int q2int(char c)
    {
        return c - 'i' + 2;
    }

    static int mult(int x, int y)
    {
        return Math.Sign(x) * Math.Sign(y) * M[Math.Abs(x), Math.Abs(y)];
    }

    static string repeat(string s, long x)
    {
        StringBuilder sb = new StringBuilder();
        while (x-- > 0)
            sb.Append(s);
        return sb.ToString();
    }

    static bool Solve(int L, long X, string S)
    {
        if (X > 1)
        {
            X = Math.Min(X, 12 + (X % 4));
            return Solve((int)(L * X), 1, repeat(S, X));
        }
        List<int> I = new List<int>();
        List<int> K = new List<int>();
        int ri = 1;
        int rk = 1;
        for (int a = 0; a < L; ++a)
        {
            ri = mult(ri, q2int(S[a]));
            rk = mult(q2int(S[L - 1 - a]), rk);
            if (ri == i)
                I.Add(a);
            if (rk == k)
                K.Add(L - 1 - a);
        }
        if (ri != -1 || rk != -1 || (I.Count == 0) || (K.Count == 0))
            return false;
        return I[0] < K[0];
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            long[] LX = ReadLongs();
            string S = ReadLine();
            Console.WriteLine("Case #{0}: {1}", t, Solve((int)LX[0], LX[1], S) ? "YES" : "NO");
        }
    }

    // INPUT READING
    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static string[] ReadWords(char separator)
    {
        return ReadLine().Split(separator);
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static long ReadLong()
    {
        return long.Parse(ReadLine());
    }

    static double ReadDouble()
    {
        return double.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static int[] ReadInts(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), int.Parse);
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static long[] ReadLongs(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), long.Parse);
    }

    static double[] ReadDoubles()
    {
        return Array.ConvertAll(ReadWords(), double.Parse);
    }

    static double[] ReadDoubles(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), double.Parse);
    }

    static void WriteList<T>(List<T> col)
    {
        int count = col.Count;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }

    static void WriteArray<T>(T[] col)
    {
        int count = col.Length;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }
}
