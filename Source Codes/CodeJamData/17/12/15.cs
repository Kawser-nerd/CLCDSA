using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class B
{
    static int Solve(int N, int P, int[] G, int[][] PG)
    {
        int count = 0;
        int[] I = new int[N];
        int i;
        for (i = 0; i < N; ++i)
            I[i] = 0;
        // PG[0][p] >= n * G[0] * 9/10
        // PG[0][p] * 10 / 9 / G[0] >= n
        // PG[0][p] <= n * G[0] * 11/10
        // PG[0][p] * 10 / 11 / G[0] <= n
        while (true)
        {
            int maxPortions = int.MaxValue;
            int minPortions = int.MinValue;
            int j = 0;
            for (i = 0; i < N; ++i)
            {
                int minPor = (int)Math.Ceiling(1.0 * PG[i][I[i]] * 10 / 11 / G[i]);
                int maxPor = (int)Math.Floor(1.0 * PG[i][I[i]] * 10 / 9 / G[i]);
                if (maxPor < maxPortions)
                {
                    maxPortions = maxPor;
                    j = i;
                }
                if (minPor > minPortions)
                {
                    minPortions = minPor;
                }
            }
            if (minPortions > maxPortions)
            {
                if (++I[j] == P)
                    return count;
                continue;
            }
            ++count;
            for (i = 0; i < N; ++i)
            {
                if (++I[i] == P)
                    return count;
            }
        }
        return count;
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] limits = ReadInts();
            int N = limits[0];
            int P = limits[1];
            int[] G = ReadInts();
            int[][] PG = new int[N][];
            for (int i = 0; i < N; ++i)
            {
                PG[i] = ReadInts();
                Array.Sort(PG[i]);
            }
            Console.WriteLine("Case #{0}: {1}", t, Solve(N, P, G, PG));
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

    static void Write<T>(IEnumerable<T> col)
    {
        Console.WriteLine(String.Join(" ", col));
    }

    static void Write<T>(T[] col)
    {
        Console.WriteLine(String.Join(" ", col));
    }
}
