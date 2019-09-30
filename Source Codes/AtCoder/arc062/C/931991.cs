using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (?°?°)??e??????????????????????????
public class Solver
{
    long Fun(int a, int b, int c, int d)
    {
        return Math.Min(Math.Min(1000000000L * a + 1000000 * b + 1000 * c + d, 1000000000L * b + 1000000 * c + 1000 * d + a),
            Math.Min(1000000000L * c + 1000000 * d + 1000 * a + b, 1000000000L * d + 1000000 * a + 1000 * b + c));
    }

    public void Solve()
    {
        int n = ReadInt();
        var a = ReadIntMatrix(n);

        //n = 400;
        //a = new int[n][];
        //for (int i = 0; i < n; i++)
        //    a[i] = new int[4];

        var idx = a.Select(aa => Fun(aa[0], aa[1], aa[2], aa[3])).Distinct().ToArray();
        Array.Sort(idx);
        var b = a.Select(aa => Array.BinarySearch(idx, Fun(aa[0], aa[1], aa[2], aa[3]))).ToArray();

        int m = idx.Length;
        var cnt = new int[m];
        for (int i = n - 5; i < n; i++)
            cnt[b[i]]++;

        long ans = 0;
        Action<List<int[]>, int, int> add = (list, v1, v2) => 
        {
            int size = list.Count;
            if (size > 0 && list[size - 1][0] == v1 && list[size - 1][1] == v2)
                list[size - 1][2]++;
            else
                list.Add(new [] { v1, v2, 1 });
        };
        for (int i = n - 6; i >= 0; i--)
        {
            Func<int, int, int, int, long> fun = (t1, t2, b1, b2) =>
            {
                int back = Array.BinarySearch(idx, Fun(t2, t1, b2, b1));
                if (back < 0)
                    return 0L;
                int right = Array.BinarySearch(idx, Fun(a[i][1], t2, b1, a[i][2]));
                if (right < 0)
                    return 0L;
                int left = Array.BinarySearch(idx, Fun(t1, a[i][0], a[i][3], b2));
                if (left < 0)
                    return 0L;
                long ret;
                if (left == right)
                {
                    if (left == back)
                        ret = 1L * cnt[left] * (cnt[left] - 1) * (cnt[left] - 2);
                    else
                        ret = 1L * cnt[left] * (cnt[left] - 1) * cnt[back];
                }
                else
                {
                    if (left == back)
                        ret = 1L * cnt[left] * (cnt[left] - 1) * cnt[right];
                    else if (right == back)
                        ret = 1L * cnt[right] * (cnt[right] - 1) * cnt[left];
                    else
                        ret = 1L * cnt[left] * cnt[right] * cnt[back];
                }
                if (t2 == b2 && t1 == b1)
                {
                    if (t2 == t1)
                        ret *= 4;
                    else
                        ret *= 2;
                }
                if (a[i][1] == b1 && t2 == a[i][2])
                {
                    if (b1 == t2)
                        ret *= 4;
                    else
                        ret *= 2;
                }
                if (t1 == a[i][3] && a[i][0] == b2)
                {
                    if (t1 == b2)
                        ret *= 4;
                    else
                        ret *= 2;
                }
                return ret;
            };

            for (int j = i + 1; j < n; j++)
            {
                var to = new List<int[]>();
                if (a[i][0] == a[j][1] && a[i][1] == a[j][0])
                    add(to, a[j][2], a[j][3]);
                if (a[i][0] == a[j][2] && a[i][1] == a[j][1])
                    add(to, a[j][3], a[j][0]);
                if (a[i][0] == a[j][3] && a[i][1] == a[j][2])
                    add(to, a[j][0], a[j][1]);
                if (a[i][0] == a[j][0] && a[i][1] == a[j][3])
                    add(to, a[j][1], a[j][2]);
                if (to.Count > 0)
                {
                    cnt[b[j]]--;
                    for (int k = i + 1; k < n; k++)
                        if (j != k)
                        {
                            cnt[b[k]]--;
                            if (a[i][2] == a[i][3] && a[k][0] == a[i][2] && a[k][0] == a[k][1] && a[k][0] == a[k][2] && a[k][0] == a[k][3])
                            {
                                foreach (var t in to)
                                    ans += 4 * t[2] * fun(t[0], t[1], a[i][2], a[i][2]);
                            }
                            else
                            {
                                if (a[i][3] == a[k][0] && a[i][2] == a[k][1])
                                    foreach (var t in to)
                                        ans += t[2] * fun(t[0], t[1], a[k][2], a[k][3]);
                                if (a[i][3] == a[k][1] && a[i][2] == a[k][2])
                                    foreach (var t in to)
                                        ans += t[2] * fun(t[0], t[1], a[k][3], a[k][0]);
                                if (a[i][3] == a[k][2] && a[i][2] == a[k][3])
                                    foreach (var t in to)
                                        ans += t[2] * fun(t[0], t[1], a[k][0], a[k][1]);
                                if (a[i][3] == a[k][3] && a[i][2] == a[k][0])
                                    foreach (var t in to)
                                        ans += t[2] * fun(t[0], t[1], a[k][1], a[k][2]);
                            }
                            cnt[b[k]]++;
                        }
                    cnt[b[j]]++;
                }
            }

            cnt[b[i]]++;
        }

        Write(ans);
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
        //writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("input.txt");
        //writer = new StreamWriter("output.txt");
#endif
        try
        {
            new Solver().Solve();
            //var thread = new Thread(new Solver().Solve, 1024 * 1024 * 128);
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