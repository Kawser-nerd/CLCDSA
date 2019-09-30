using System;
using System.Collections;
using System.Collections.Generic;
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
    private string s;
    void Solve() {
        //input
        s = io.String;
        //cal
        var win = 0;
        var los = 0;
        var pNum = 0;
        var gNum = 0;        
        Func <bool> availableP = () => pNum + 1 <= gNum;
        Func <int,bool>  isG=(index)=> s[index] == 'g';
        Func <int, bool> drawableWithG = (index) => isG(index);
        Func <int, bool> drawableWithP = (index) => !isG(index) && availableP();
        Func <int, bool> winable = (index) => availableP() && isG(index);
        for(int i = 0; i < s.Length; ++i) {
            if(winable(i)) {
                win++;
                pNum++;
            } else if(drawableWithG(i)) {
                gNum++;
            } else if(drawableWithP(i)) {
                pNum++;
            } else {
                los++;
                gNum++;
            }
        }
        //ret
        Console.WriteLine(win - los);
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