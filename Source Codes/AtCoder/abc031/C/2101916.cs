using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using static System.Console;
using static System.Math;
class Simple {
    private int N;
    private int[] a;
    void Solve() {
        //input
        N = io.Int;
        a = new int[N];
        for(int i = 0; i < N; ++i)
            a[i] = io.Int;
        //cal
        Func <int, int> f = (select) => {
            //select???????chokudai??????????
            var maxAoki = int.MinValue;
            var maxChokudai = int.MinValue;
            for(int i = 0; i < a.Length; ++i) {
                if(i==select)continue;
                var cnt = 1;
                var sumChokudai = 0;
                var sumAoki = 0;
                var l = Min(select, i);
                var r = Max(select, i);
                for(int j = l; j <= r; ++j) {
                    if(cnt % 2 != 0) {
                        sumChokudai += a[j];
                    } else {
                        sumAoki += a[j];
                    }
                    cnt++;
                }
                if(maxAoki < sumAoki) {
                    //update
                    maxAoki = sumAoki;
                    maxChokudai = sumChokudai;
                }
            }
            return maxChokudai;
        };
        var ans = int.MinValue;
        for(int i = 0; i < a.Length; ++i) {
            ans = Max(ans, f(i));
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