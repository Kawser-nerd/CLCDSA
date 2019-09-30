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
    int N;
    int[] A;
    void Solve() {
        //input
        H = io.Int;
        W = io.Int;
        N = io.Int;
        A = new int[N];
        for (int i = 0; i < N; ++i)
            A[i] = io.Int;
        //cal
        int[,] C = new int[H, W];
        bool rev = false;
        int nowIndex = 0;
        for (int i = 0; i < H; ++i) {
            if (!rev)
                for (int j = 0; j < W; ++j) {
                    if (A[nowIndex] > 0) {
                        C[i, j] = nowIndex + 1;
                    } else {
                        nowIndex++;
                        C[i, j] = nowIndex + 1;
                    }
                    A[nowIndex]--;
                    if (j == W - 1)
                        rev = !rev;
                } 
            else
                for (int j = W - 1; j >= 0; --j) {
                    if (A[nowIndex] > 0) {
                        C[i, j] = nowIndex + 1;
                    } else {
                        nowIndex++;
                        C[i, j] = nowIndex + 1;

                    }
                    A[nowIndex]--;
                    if (j == 0)
                        rev = !rev;
                }
        }
        //ret
        for (int i = 0; i < H;++i){
            for (int j = 0; j < W-1;++j){
                Console.Write(C[i,j]+" ");
            }
            Console.WriteLine(C[i,W-1]);
        }
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