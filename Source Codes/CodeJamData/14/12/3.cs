using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

public class Solver
{
    private int n;
    private IList<int>[] m;

    Tuple<int, int> Fun(int x, int p)
    {
        int ret = 0;
        var list = new List<int>();
        foreach (int s in m[x])
            if (s != p)
            {
                var y = Fun(s, x);
                ret += y.Item1;
                list.Add(y.Item2);
            }

        if (list.Count == 1)
            return Tuple.Create(ret + list[0], 1);
        
        list.Sort();
        int ret2 = 0;
        for (int i = 0; i < list.Count; i++)
            if (i < list.Count - 2)
                ret += list[i];
            else
                ret2 += list[i];
        return Tuple.Create(ret, ret2 + 1);
    }

    public object Solve()
    {
        n = ReadInt();
        m = new IList<int>[n];
        for (int i = 0; i < n; i++)
            m[i] = new List<int>();
        for (int i = 0; i + 1 < n; i++)
        {
            int x = ReadInt() - 1;
            int y = ReadInt() - 1;
            m[x].Add(y);
            m[y].Add(x);
        }

        int ans = int.MaxValue;

        for (int i = 0; i < n; i++)
            ans = Math.Min(ans, Fun(i, -1).Item1);

        return ans;
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