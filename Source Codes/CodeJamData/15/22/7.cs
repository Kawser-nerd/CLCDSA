using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    public void Solve()
    {
        int nt = ReadInt();
        for(int tt = 1; tt <= nt; tt++)
        {
            int rs = ReadInt();
            int cs = ReadInt();
            int n = ReadInt();

            int ans = int.MaxValue;
            for (int mask = 0; mask < 1 << rs * cs; mask++)
            {
                var f = new bool[rs, cs];
                int u = 0;
                int c = 0;
                for (int i = 0; i < rs * cs; i++)
                    if ((mask >> i & 1) == 1)
                    {
                        f[i / cs, i % cs] = true;
                        c++;
                    }
                if (c != n)
                    continue;
                for (int i = 0; i < rs; i++)
                    for (int j = 0; j < cs; j++)
                    {
                        if (f[i, j])
                        {
                            if (i > 0 && f[i - 1, j])
                                u++;
                            if (j > 0 && f[i, j - 1])
                                u++;
                        }
                    }
                ans = Math.Min(ans, u);
            }

            writer.WriteLine("Case #{0}: {1}", tt, ans);
        }
    }

    #region Main

    protected static TextReader reader;
    protected static TextWriter writer;

    static void Main()
    {
#if DEBUG
        reader = new StreamReader("..\\..\\input.txt");
        writer = Console.Out;
        writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("game.in");
        //writer = new StreamWriter("game.out");
#endif
        try
        {
            new Solver().Solve();
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            Console.WriteLine(ex);
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write

    private static Queue<string> currentLineTokens = new Queue<string>();

    private static string[] ReadAndSplitLine()
    {
        return reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
    }

    public static string ReadToken()
    {
        while (currentLineTokens.Count == 0)
            currentLineTokens = new Queue<string>(ReadAndSplitLine());
        return currentLineTokens.Dequeue();
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
        return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
    }

    public static int[] ReadIntArray()
    {
        return ReadAndSplitLine().Select(int.Parse).ToArray();
    }

    public static long[] ReadLongArray()
    {
        return ReadAndSplitLine().Select(long.Parse).ToArray();
    }

    public static double[] ReadDoubleArray()
    {
        return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
    }

    public static int[][] ReadIntMatrix(int numberOfRows)
    {
        int[][] matrix = new int[numberOfRows][];
        for (int i = 0; i < numberOfRows; i++)
            matrix[i] = ReadIntArray();
        return matrix;
    }

    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows);
        int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++)
        {
            ret[i] = new int[numberOfRows];
            for (int j = 0; j < numberOfRows; j++)
                ret[i][j] = matrix[j][i];
        }
        return ret;
    }

    public static string[] ReadLines(int quantity)
    {
        string[] lines = new string[quantity];
        for (int i = 0; i < quantity; i++)
            lines[i] = reader.ReadLine().Trim();
        return lines;
    }

    public static void WriteArray<T>(IEnumerable<T> array)
    {
        writer.WriteLine(string.Join(" ", array));
    }

    public static void Write<T>(params T[] array)
    {
        WriteArray(array);
    }

    public static void WriteLines<T>(IEnumerable<T> array)
    {
        foreach (var a in array)
            writer.WriteLine(a);
    }

    #endregion
}