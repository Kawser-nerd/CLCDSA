using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

public class Solver
{
    private int rs, cs;

    int Attempt(bool[,] field, int r, int c)
    {
        if (r >= 0 && r < rs && c >= 0 && c < cs && !field[r, c])
        {
            field[r, c] = true;
            return 1;
        }
        return 0;
    }

    int Clear(bool[,] field, int r, int c)
    {
        int ret = 0;
        ret += Attempt(field, r - 1, c - 1);
        ret += Attempt(field, r - 1, c);
        ret += Attempt(field, r - 1, c + 1);
        ret += Attempt(field, r, c - 1);
        ret += Attempt(field, r, c);
        ret += Attempt(field, r, c + 1);
        ret += Attempt(field, r + 1, c - 1);
        ret += Attempt(field, r + 1, c);
        ret += Attempt(field, r + 1, c + 1);

        return ret;
    }

    public object Solve()
    {
        rs = ReadInt();
        cs = ReadInt();
        int rcm = Math.Min(rs, cs);
        int m = ReadInt();
        int n = rs * cs - m;
        //writer.WriteLine("{0} {1} {2}", rs, cs, m);
        writer.WriteLine();

        if (n > 1)
        {
            if (rcm == 2 && (n % 2 == 1 || n == 2))
            {
                return "Impossible";
            }
            if (rcm > 2 && (n < 4 || n == 5 || n == 7))
            {
                return "Impossible";
            }
        }

        bool[,] field = new bool[rs, cs];
        if (n > 1)
        {
            int count = 0;
            if (n % 2 == 1)
                count += Clear(field, 1, 1);
            for (int i = 0; i < rs && count < n; i++)
                for (int j = 0; j < cs && count < n; j++)
                    count += Clear(field, i, j);

            if (n - count == -1)
                field[n / cs - 1, cs - 1] = false;
        }

        for (int i = 0; i < rs; i++)
        {
            for (int j = 0; j < cs; j++)
            {
                if (i == 0 && j == 0)
                    writer.Write('c');
                else
                    writer.Write(field[i, j] ? '.' : '*');
            }
            writer.WriteLine();
        }            
        return null;
    }

    private static int casesToRun = -1;

    #region I/O
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
                if (casesToRun != -1 && casesToRun != i)
                    continue;
                writer.Write("Case #{0}:", i + 1);
                //Console.Error.Write("Case #{0}: ", i + 1);
                object result = solver.Solve();
                if (result != null)
                {
                    writer.WriteLine(result);
                    //Console.Error.WriteLine(result);
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

    #region Read helpers

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

    #endregion
}