using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class A
{
    static int Solve(string SC)
    {
        int sum = 0;
        int add = 0;
        for (int k = 0; k < SC.Length; ++k)
        {
            int count = SC[k] - '0';
            if (count > 0 && sum < k)
            {
                add += k - sum;
                sum = k;
            }
            sum += count;
        }
        return add;
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            string[] tokens = ReadWords();
            Console.WriteLine("Case #{0}: {1}", t, Solve(tokens[1]));
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
