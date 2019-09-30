using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;
using System.Collections;

class A
{
    static char Get(char[][] G, int r, int c)
    {
        if (r < 0 || r >= G.Length) return (char)0;
        if (c < 0 || c >= G[r].Length) return (char)0;
        return G[r][c];
    }

    static void Solve(char[][] G, int R, int C)
    {
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                if (G[r][c] == '?') continue;
                // spread right
                for (int k = 1; c+k < C && G[r][c+k] == '?'; ++k)
                {
                    G[r][c + k] = G[r][c];
                }
                // spread left
                for (int k = -1; c + k >= 0 && G[r][c + k] == '?'; --k)
                {
                    G[r][c + k] = G[r][c];
                }
            }
        }
        for (int r = 1; r < R; ++r)
        {
            // whole row is ?
            if (G[r][0] == '?' && G[r - 1][0] != '?')
                G[r] = G[r - 1];
        }
        for (int r = R-2; r >= 0; --r)
        {
            // whole row is ?
            if (G[r][0] == '?' && G[r + 1][0] != '?')
                G[r] = G[r + 1];
        }
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] size = ReadInts();
            int R = size[0];
            int C = size[1];
            char[][] G = new char[R][];
            for (int r = 0; r < R; ++r)
            {
                G[r] = ReadLine().ToCharArray();
            }
            Solve(G, R, C);
            Console.WriteLine("Case #{0}:", t);
            foreach (var row in G)
            {
                Console.WriteLine(new string(row));
            }
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
