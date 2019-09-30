using System;
using System.CodeDom;
using System.Collections;
using System.Collections.Generic;
using System.Configuration;
//using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Contexts;
using System.Runtime.Remoting.Messaging;
using System.Security.Principal;
using System.Text;
class Simple {
    private int N;
    private int[] T, A;
    void Solve() {        
        //input
        N = io.Int;
        T = new int[N];
        A = new int[N];        
        for(int i = 0; i < N; ++i) {
            T[i] = io.Int;
            A[i] = io.Int;            
        }
        //cal
        var a = 1L;
        var b = 1L;
        for(int i = 0; i < N; ++i) {            
            f(ref a,ref b,T[i],A[i]);       
        }
        var ans = a + b;
        //ret
        Console.WriteLine(ans);
    }
    private Func <long, long, bool> isDivisiable = (v, n) => v % n == 0;
    void f(ref long a, ref long b, int ratioA, int ratioB) {
        var ta = a / ratioA;
        var tb = b / ratioB;
        var ok_A = isDivisiable(a, ratioA);
        var ok_B = isDivisiable(b, ratioB);
        if(ok_A && ok_B) {
            if(ta == tb) {
                //ok
            } else {
                if(ta < tb)  
                    a = tb * ratioA; 
                else  
                    b = ta * ratioB; 
            }
        } else {
            if(!ok_A) 
                a = (ta + 1) * ratioA; 
            if(!ok_B) 
                b = (tb + 1) * ratioB; 
            f(ref a,ref b,ratioA,ratioB);
        }
    }
    long calRatio(long n, long a, long b) { return n % gcd(a, b); }
    long gcd(long a, long b) {
        if(a < b) swap(ref a, ref b);
        return a % b == 0 ? b : gcd(b, a % b);
    }
    void swap(ref long a, ref long b) {
        long t = b;
        b = a;
        a = t;
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) => new Simple().Stream();
    void Stream() {
        Solve();
        io.writeFlush();
    }
}
class SimpleIO {
    string[] nextBuffer;
    int BufferCnt;
    char[] cs = new char[] {' '};
    StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
    public SimpleIO() {
        nextBuffer = new string[0];
        BufferCnt = 0;
        Console.SetOut(sw);
    }
    public string Next() {
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