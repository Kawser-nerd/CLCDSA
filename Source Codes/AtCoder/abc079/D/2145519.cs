using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using static System.Console;
using static System.Math;
class Simple
{
    int H, W;
    int[,] c,A;
    void Solve() {
        //input
        H = io.Int;
        W = io.Int;
        c = new int[10, 10];
        A = new int[H, W];
        for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            c[i, j] = io.Int;
        for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            A[i, j] = io.Int;
        //cal
        var wf = new WarshallFloyd(10,false);
        for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            wf.AddPath(i, j, c[i, j]);
        wf.Run();
        var ans = 0L;
        for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (A[i, j] != -1) ans += wf.MinCost(A[i, j], 1);
        //ret
        WriteLine(ans);
    }

    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) => new Simple().Stream();
    private void Stream() {
        //var exStdIn = new System.IO.StreamReader("stdin.txt");
        //SetIn(exStdIn);
        Solve();
        io.Flush();
    }
}
class WarshallFloyd
{
    bool    IsNonDir;
    int     VertexNum;
    int     EdgeNum;
    long    INF;
    long[,] G;
    public WarshallFloyd(int n, bool isNondir = true,long inf = long.MaxValue/2) {
        IsNonDir = isNondir;
        INF      = inf;
        Init(n);
    }
    public void Init(int n) {
        VertexNum = n;
        G = new long[VertexNum + 1, VertexNum + 1];
        for (int i = 0; i < VertexNum + 1; ++i)
        for (int j = 0; j < VertexNum + 1; ++j)
            G[i, j] = INF;
    }
    public void AddPath(int f, int t, long c = 1) {
        EdgeNum++;
        G[f, t] = Math.Min(G[f, t], c);
        if (IsNonDir) G[t, f] = Math.Min(G[t, f], c);
    }
    public virtual void AddPath(int[] f, int[] t) {
        for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i]);
    }
    public virtual void AddPath(int[] f, int[] t, long[] c) {
        for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]);
    }
    public void Run() {
        for (int i = 0; i < VertexNum + 1; ++i)
        for (int j = 0; j < VertexNum + 1; ++j)
        for (int k = 0; k < VertexNum + 1; ++k)
            G[j, k] = Math.Min(G[j, k], G[j, i] + G[i, k]);
    }
    public long MinCost(int f, int t) => G[f, t];
}
class SimpleIO
{
    string[] _nextBuffer;
    int _bufferCnt;
    char[] cs = new char[] { ' ', '"', ',' };
    StreamWriter sw = new StreamWriter(OpenStandardOutput()) {
        AutoFlush = false
    };
    public SimpleIO() {
        _nextBuffer = new string[0];
        _bufferCnt = 0;
        SetOut(sw);
    }
    string Next() {
        if (_bufferCnt < _nextBuffer.Length)
            return _nextBuffer[_bufferCnt++];
        var st = ReadLine();
        while (st == "")
            st = ReadLine();
        if (st != null)
            _nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        else
            st = "";
        _bufferCnt = 0;
        return _nextBuffer[_bufferCnt++];
    }
    public string String => Next();
    public char Char => char.Parse(String);
    public int Int => int.Parse(String);
    public long Long => long.Parse(String);
    public double Double => double.Parse(String);
    public void Flush() => Out.Flush();
}