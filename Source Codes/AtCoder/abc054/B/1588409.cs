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
    string[] A, B;
    void Solve() {
        //input
        N = io.Int;
        M = io.Int;
        A = new string[N];
        B = new string[M];
        for (int i = 0; i < N; ++i)
            A[i] = io.String;
        for (int j = 0; j < M; ++j)
            B[j] = io.String;
        //cal
        for (int shiftX = 0; shiftX < N - M + 1; ++shiftX) {
            for (int shiftY = 0; shiftY < N - M + 1; ++shiftY) {
                for (int i = 0; i < M; ++i) {
                    for (int j = 0; j < M; ++j) {
                        if (A[i + shiftY][j + shiftX] != B[i][j])
                            goto BR;
                    }
                }
                //res(Contain)
                Console.WriteLine("Yes");
                return;
            BR:;
            }
        }
        //res(!Contain)
        Console.WriteLine("No");
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