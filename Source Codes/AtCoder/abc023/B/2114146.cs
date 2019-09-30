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
    private string S;
    void Solve() {
        //input
        N = io.Int;
        S = io.String;
        //cal
        var str = "b";
        if(N == 1) {
            if(S == str) {
                WriteLine(0);
                return;
            } else
                goto RET;
        }
        Action f1 = () => str = string.Join("", "a", str, "c");
        Action f2 = () => str = string.Join("", "c", str, "a");
        Action f3 = () => str = string.Join("", "b", str, "b");
        Action <int> f = (a) => {
            var n = a % 3;
            switch(n) {
            case 1:
                f1();
                break;
            case 2:
                f2();
                break;
            case 0:
                f3();
                break;
            }
        };
        var cnt = 0;
        while(str.Length <= S.Length) {
            f(++cnt);
            if(S == str) {
                WriteLine(cnt);
                return;
            }
        }
        RET:
        WriteLine(-1);
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