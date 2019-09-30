using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using static System.Console;
using static System.Math;
class Simple {
    private int N, a;
    private int k;
    private int[] b;
    void Solve() {
        //input
        N = io.Int;
        a = io.Int - 1;
        var strK = io.String;
        b = new int[N];
        for(int i = 0; i < N; ++i)
            b[i] = io.Int - 1;
        //cal
        var numHash = new HashSet <int>();
        var numList = new List <int>();
        var next = a;
        while(true) {
            if(numHash.Contains(next)) {
                break;
            } else {
                numHash.Add(next);
                numList.Add(next);
                next = b[next];
            }
        }
        var T = numList.IndexOf(next);
        var L = strK.Length;
        var C = numList.Count - T;
        var kModC = 0;
        for(int i = 0; i < L; ++i)
            kModC = (kModC * 10 + (strK[i] - '0')) % C;
        while(kModC < T)
            kModC += C;
        var ans = a;
        if(strK.Length < 9) {
            k = int.Parse(strK);
            for(int i = 0; i < k; ++i) {
                ans = b[ans];
            }
            ans++;
        } else {
            ans = numList[kModC] + 1;
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