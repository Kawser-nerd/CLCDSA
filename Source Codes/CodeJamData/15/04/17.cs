using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class D
{
    static bool Solve(int X, int R, int C)
    {
        if (R > C) return Solve(X, C, R); // ensure R <= C
        if ((R * C) % X != 0) return false; // we have to fill each tile (a)
        if (Math.Max(R, C) < X) return false; // we have to fit noodle (b)
        if (Math.Min(R, C) < ((X + 1) / 2)) return false; // we have to fit bent noodle (b)
        if (X == 1) return true;
        if (X == 2) return true;
        if (X == 3) return true;
        if (X == 4) return !(R == 2);
        if (X == 5) return !(R == 3 && C == 5);
        if (X == 6) return !(R == 3);
        if (X >= 7) return false; // there can be holes
        return false;
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] I = ReadInts();
            Console.WriteLine("Case #{0}: {1}", t, Solve(I[0], I[1], I[2]) ? "GABRIEL" : "RICHARD");
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
