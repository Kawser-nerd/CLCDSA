using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int H, W;
    int[,] A;
    long[,] dp;
    int[] dir = { 0, 1, 0, -1, 0 };
    const int MOD = (int)1e9 + 7;
    void Solve() {
        //input
        H = io.Int;
        W = io.Int;
        A = new int[H, W];
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                A[i, j] = io.Int;
        //cal
        dp = new long[H, W];
        long ans = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                ans = (ans + dfs(i, j)) % MOD;
        //ret
        Console.WriteLine(ans);
    }
    long dfs(int y, int x) {
        if (dp[y, x] != 0) return dp[y, x];
        long ret = 1;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dir[i];
            int nx = x + dir[i + 1];
            if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                if (A[ny, nx] > A[y, x]) {
                    ret = (ret + dfs(ny, nx)) % MOD;
                }
            }
        }
        return dp[y, x] = ret;
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