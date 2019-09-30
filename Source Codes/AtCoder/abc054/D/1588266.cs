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
        var dp = new int[401, 401];
        for (int i = 0; i < dp.GetLength(0); ++i)
            for (int j = 0; j < dp.GetLength(1); ++j)
                dp[i, j] = INF;
        dp[0, 0] = 0;
        for (int i = 0; i < N;++i)
            for (int j = dp.GetLength(0)-1; j >= 0;--j)
                for (int k = dp.GetLength(1) - 1; k >=0;--k)
                    if (dp[j,k]!=INF)
                        dp[j + a[i], k + b[i]] = 
                            Math.Min(dp[j + a[i], k + b[i]], dp[j, k] + c[i]);
        int ans = INF;
        for (int i = 1; i < 401; ++i)
            for (int j = 0; j < 401; ++j)
                if (i * Mb == j * Ma)
                    ans = Math.Min(ans, dp[i, j]);
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