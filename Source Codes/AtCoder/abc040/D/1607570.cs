using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N, M;
    Tuple<int, int, int>[] aby;
    int Q;
    Tuple<int, int, int>[] vw;
    void Solve() {
        //input
        N = io.Int;
        M = io.Int;
        aby = new Tuple<int, int, int>[M];
        for (int i = 0; i < M; ++i) {
            int a = io.Int;
            int b = io.Int;
            int y = io.Int;
            aby[i] = Tuple.Create(a, b, y);
        }
        Q = io.Int;
        vw = new Tuple<int, int, int>[Q];
        for (int i = 0; i < Q; ++i) {
            int v = io.Int;
            int w = io.Int;
            vw[i] = Tuple.Create(v, w, i);
        }
        //cal
        var index = 0;
        var ans = new int[Q];
        var uf = new UnionFind();
        uf.Init(N);
        aby = aby.OrderByDescending(t => t.Item3).ToArray();
        vw = vw.OrderByDescending(t => t.Item2).ToArray();
        for (int i = 0; i < M;++i){
            while(index<Q&&vw[index].Item2>=aby[i].Item3){
                ans[vw[index].Item3] = uf.Size(vw[index].Item1);
                index++;
            }
            uf.Unite(aby[i].Item1,aby[i].Item2);
        }
        while(index<Q){            
            ans[vw[index].Item3] = uf.Size(vw[index].Item1);
            index++;
        }
        //ret
        foreach (var v in ans)
            Console.WriteLine(v);
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() {
        Solve();
        io.writeFlush();
    }
}
class UnionFind {
    int[] dat;
    public void Init(int n) {
        dat = new int[n + 1];
        for (int i = 0; i <= n; ++i)
            dat[i] = -1;
    }
    public void Unite(int x, int y) {
        x = Root(x); y = Root(y);
        if (x == y) return;
        if (dat[y] < dat[x]) swap(ref x, ref y);
        dat[x] += dat[y];
        dat[y] = x;
    }
    public bool Find(int x, int y) { return Root(x) == Root(y); }
    public int Root(int x) { return dat[x] < 0 ? x : dat[x] = Root(dat[x]); }
    public int Size(int x) { return -dat[Root(x)]; }
    void swap(ref int a, ref int b) { int tmp = b; b = a; a = tmp; }
}
class SimpleIO {
    string[] nextBuffer;
    int BufferCnt;
    char[] cs = new char[] { ' ' };
    StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    public SimpleIO() {
        nextBuffer = new string[0];
        BufferCnt = 0;
        Console.SetOut(sw);
    }
    public string Next() {
        if (BufferCnt < nextBuffer.Length)
            return nextBuffer[BufferCnt++];
        string st = Console.ReadLine();
        while (st == "")
            st = Console.ReadLine();
        nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        BufferCnt = 0;
        return nextBuffer[BufferCnt++];
    }
    public string String => Next();
    public char Char => char.Parse(String);
    public int Int => int.Parse(String);
    public long Long => long.Parse(String);
    public double Double => double.Parse(String);
    public void writeFlush() { Console.Out.Flush(); }
}