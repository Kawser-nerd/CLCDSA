using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        //Test();
        int N = Reader.Int();
        int M = Reader.Int();
        var E = Reader.IntTable(M);
        int NQ = Reader.Int();
        var Q = Reader.IntTable(NQ);
        foreach (var e in E) { e[0]--; e[1]--; }
        foreach (var q in Q) { q[0]--; q[1]--; }
        UnionFind uf = null;
        Action init = () => uf = new UnionFind(N);
        Action<int> act = i => uf.Unite(E[i][0], E[i][1]);
        Predicate<int> ok = i => Q[i][2] <= uf.Count(Q[i][0]) + (uf.Same(Q[i][0], Q[i][1]) ? 0 : uf.Count(Q[i][1]));
        var ans = BinarySearch(NQ, 0, M, init, act, ok);
        Console.WriteLine(string.Join("\n", ans));
    }

    //void Test()
    //{
    //    var random = new Random(0);
    //    for (int ite = 1; ; ite++)
    //    {
    //        if (ite % (int)1e0 == 0) Console.WriteLine("iterations:" + ite);
    //        int N = random.Next(1, 100);
    //        var E = RandomCaseGenerator.TreeEdges(N);
    //        int NQ = random.Next(1, 100);
    //        int[][] Q = new int[NQ][];
    //        for (int i = 0; i < NQ; i++)
    //            Q[i] = new[] { random.Next(N), random.Next(N), random.Next(1, N + 1) };
    //        UnionFind uf = null;
    //        Action init = () => uf = new UnionFind(N);
    //        Action<int> act = i => uf.Unite(E[i][0], E[i][1]);
    //        Predicate<int> ok = i => Q[i][2] <= uf.Count(Q[i][0]) + (uf.Same(Q[i][0], Q[i][1]) ? 0 : uf.Count(Q[i][1]));

    //        var naive = Naive(N, E, Q);
    //        var ans = BinarySearch(NQ, 0, E.Length, init, act, ok);
    //        if (!naive.SequenceEqual(ans))
    //        {
    //            Console.WriteLine(N);
    //            Console.WriteLine(string.Join("\n", E.Select(e => string.Join(" ", e))));
    //            Console.WriteLine("Q:");
    //            Console.WriteLine(string.Join("\n", Q.Select(e => string.Join(" ", e))));
    //            Console.WriteLine("naive:" + string.Join(" ", naive));
    //            Console.WriteLine("ans  :" + string.Join(" ", ans));
    //        }
    //    }
    //}

    //int[] Naive(int N, int[][] E, int[][] Q)
    //{
    //    var ans = new int[Q.Length];
    //    for (int i = 0; i < Q.Length; i++)
    //    {
    //        int L = -1, R = E.Length;
    //        for (; R - L > 1; )
    //        {
    //            int mid = L + R >> 1;
    //            if (Can(mid, N, E, Q[i][0], Q[i][1], Q[i][2])) R = mid;
    //            else L = mid;
    //        }
    //        ans[i] = R;
    //    }
    //    return ans;
    //}

    //private bool Can(int max, int N, int[][] E, int x, int y, int K)
    //{
    //    var uf = new UnionFind(N);
    //    for (int i = 0; i < max; i++)
    //        uf.Unite(E[i][0], E[i][1]);
    //    int num = uf.Count(x) + (uf.Same(x, y) ? 0 : uf.Count(y));
    //    return num >= K;
    //}



    // [L, R)
    int[] BinarySearch(int N, int L, int R, Action Init, Action<int> Act, Predicate<int> OK)
    {
        var res = new int[N];
        Queue<int> q = new Queue<int>(), nq;
        int[] A = new int[N * 2], B = new int[N * 2], tmp;
        for (int i = 0; i < N; i++) A[i] = i;
        q.Enqueue(L); q.Enqueue(R); q.Enqueue(0); q.Enqueue(N);

        for (; q.Count > 0; q = nq, tmp = A, A = B, B = tmp)
        {
            Init();
            nq = new Queue<int>();
            for (int ni = 0; q.Count > 0; )
            {
                L = q.Dequeue(); R = q.Dequeue(); int mid = L + R >> 1;
                int start = q.Dequeue(), num = q.Dequeue(), end = start + num;
                if (R - L <= 1)
                {
                    for (int i = start; i < end; i++) res[A[i]] = OK(A[i]) ? L : R;
                    if (L < R) Act(L);
                    continue;
                }
                for (int i = L; i < mid; i++) Act(i);
                int numL = 0, numR = 0;
                for (int i = start; i < end; i++)
                    if (OK(A[i])) B[ni + numL++] = A[i];
                    else B[ni + num + numR++] = A[i];
                Array.Copy(B, ni + num, B, ni + numL, numR);
                for (int i = mid; i < R; i++) Act(i);
                nq.Enqueue(L); nq.Enqueue(mid); nq.Enqueue(ni); nq.Enqueue(numL);
                nq.Enqueue(mid); nq.Enqueue(R); nq.Enqueue(ni + numL); nq.Enqueue(num - numL);
                ni += num;
            }
        }

        return res;
    }
}

class UnionFind
{
    private int[] parent;
    private byte[] rank;

    public UnionFind(int N)
    {
        parent = new int[N];
        rank = new byte[N];
        for (int i = 0; i < N; i++) parent[i] = -1;
    }
    public int Root(int x)
    {
        if (parent[x] < 0) return x;
        return parent[x] = Root(parent[x]);
    }
    public bool Same(int x, int y)
    {
        return Root(x) == Root(y);
    }
    public int Count(int x)
    {
        return -parent[Root(x)];
    }
    public bool Unite(int x, int y)
    {
        x = Root(x); y = Root(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) { var t = x; x = y; y = t; }
        if (rank[x] == rank[y]) rank[y]++;
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }
    public Dictionary<int, List<int>> Components()
    {
        var dic = new Dictionary<int, List<int>>();
        for (int i = 0; i < parent.Length; i++)
        {
            int root = Root(i);
            if (!dic.ContainsKey(root)) dic[root] = new List<int>();
            dic[root].Add(i);
        }
        return dic;
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
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
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