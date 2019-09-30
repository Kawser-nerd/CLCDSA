using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N, K;
    int[] w, p;
    double[] y;
    void Solve() {
        //input
        N = io.Int;
        K = io.Int;
        w = new int[N];
        p = new int[N];
        y = new double[N];
        for(int i = 0; i < N; ++i) {
            w[i] = io.Int;
            p[i] = io.Int;
        }
        //cal
        var lb = 0D;
        var ub = 1e10;
        for(int i = 0; i < 1000; ++i) {
            var mid = (lb + ub) / 2;
            if (check(mid))
                lb = mid;
            else
                ub = mid;
        }
        //ret
        Console.WriteLine(ub);
    }
    bool check(double x) {
        for(int i = 0; i < N; ++i)
            y[i] = (p[i] - x) * w[i];
        return y.OrderByDescending(v => v).Take(K).Sum()>=0;
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() {
        Solve();
        io.writeFlush();
    }
}
class SimpleIO {
    SimpleIO(bool isAutoFlush = false) { this.isAutoFlush = isAutoFlush; }
    string[] nextBuffer;
    int BufferCnt;
    char[] cs = new char[] { ' ' };
    public bool isAutoFlush;
    StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
    public SimpleIO() {
        nextBuffer = new string[0];
        BufferCnt = 0;
        if(!isAutoFlush)
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