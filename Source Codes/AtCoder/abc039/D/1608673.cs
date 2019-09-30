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
    string[] S;
    readonly int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 }; 
    readonly int[] dx = { 1, 1, 0, -1, -1, -1, 0, 1 };
    void Solve() {
        //input
        H = io.Int;
        W = io.Int;
        S = new string[H];
        for (int i = 0; i < H; ++i)
            S[i] = io.String;
        //cal
        //??
        var ans = new char[H,W];
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (S[i][j] == '#') {
                    int ccnt = 0;//# only
                    int ecnt = 0;//# or .
                    for (int k = 0; k < 8; ++k) {
                        int ny=i+dy[k];
                        int nx=j+dx[k];
                        if(0<=ny&&ny<H&&0<=nx&&nx<W){
                            ecnt++;
                            if(S[ny][nx]=='#'){
                                ccnt++;
                            }
                        }
                    }
                    ans[i, j] = ccnt==ecnt?'#':'.';
                }else{
                    ans[i, j] = '.';
                }
            }
        }
        //??
        var rev = new char[H, W];
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (ans[i,j] == '#') {
                    rev[i, j] = '#';
                    for (int k = 0; k < 8; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                            rev[ny, nx] = '#';
                        }
                    }
                } else {
                    if(rev[i,j]!='#'){
                        rev[i, j] = '.';
                    }
                }
            }
        }
        //??
        for (int i = 0; i < H;++i){
            for (int j = 0; j < W;++j){
                if(S[i][j]!=rev[i,j]){
                    Console.WriteLine("impossible");
                    return;
                }
            }
        }
        //ret
        Console.WriteLine("possible");
        for (int i = 0; i < H;++i){
            for (int j = 0; j < W-1;++j){
                Console.Write(ans[i,j]);
            }
            Console.WriteLine(ans[i, W-1]);
        }
    }

    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream() {
        Solve();
        //Test();
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