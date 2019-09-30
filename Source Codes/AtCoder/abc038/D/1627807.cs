using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N;
    //int w,h
    const int INF = (int)1e9;
    void Solve() {
        //input
        N = io.Int;
        var wh = new Tuple<int, int>[N];
        for(int i = 0; i < N; ++i) {
            var w = io.Int;
            var h = io.Int;
            wh[i] = Tuple.Create(w, h);
        }
        //cal
        wh = wh.OrderBy(t => t.Item1).ThenByDescending(t => t.Item2).ToArray();
        var arr = new int[N + 1];
        for (int i = 0; i < arr.Length; ++i)
            arr[i] = INF;
        for(int i = 0; i < N; ++i) 
            arr[LowerBound(arr, wh[i].Item2)] = wh[i].Item2;
        //ret
        Console.WriteLine(LowerBound(arr, INF));
    }

    int LowerBound(int[] arr,int val) {
        var lb = -1;
        var ub = arr.Length;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (arr[mid] >= val)
                ub = mid;
            else
                lb = mid;
        }
        return ub;
    }

    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() {
        Solve();
        io.writeFlush();
    }
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