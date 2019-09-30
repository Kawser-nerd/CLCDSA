using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N, M;
    int[] x, y;
    void Solve() {
        //input
        N = io.Int;
        M = io.Int;
        x = new int[M];
        y = new int[M];
        for (int i = 0; i < M; ++i) {
            x[i] = io.Int;
            y[i] = io.Int;
        }
        //cal
        long[] dp = new long[1 << N];
        int[] path = new int[N];
        for (int i = 0; i < M; ++i)
            path[y[i] - 1] |= 1 << x[i] - 1;
        dp[0] = 1;
        for (int i = 0; i < 1 << N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (((1 << j) & i) == 0 && (i & path[j]) == 0)
                    dp[i | 1 << j] += dp[i];
            }
        }
        //ret
        Console.WriteLine(dp[(1 << N) - 1]);
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