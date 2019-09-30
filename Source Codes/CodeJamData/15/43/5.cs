﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    int m;
    List<int> f;
    Dictionary<string, int> idx;

    int Id(string s)
    {
        if (!idx.ContainsKey(s))
        {
            idx[s] = m++;
            f.Add(0);
        }
        return idx[s];
    }

    void Solve()
    {
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            Console.WriteLine(tt);
            int n = ReadInt();
            idx = new Dictionary<string, int>();
            m = 0;
            f = new List<int>();
            foreach (string s in ReadAndSplitLine())
                f[Id(s)] |= 1;
            foreach (string s in ReadAndSplitLine())
                f[Id(s)] |= 2;

            if (n == 2)
            {
                writer.WriteLine("Case #{0}: {1}", tt, f.Count(ff => ff == 3));
                continue;
            }

            var a = new int[n - 2][];
            for (int i = 0; i < n - 2; i++)
                a[i] = ReadAndSplitLine().Select(Id).ToArray();

            int ans = int.MaxValue;
            for (int mask = 0; mask < 1 << n - 2; mask++)
            {
                var ff = f.ToArray();
                for (int i = 0; i < n - 2; i++)
                    foreach (int aa in a[i])
                        if ((mask >> i & 1) == 1)
                            ff[aa] |= 1;
                        else
                            ff[aa] |= 2;
                ans = Math.Min(ans, ff.Count(fx => fx == 3));
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
        //reader = new StreamReader(Console.OpenStandardInput());
        writer = Console.Out;
        writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("hull.in");
        //writer = new StreamWriter("hull.out");
#endif
        try
        {
            //            var thread = new Thread(new Solver().Solve, 1024 * 1024 * 128);
            //            thread.Start();
            //            thread.Join();
            new Solver().Solve();
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex);
#if DEBUG
#else
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write
    private static Queue<string> currentLineTokens = new Queue<string>();
    private static string[] ReadAndSplitLine() { return reader.ReadLine().Split(new[] { ' ', '\t', }, StringSplitOptions.RemoveEmptyEntries); }
    public static string ReadToken() { while (currentLineTokens.Count == 0)currentLineTokens = new Queue<string>(ReadAndSplitLine()); return currentLineTokens.Dequeue(); }
    public static int ReadInt() { return int.Parse(ReadToken()); }
    public static long ReadLong() { return long.Parse(ReadToken()); }
    public static double ReadDouble() { return double.Parse(ReadToken(), CultureInfo.InvariantCulture); }
    public static int[] ReadIntArray() { return ReadAndSplitLine().Select(int.Parse).ToArray(); }
    public static long[] ReadLongArray() { return ReadAndSplitLine().Select(long.Parse).ToArray(); }
    public static double[] ReadDoubleArray() { return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray(); }
    public static int[][] ReadIntMatrix(int numberOfRows) { int[][] matrix = new int[numberOfRows][]; for (int i = 0; i < numberOfRows; i++)matrix[i] = ReadIntArray(); return matrix; }
    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows); int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++) { ret[i] = new int[numberOfRows]; for (int j = 0; j < numberOfRows; j++)ret[i][j] = matrix[j][i]; } return ret;
    }
    public static string[] ReadLines(int quantity) { string[] lines = new string[quantity]; for (int i = 0; i < quantity; i++)lines[i] = reader.ReadLine().Trim(); return lines; }
    public static void WriteArray<T>(IEnumerable<T> array) { writer.WriteLine(string.Join(" ", array)); }
    public static void Write(params object[] array) { WriteArray(array); }
    public static void WriteLines<T>(IEnumerable<T> array) { foreach (var a in array)writer.WriteLine(a); }
    private class SDictionary<TKey, TValue> : Dictionary<TKey, TValue>
    {
        public new TValue this[TKey key]
        {
            get { return ContainsKey(key) ? base[key] : default(TValue); }
            set { base[key] = value; }
        }
    }
    private static T[] Init<T>(int size) where T : new() { var ret = new T[size]; for (int i = 0; i < size; i++)ret[i] = new T(); return ret; }
    #endregion
}