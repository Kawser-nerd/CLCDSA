using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple{
    private int N;
    private double[] t, v;
    void Solve(){
        //input
        N = io.Int;
        t = new double[N + 2];
        v = new double[N + 2];
        for(int i = 0; i < N; ++i) t[i + 1] = io.Double;
        for(int i = 0; i < N; ++i) v[i + 1] = io.Double;
        //cal
        var start = new double[N + 2];
        var time = 0D;
        for(int i = 0; i < N + 2; ++i){
            start[i] = time;
            time += t[i];            
        }
        var pre = 0D;
        var cur = 0D;
        var ans = 0D;
        var tmp = new double[N + 2];
        for(int i = 0; i < time * 2; ++i){
            pre = cur;
            var cTime = i / 2D;
            for(int j = 0; j < N + 2; ++j){
                if(cTime < start[j])  tmp[j] = v[j] +start[j]-cTime; 
                else if(start[j] <= cTime && cTime <= start[j] + t[j]) tmp[j] = v[j];
                else tmp[j] = v[j] + cTime - (start[j] + t[j]);                                                                     
            }
            cur = tmp.Min();
            ans += (pre + cur) * 0.5 / 2;
        }
        pre = cur;
        cur = 0;
        ans += (pre + cur) * 0.5 / 2;
        //ret
        Console.WriteLine(ans);       
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) { new Simple().Stream(); }
    void Stream(){
        Solve();
        io.writeFlush();
    }
}
class SimpleIO{
    string[] nextBuffer;
    int BufferCnt;
    char[] cs = new char[]{' '};
    StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
    public SimpleIO(){
        nextBuffer = new string[0];
        BufferCnt = 0;
        Console.SetOut(sw);
    }
    public string Next(){
        if(BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
        string st = Console.ReadLine();
        while(st == "") st = Console.ReadLine();
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