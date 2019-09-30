using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    string S;
    void Solve() {
        //input
        S = io.String;
        //ret
        if (S == "WBWBWWBWBWBWWBWBWWBW")
            Console.WriteLine("Do");
        else if (S == "WBWWBWBWBWWBWBWWBWBW")
            Console.WriteLine("Re");
        else if (S == "WWBWBWBWWBWBWWBWBWBW")
            Console.WriteLine("Mi");
        else if (S == "WBWBWBWWBWBWWBWBWBWW")
            Console.WriteLine("Fa");
        else if (S == "WBWBWWBWBWWBWBWBWWBW")
            Console.WriteLine("So");
        else if (S == "WBWWBWBWWBWBWBWWBWBW")
            Console.WriteLine("La");
        else if (S == "WWBWBWWBWBWBWWBWBWWB")
            Console.WriteLine("Si");
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