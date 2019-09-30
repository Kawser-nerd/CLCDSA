using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

public class Solver
{
    private static int c;
    class Trie
    {
        public Trie[] Next = new Trie[26];
        public Trie()
        {
            c++;
        }
    }

    int Build(IEnumerable<string> data)
    {
        c = 0;
        var root = new Trie();
        foreach (string s in data)
        {
            var current = root;
            foreach (char ch in s)
            {
                int x = ch - 'A';
                if (current.Next[x] == null)
                {
                    current.Next[x] = new Trie();
                }
                current = current.Next[x];
            }
        }
        return c;
    }

    public object Solve()
    {
        int m = ReadInt();
        int n = ReadInt();
        var data = ReadLines(m);

        var dict = new Dictionary<int, int>();
        for (int i = 0; i < 1 << m * 2; i++)
        {
            var lists = Enumerable.Repeat(0, n).Select(xx => new List<string>()).ToArray();
            int x = i;
            int j;
            for (j = 0; j < m; j++)
            {
                int y = x % 4;
                if (y >= n)
                    break;
                lists[y].Add(data[j]);
                x >>= 2;
            }
            if (j < m)
                continue;
            if (lists.Any(l => !l.Any()))
                continue;
            int s = 0;
            for (j = 0; j < n; j++)
                s += Build(lists[j]);
            if (!dict.ContainsKey(s))
                dict[s] = 0;
            dict[s]++;
        }

        int max = dict.Keys.Max();
        writer.WriteLine("{0} {1}", max, dict[max]);
        
        return null;
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