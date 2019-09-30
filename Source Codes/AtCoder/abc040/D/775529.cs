using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

public class UnionFind {
    private int[] _par;
    private int[] _rank;
    private int[] _counts; // i ??????????????

    public UnionFind(int size) {
        _par  = new int[size+1];
        _rank = new int[size+1];
        _counts = new int[size+1];
        for (int i = 0; i < _par.Length; i++) {
            _par[i] = i;
            _counts[i] = 1;
        }
    }

    private int Root(int x) {
        if (_par[x] == x)
            return x;
        else {
            _par[x] = Root(_par[x]);
            return _par[x];
        }
    }

    public bool IsSame(int x, int y) {
        return Root(x) == Root(y);
    }

    public void Unite(int x, int y) {
        int rootX = Root(x);
        int rootY = Root(y);
        if (rootX == rootY) return;

        if (_rank[rootX] < _rank[rootY]) {
            _par[rootX] = rootY;
            _counts[rootY] += _counts[rootX];
        }
        else {
            _par[rootY] = rootX;
            _counts[rootX] += _counts[rootY];
            if (_rank[rootX] == _rank[rootY]) {
                _rank[rootX]++;
            }
        }
    }

    public int Count(int x) {
        return _counts[Root(x)];
    }
}

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    struct Edge {
        public int a, b, y;
    }

    struct Query {
        public int v; // ??
        public int w; // w ???????????
        public int index; // ??????????
    }

    static void Main() {
        var nm = ReadInts();
        int n = nm[0], m = nm[1];

        var edges = new List<Edge>();
        for (int i = 0; i < m; i++) {
            var aby = ReadInts();
            edges.Add(new Edge { a = aby[0]-1, b = aby[1]-1, y = aby[2] });
        }

        int q = ReadInt();
        var qs = new List<Query>();
        for (int i = 0; i < q; i++) {
            var vw = ReadInts();
            qs.Add(new Query { v = vw[0]-1, w = vw[1], index = i });
        }

        var uf = new UnionFind(n);
        edges.Sort((a, b) => -a.y.CompareTo(b.y));
        qs.Sort((a, b) => -a.w.CompareTo(b.w));

        int p = 0;
        var ans = new int[qs.Count];
        for (int i = 0; i < qs.Count; i++) {
            int v = qs[i].v; // ??
            int w = qs[i].w; // w ???????????????
            while (p < edges.Count && edges[p].y > w) {
                uf.Unite(edges[p].a, edges[p].b);
                p++;
            }

            ans[qs[i].index] = uf.Count(v);
        }

        var sb = new StringBuilder();
        foreach (var a in ans) {
            sb.AppendLine(a.ToString());
        }
        Console.Write(sb.ToString());
        /*
        Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        for (int i = 0; i < ans.Length; i++) {
            Console.WriteLine(ans[i]);
        }
        Console.Out.Flush();
        */
    }
}