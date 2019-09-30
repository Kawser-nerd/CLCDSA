using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple{
    private int[] b=new int[10];
    private int N;
    private int[] a;
    void Solve(){
        //input
        for(int i = 0; i < 10; ++i) b[i] = io.Int;        
        var withNormal = b.Select((v, i) => new{Value = v, Index = i}).
                           ToDictionary(v => v.Value, v => v.Index);
        N = io.Int;
        a = new int[N];
        for(int i = 0; i < N; ++i) a[i] = io.Int;
        var withConverted = a.Select
            (v => new{
                AtCoder = v, 
                Converted = int.Parse(new string(v.ToString().ToCharArray().
                                Select(c => char.Parse(withNormal[int.Parse(c.ToString())].ToString())).ToArray()))
            });
        foreach(var v in withConverted.OrderBy(p=>p.Converted)){
            Console.WriteLine(v.AtCoder);            
        }
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