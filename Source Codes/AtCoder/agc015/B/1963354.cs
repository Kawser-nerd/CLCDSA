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
class Simple {
    private string S;
    void Solve() {
        //input
        S = io.String;
        //cal
        var ans = 0L;
        var floor = S.Length;
        Func <char, bool> isUp = (c) => c == 'U';
        for(int i = 1; i <= floor; ++i) {
            var ue = floor - i;
            var sita = i - 1;
            if(isUp(S[i - 1])) ans += ue + sita * 2;
            else ans += ue * 2 + sita;
        }
        //ret
        Console.WriteLine(ans);
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