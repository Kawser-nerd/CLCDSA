using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using static System.Console;
using static System.Math;
class Simple {
    private int R, C, K;
    private int N;
    private int[] r, c;
    void Solve() {
        //input
        R = io.Int;
        C = io.Int;
        K = io.Int;
        N = io.Int;
        r = new int[N];
        c = new int[N];
        for(int i = 0; i < N; ++i) {
            r[i] = io.Int - 1;
            c[i] = io.Int - 1;
        }
        //cal
        //??????
        var rCnt = new int[R];
        var cCnt = new int[C];
        for(int i = 0; i < N; ++i) {            
            rCnt[r[i]]++;
            cCnt[c[i]]++;
        }
        //???????
        var cntR = new int[N + 1];
        var cntC = new int[N + 1];
        foreach(var v in rCnt) cntR[v]++;
        foreach(var v in cCnt) cntC[v]++;
                
        var ans = 0L;
        for(int i = 0; i <= K; ++i) ans += cntR[i] * cntC[K - i];
        for(int i = 0; i < N; ++i) {
            if(rCnt[r[i]] + cCnt[c[i]] == K) ans--;
            if(rCnt[r[i]] + cCnt[c[i]] == K + 1) ans++;
        }
        
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