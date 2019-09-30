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
    int[,] z = new int[,]
    {
        { '1', 'i', 'j', 'k' },
        { 'i', -'1', 'k', -'j' },
        { 'j', -'k', -'1', 'i' },
        { 'k', 'j', -'i', -'1' }
    };

    int Fun(int a, int b)
    {
        int sign = 1;
        if (a < 0)
        {
            sign *= -1;
            a = -a;
        }
        if (b < 0)
        {
            sign *= -1;
            b = -b;
        }
        
        return z["1ijk".IndexOf((char)a), "1ijk".IndexOf((char)b)] * sign;
    }

    bool Go(int n, long m, int[] a)
    {
        int o = 0;
        int p = 0;
        int y = '1';
        while (o < 8)
        {
            y = Fun(y, a[p]);
            if (++p == n)
            {
                o++;
                p = 0;
            }
            if (y == 'i')
                break;
        }
        if (y != 'i')
            return false;

        y = '1';
        while (o < 16)
        {
            y = Fun(y, a[p]);
            if (++p == n)
            {
                o++;
                p = 0;
            }
            if (y == 'j')
                break;
        }
        if (y != 'j' || o >= m)
            return false;

        y = '1';
        while (p < n)
        {
            y = Fun(y, a[p]);
            p++;
        }

        if (++o == m)
            return y == 'k';

        int v = a.Aggregate((int)'1', Fun);
        var dict = new Dictionary<int, int>();
        int x = '1';
        int c = 0;
        for (; ; c++)
        {
            if (dict.ContainsKey(x))
                break;
            dict[x] = c;
            x = Fun(x, v);
        }

        for (int i = 0; i < dict[x] && o < m; i++, o++)
            y = Fun(y, v);

        long r = (m - o) % (c - dict[x]);
        for (; r > 0; r--)
            y = Fun(y, v);

        return y == 'k';
    }

    public void Solve()
    {
        int nt = ReadInt();
        for (int tt = 0; tt < nt; tt++)
        {
            int n = ReadInt();
            long m = ReadLong();
            var a = ReadToken().Select(ch => (int)ch).ToArray();

            writer.WriteLine("Case #{0}: {1}", tt + 1, Go(n, m, a) ? "YES" : "NO");
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
        //reader = new StreamReader("cycle.in");
        //writer = new StreamWriter("cycle.out");
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
    private static string[] ReadAndSplitLine() {return reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);}
    public static string ReadToken(){while (currentLineTokens.Count == 0)currentLineTokens = new Queue<string>(ReadAndSplitLine());return currentLineTokens.Dequeue();}
    public static int ReadInt(){return int.Parse(ReadToken());}
    public static long ReadLong(){return long.Parse(ReadToken());}
    public static double ReadDouble(){return double.Parse(ReadToken(), CultureInfo.InvariantCulture);}
    public static int[] ReadIntArray(){return ReadAndSplitLine().Select(int.Parse).ToArray();}
    public static long[] ReadLongArray(){return ReadAndSplitLine().Select(long.Parse).ToArray();}
    public static double[] ReadDoubleArray(){return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();}
    public static int[][] ReadIntMatrix(int numberOfRows){int[][] matrix = new int[numberOfRows][];for (int i = 0; i < numberOfRows; i++)matrix[i] = ReadIntArray();return matrix;}
    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows){int[][] matrix = ReadIntMatrix(numberOfRows);int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++){ret[i] = new int[numberOfRows];for (int j = 0; j < numberOfRows; j++)ret[i][j] = matrix[j][i];}return ret;}
    public static string[] ReadLines(int quantity){string[] lines = new string[quantity];for (int i = 0; i < quantity; i++)lines[i] = reader.ReadLine().Trim();return lines;}
    public static void WriteArray<T>(IEnumerable<T> array){writer.WriteLine(string.Join(" ", array));}
    public static void Write(params object[] array){WriteArray(array);}
    public static void WriteLines<T>(IEnumerable<T> array){foreach (var a in array)writer.WriteLine(a);}
    private class SDictionary<TKey, TValue> : Dictionary<TKey, TValue>{public new TValue this[TKey key]{
        get { return ContainsKey(key) ? base[key] : default(TValue); }set { base[key] = value; }}}
    private static T[] Init<T>(int size) where T : new(){var ret = new T[size];for (int i = 0; i < size; i++)ret[i] = new T();return ret;}
    #endregion
}