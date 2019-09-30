﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    int m;
    int[,,,] mem;
    int Fun(int[] a, int p)
    {
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
            return 0;
        if (mem[a[0], a[1], a[2], a[3]] != -1)
            return mem[a[0], a[1], a[2], a[3]];

        int ret = 0;
        for (int i = 0; i < m; i++)
            if (a[i] > 0)
            {
                a[i]--;
                ret = Math.Max(ret, Fun(a, (p + m - i) % m));
                a[i]++;
            }

        return mem[a[0], a[1], a[2], a[3]] = ret + (p > 0 ? 0 : 1);
    }

    public void Solve()
    {
        int nt = ReadInt();
        for (int tt = 1; tt <= nt; tt++)
        {
            int n = ReadInt();
            m = ReadInt();

            var a = new int[4];
            for (; n > 0; n--)
                a[ReadInt() % m]++;

            mem = new int[a[0] + 1, a[1] + 1, a[2] + 1, a[3] + 1];
            for (int i = 0; i <= a[0]; i++)
                for (int j = 0; j <= a[1]; j++)
                    for (int k = 0; k <= a[2]; k++)
                        for (int l = 0; l <= a[3]; l++)
                            mem[i, j, k, l] = -1;

            Console.WriteLine(tt);
            writer.WriteLine("Case #{0}: {1}", tt, Fun(a, 0));
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
        //reader = new StreamReader("input.txt");
        //writer = new StreamWriter("output.txt");
#endif
        try
        {
            new Solver().Solve();
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 256);
            //thread.Start();
            //thread.Join();
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
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

