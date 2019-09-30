using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N, Ma, Mb;
    int[] a, b, c;
    const int INF = 1234567890;
    void Solve() {
        //intput
        N = io.Int;
        Ma = io.Int;
        Mb = io.Int;
        a = new int[N];
        b = new int[N];
        c = new int[N];
        for (int i = 0; i < N; ++i) {
            a[i] = io.Int;
            b[i] = io.Int;
            c[i] = io.Int;
        }
        //cal
        var dp = new int[50, 500, 500];
        for (int i = 0; i < dp.GetLength(0); ++i)
            for (int j = 0; j < dp.GetLength(1); ++j)
                for (int k = 0; k < dp.GetLength(2); ++k)
                    dp[i, j, k] = INF;
        dp[0, 0, 0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < (N+1)*10+1; ++j)
                for (int k = 0; k < (N+1)*10+1; ++k) {
                    if (dp[i, j, k] == INF) continue;
                    //???
                    dp[i + 1, j + a[i], k + b[i]] =
                        Math.Min(dp[i + 1, j + a[i], k + b[i]], dp[i, j, k] + c[i]);
                    //????
                    dp[i + 1, j, k] = Math.Min(dp[i + 1, j, k], dp[i, j, k]);
                }
        int ans = INF;
        for (int j = 1; j < dp.GetLength(1); ++j)
            for (int k = 1; k < dp.GetLength(2); ++k)
                if (j * Mb == k * Ma)
                    ans = Math.Min(ans, dp[N, j, k]);
        //res
        Console.WriteLine(ans == INF ? -1 : ans);
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