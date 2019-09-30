using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

class Program
{
    int N;
    int[][] A, B;
    int[] Bfirst;

    public void Solve()
    {
        N = Reader.Int();
        int NA = Reader.Int();
        A = Reader.IntTable(NA).Select(r => new[] { --r[0], --r[1] }).ToArray();
        int NB = Reader.Int();
        B = Reader.IntTable(NB).Select(r => new[] { --r[0], --r[1] }).ToArray();
        int ans = 0;
        Bfirst = B.Select(b => b[0]).Distinct().ToArray();

        for (int mask = 0; mask < (1 << Bfirst.Length); mask++)
        {
            bool[] bad;
            HashSet<int>[] parents;
            List<int>[] children;
            GenGraph(mask, out bad, out parents, out children);
            ans = Math.Max(ans, Calc(bad, parents, children));
        }

        Console.WriteLine(ans);
    }

    private void GenGraph(int mask, out bool[] bad, out HashSet<int>[] parents, out List<int>[] children)
    {
        bad = new bool[N];
        for (int i = 0; i < Bfirst.Length; i++)
            if ((mask >> i & 1) == 1)
                bad[Bfirst[i]] = true;
        parents = new HashSet<int>[N];
        children = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            parents[i] = new HashSet<int>();
            children[i] = new List<int>();
        }
        foreach (var a in A)
        {
            parents[a[0]].Add(a[1]);
            children[a[1]].Add(a[0]);
        }
        foreach (var b in B)
            if (!bad[b[0]])
            {
                parents[b[1]].Add(b[0]);
                children[b[0]].Add(b[1]);
            }
    }

    private int Calc(bool[] bad, HashSet<int>[] parents, List<int>[] children)
    {
        int res = 0;
        var que = new Queue<int>();
        for (int i = 0; i < N; i++)
            if (!bad[i] && parents[i].Count == 0)
            {
                res++;
                que.Enqueue(i);
            }
        while (que.Count > 0)
        {
            int who = que.Dequeue();
            foreach (int child in children[who])
                if (!bad[child] && parents[child].Remove(who) && parents[child].Count == 0)
                {
                    res++;
                    que.Enqueue(child);
                }
        }

        return res;
    }


}

class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    private static TextReader reader = Console.In;
    private static readonly char[] separator = { ' ' };
    private static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    private static string[] A = new string[0];
    private static int i;
    private static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Enu.Range(0, N).Select(i => Int()).ToArray(); }
    public static int[][] IntTable(int H) { return Enu.Range(0, H).Select(i => IntLine()).ToArray(); }
    public static string[] StringArray(int N) { return Enu.Range(0, N).Select(i => Next()).ToArray(); }
    public static string Line() { return reader.ReadLine().Trim(); }
    private static string[] Split(string s) { return s.Split(separator, op); }
    private static string Next() { CheckNext(); return A[i++]; }
    private static bool CheckNext()
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