using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int N = Reader.Int(), M = Reader.Int();
        var E = Reader.IntTable(M);
        int NQ = Reader.Int();
        var Q = Reader.IntTable(NQ);
        var uf = new PersistentPartialUnionFind(N);
        Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });

        foreach (var e in E)
            uf.Unite(--e[0], --e[1]);
        foreach (var q in Q)
            Console.WriteLine(BinSearch(--q[0], --q[1], q[2], M, uf));

        Console.Out.Flush();
    }

    private int BinSearch(int a, int b, int need, int M, PersistentPartialUnionFind uf)
    {
        int L = -1, R = M;
        while (R - L > 1)
        {
            int mid = L + R >> 1;
            int num = uf.NumElements(a, mid) + (uf.Same(a, b, mid) ? 0 : uf.NumElements(b, mid));
            if (num >= need) R = mid;
            else L = mid;
        }
        return R;
    }

    public class PersistentPartialUnionFind
    {
        public int CurrentTime { get; private set; }
        int[] Parent, LastTime, Size;
        List<Edge>[] E;

        public PersistentPartialUnionFind(int N)
        {
            Parent = new int[N];
            LastTime = new int[N];
            Size = new int[N];
            E = new List<Edge>[N];
            for (int i = 0; i < N; i++)
            {
                Parent[i] = i;
                Size[i] = 1;
                E[i] = new List<Edge>();
            }
        }

        public bool Unite(int a, int b)
        {
            a = Root(a, CurrentTime);
            b = Root(b, CurrentTime);
            ++CurrentTime;
            if (a == b) return false;
            if (Size[a] < Size[b]) { int t = a; a = b; b = t; }
            E[a].Add(new Edge(CurrentTime, Size[a] + Size[b]));
            Size[a] += Size[b];
            Parent[b] = a;
            LastTime[b] = CurrentTime;
            return false;
        }

        public int Root(int a, int time)
        {
            while (Parent[a] != a && LastTime[a] <= time) a = Parent[a];
            return a;
        }
        public bool Same(int a, int b, int time)
        {
            return Root(a, time) == Root(b, time);
        }

        public int NumElements(int a, int time)
        {
            a = Root(a, time);
            if (E[a].Count == 0) return Size[a];
            int L = -1, R = E[a].Count;
            while (R - L > 1)
            {
                int mid = L + R >> 1;
                if (E[a][mid].Time <= time) L = mid;
                else R = mid;
            }
            return L == -1 ? 1 : E[a][L].Size;
        }

        public struct Edge
        {
            public int Time, Size;
            public Edge(int time, int size) { Time = time; Size = size; }
        }
    }

}

class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}