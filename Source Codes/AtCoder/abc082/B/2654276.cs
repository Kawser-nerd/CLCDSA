using System;
using System.Collections;
using System.Collections.Generic;
using System.Dynamic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;
using static System.Math;

class Simple {    
    
    void Solve() {
        //input        
        var s = io.String;
        var t = io.String;
        //cal
        var ss = new string(s.ToCharArray().OrderBy(x=>x).ToArray());
        var tt = new string(t.ToCharArray().OrderByDescending(x=>x).ToArray());
        var ans = ss.CompareTo(tt) < 0 ? "Yes" : "No";
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
#if DEBUG
        AutoFlush = true
#else
        AutoFlush = false
#endif
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
        _nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
static class Ex {
    public static void REP(this int n, Action <int> act) {
        for(var i = 0; i < n; ++i) 
            act(i);
    }
}