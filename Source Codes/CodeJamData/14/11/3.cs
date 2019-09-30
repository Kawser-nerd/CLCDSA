using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

public class Solver
{
    int BitCount(long x)
    {
        int res = 0;
        while (x > 0)
        {
            x &= x - 1;
            res++;
        }
        return res;
    }

    public object Solve()
    {
        int n = ReadInt();
        int l = ReadInt();
        long[] a = ReadTokens().Select(s => Convert.ToInt64(s, 2)).ToArray();
        long[] b = ReadTokens().Select(s => Convert.ToInt64(s, 2)).ToArray();
        Array.Sort(b);

        int best = int.MaxValue;
        for (int i = 0; i < n; i++)
        {
            long trans = a[0] ^ b[i];
            if (a.Select(x => x ^ trans).OrderBy(x => x).SequenceEqual(b))
                best = Math.Min(best, BitCount(trans));
        }

        return best == int.MaxValue ? "NOT POSSIBLE" : best.ToString();
    }

    #region Main
    protected static TextReader reader;
    protected static TextWriter writer;

    static void Main()
    {
        reader = new StreamReader("..\\..\\input.txt");
        writer = new StreamWriter("..\\..\\output.txt");
        //writer = Console.Out;
        Solver solver = new Solver();

        try
        {
            int t = ReadInt();
            for (int i = 0; i < t; i++)
            {
                writer.Write("Case #{0}: ", i + 1);
                object result = solver.Solve();
                if (result != null)
                {
                    writer.WriteLine(result);
                }
            }
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine(ex);
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read/Write

    static Queue<string> currentLineTokens = new Queue<string>();

    public static string ReadToken()
    {
        if (currentLineTokens.Count == 0)
        {
            currentLineTokens = new Queue<string>(reader.ReadLine().Trim().Split(' '));
        }
        return currentLineTokens.Dequeue();
    }

    public static string[] ReadTokens(bool fromCurrentLine = false)
    {
        string[] split;
        if (fromCurrentLine)
        {
            if (currentLineTokens.Count == 0)
                return new string[0];
            split = currentLineTokens.ToArray();
            currentLineTokens.Clear();
        }
        else
        {
            split = reader.ReadLine().Trim().Split(' ');
        }
        return split;
    }

    public static int ReadInt()
    {
        return int.Parse(ReadToken());
    }

    public static long ReadLong()
    {
        return long.Parse(ReadToken());
    }

    public static double ReadDouble()
    {
        return double.Parse(ReadToken());
    }

    public static int[] ReadIntArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(int.Parse).ToArray();
    }

    public static long[] ReadLongArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(long.Parse).ToArray();
    }

    public static double[] ReadDoubleArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(double.Parse).ToArray();
    }

    public static int[][] ReadIntMatrix(int numberOfRows)
    {
        int[][] matrix = new int[numberOfRows][];
        for (int i = 0; i < numberOfRows; i++)
            matrix[i] = ReadIntArray();
        return matrix;
    }

    public static string[] ReadLines(int quantity)
    {
        string[] lines = new string[quantity];
        for (int i = 0; i < quantity; i++)
        {
            lines[i] = reader.ReadLine().Trim();
        }
        return lines;
    }

    public static void WriteArray<T>(IEnumerable<T> array)
    {
        writer.WriteLine(string.Join(" ", array));
    }

    #endregion
}