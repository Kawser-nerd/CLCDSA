using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int L, H, N;
    int[] A;
    void Solve() {
        //input
        L = io.Int;
        H = io.Int;
        N = io.Int;
        A = new int[N];
        for (int i = 0; i < N; ++i)
            A[i] = io.Int;
        //cal       
        for (int i = 0; i < N; ++i) {
            if (A[i] < L)
                Console.WriteLine(L - A[i]);
            else if (H < A[i])
                Console.WriteLine(-1);
            else
                Console.WriteLine(0);
        }
    }

    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() { Solve(); io.writeFlush(); }
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