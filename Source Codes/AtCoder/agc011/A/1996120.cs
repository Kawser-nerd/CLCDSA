using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple
{
    int N, C, K;
    int[] T;
    void Solve() {
        //input
        N = io.Int;
        C = io.Int;
        K = io.Int;
        T = new int[N];
        for (int i = 0; i < N; ++i)
            T[i] = io.Int;
        //cal
        Array.Sort(T);
        var time = T[0] + K;
        var mem = 1;
        var ans = 0;
        for (int i = 1; i < N; ++i) {
            if (T[i] <= time && mem++ < C) continue;
            ans++;
            mem = 1;
            time = T[i] + K;
        }
        ans++;
        //ret
        Console.WriteLine(ans);

    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() { Solve(); io.writeFlush(); }
}
class SimpleIO
{
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