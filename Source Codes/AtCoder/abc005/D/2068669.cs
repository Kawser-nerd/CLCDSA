using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Console;
using static System.Math;
class Simple {
    private int N, Q;
    private int[,] D;
    private int[] P;
    void Solve() {
        //input
        N = io.Int;
        D = new int[N, N];
        for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) 
            D[i, j] = io.Int;                    
        Q = io.Int;
        P = new int[Q];
        for(int i = 0; i < Q; ++i) 
            P[i] = io.Int;   
        //cal
        var resList = slide(D);
        //ret
        foreach(var v in P) 
            WriteLine(resList[v]);
        
    }
    int[] slide(int[,] m) {
        var acc = new int[m.GetLength(0) + 1, m.GetLength(1) + 1];
        //shift and copy
        for(int i=1;i<acc.GetLength(0);++i)for(int j = 1; j < acc.GetLength(1); ++j)
            acc[i, j] = m[i - 1, j - 1];
        // cal acc            
        for(int i = 1; i < acc.GetLength(0); ++i) acc[i, 0] += acc[i - 1, 0];
        for(int j = 1; j < acc.GetLength(1); ++j) acc[0, j] += acc[0, j - 1];
        for(int i = 1; i < acc.GetLength(0); ++i)for(int j = 1; j < acc.GetLength(1); ++j)
            acc[i, j] = acc[i, j] + acc[i - 1, j] + acc[i, j - 1] - acc[i - 1, j - 1];        
        // t
        //l r
        // b
        var res = new int[m.GetLength(0) * m.GetLength(1) + 1];                
        for(int b = 1; b < acc.GetLength(0); ++b) for(int t = 0; t < b; ++t)
            for(int r = 1; r < acc.GetLength(1); ++r)for(int l = 0; l < r; ++l) {
                var h =  b - t ;
                var w =  r - l ;
                var tmp = acc[b, r] - acc[t, r] - acc[b, l] + acc[t, l];
                res[h * w] = Max(res[h * w], tmp);
            }
        for(int i = 1; i < res.Length; ++i) res[i] = Max(res[i], res[i - 1]);        
        return res;
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
class SimpleIO {
    string[] _nextBuffer;
    int _bufferCnt;
    char[] cs = new char[] {' ', '"', ','};
    StreamWriter sw = new StreamWriter(OpenStandardOutput()) {
        AutoFlush = false
    };
    public SimpleIO() {
        _nextBuffer = new string[0];
        _bufferCnt = 0;
        SetOut(sw);
    }
    string Next() {
        if(_bufferCnt < _nextBuffer.Length)
            return _nextBuffer[_bufferCnt++];
        var st = ReadLine();
        while(st == "")
            st = ReadLine();
        if(st != null)
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