using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N, Q;
    int[] L, R, T;
    void Solve() {
        //input
        N = io.Int;
        Q = io.Int;
        L = new int[Q];
        R = new int[Q];
        T = new int[Q];
        for(int i = 0; i < Q; ++i) {
            L[i] = io.Int;
            R[i] = io.Int;
            T[i] = io.Int;
        }
        //cal
        var arr = new int[N];
        for(int i = 0; i < Q; ++i) {
            for(int j = L[i] - 1; j < R[i]; ++j) {
                arr[j] = T[i];
            }
        }
        //ret
        for (int i = 0; i < N; ++i)
            Console.WriteLine(arr[i]);
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