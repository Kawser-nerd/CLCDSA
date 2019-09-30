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
    class Omino
    {
        public int Height, Width;
        public bool[,] F;
        private int hash;

        public Omino(bool[,] f, int n, int m)
        {
            F = f;
            Height = n;
            Width = m;
            int p = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++, p++)
                    if (f[i, j])
                        hash |= 1 << p;
            hash |= n << 12;
            hash |= m << 15;
        }

        public static Omino Norm(bool[,] f, int n, int m)
        {
            int rmin = n, rmax = 0, cmin = m, cmax = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (f[i, j])
                    {
                        rmin = Math.Min(rmin, i);
                        rmax = Math.Max(rmax, i);
                        cmin = Math.Min(cmin, j);
                        cmax = Math.Max(cmax, j);
                    }
            var nf = new bool[rmax - rmin + 1,cmax - cmin + 1];
            for (int i = rmin; i <= rmax; i++)
                for (int j = cmin; j <= cmax; j++)
                    if (f[i, j])
                        nf[i - rmin, j - cmin] = true;
            return new Omino(nf, rmax - rmin + 1, cmax - cmin + 1);
        }

        public IEnumerable<Omino> Generate()
        {
            var ret = new HashSet<Omino>();
            for (int i = 0; i < Height; i++)
                for (int j = 0; j < Width; j++)
                    if (F[i, j])
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni >= 0 && ni < Height && nj >= 0 && nj < Width && F[ni, nj])
                            continue;
                        var nf = new bool[Height + 2, Width + 2];
                        for (int i2 = 0; i2 < Height; i2++)
                            for (int j2 = 0; j2 < Width; j2++)
                                if (F[i2, j2])
                                    nf[i2 + 1, j2 + 1] = true;
                        nf[ni + 1, nj + 1] = true;
                        ret.Add(Norm(nf, Height + 2, Width + 2));
                    }
            return ret;
        }

        public override bool Equals(object obj)
        {
            return hash == obj.GetHashCode();
        }

        public override int GetHashCode()
        {
            return hash;
        }

        public void Print()
        {
            for (int i = 0; i < Height; i++)
            {
                for (int j = 0; j < Width; j++)
                    writer.Write(F[i, j] ? '*' : '.');
                Write();
            }
        }
    }

    private static int[] dr = { 1, 0, -1, 0 };
    private static int[] dc = { 0, -1, 0, 1 };

    int Dfs(bool[,] f, int r, int c, int rs, int cs)
    {
        if (r < 0 || r == rs || c < 0 || c == cs || f[r, c])
            return 0;
        int ret = 1;
        f[r, c] = true;
        for (int i = 0; i < 4; i++)
            ret += Dfs(f, r + dr[i], c + dc[i], rs, cs);
        return ret;
    }

    bool Check(Omino o, int n, int r, int c)
    {
        if (o.Height > r || o.Width > c)
            return false;
        for (int i = 0; i + o.Height <= r; i++)
            for (int j = 0; j + o.Width <= c; j++)
            {
                var f = new bool[r, c];
                for (int ii = 0; ii < o.Height; ii++)
                    for (int jj = 0; jj < o.Width; jj++)
                        if (o.F[ii, jj])
                            f[i + ii, j + jj] = true;
                bool ok = true;
                for (int ii = 0; ok && ii < r; ii++)
                    for (int jj = 0; ok && jj < c; jj++)
                        if (Dfs(f, ii, jj, r, c) % n > 0)
                            ok = false;
                if (ok)
                    return true;
            }
        return false;
    }

    public void Solve()
    {
        var sets = new ISet<Omino>[7];
        sets[1] = new HashSet<Omino> { new Omino(new [,] { {true}}, 1, 1)};
        for (int i = 2; i < 7; i++)
        {
            sets[i] = new HashSet<Omino>();
            foreach (var o in sets[i - 1])
                sets[i].UnionWith(o.Generate());
        }

        int nt = ReadInt();
        for (int tt = 0; tt < nt; tt++)
        {
            int n = ReadInt();
            int rs = ReadInt();
            int cs = ReadInt();
            if (n > Math.Max(rs, cs) || n > 6)
            {
                writer.WriteLine("Case #{0}: RICHARD", tt + 1);
                continue;
            }

            bool ans = true;
            foreach (var o in sets[n])
            {
                if (!Check(o, n, rs, cs) && !Check(o, n, cs, rs))
                {
                    ans = false;
                    break;
                }
            }

            writer.WriteLine("Case #{0}: {1}", tt + 1, ans ? "GABRIEL" : "RICHARD");
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