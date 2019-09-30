using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Security.Principal;
using System.Text;
class Simple
{
    int N;
    int[] p;
    void Solve() {
        //input
        N = io.Int;
        p = new int[N];
        for (int i = 0; i < N; ++i)
            p[i] = io.Int;
        //cal
        var bas = 20000+5;
        var A = p.Select((v, i) => bas * (i + 1)).ToArray();
        var B = p.Select((v, i) => bas * (N - i)).ToArray();
        for (int i = 0; i < N; ++i) {
            B[p[i] - 1] += i+1;
        }
        //ret
        foreach (var v in A) Console.Write(v + " ");
        Console.WriteLine("");
        foreach (var v in B) Console.Write(v + " ");
        Console.WriteLine("");
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) => new Simple().Stream();
    void Stream() {
        Solve();
        io.writeFlush();
    }
}
class SimpleIO
{
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
        if (BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
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