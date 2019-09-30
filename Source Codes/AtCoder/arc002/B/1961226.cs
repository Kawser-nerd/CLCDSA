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
    private int Y, M, D;
    void Solve() {
        //input
        var S = io.String.Split('/').Select(int.Parse).ToArray();
        Y = S[0];
        M = S[1];
        D = S[2];
        //cal
        var date = new Date(Y, M, D);
        while(date.Year % (date.Month * date.Day) != 0) {
            date.NextDay();            
        }
        var ans = date.Year + "/" + date.Month.ToString().PadLeft(2, '0') + 
                  "/" + date.Day.ToString().PadLeft(2, '0');
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
class Date {
    public int Year = 1000;
    public int Month = 1;
    public int Day = 1;
    public bool IsLeapYear(int y) => y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    public Date(int y, int m, int d) {
        Year = y;
        Month = m;
        Day = d;
        if(IsLeapYear(y)) daysPerMonth[1] = 29;
    }
    private int[] daysPerMonth = new int[12]
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public void NextDay() {
        //Year
        if(Month == 12 && Day == 31) {
            Year++;
            Month = 1;
            Day = 1;
            daysPerMonth[1] = IsLeapYear(Year) ? 29 : 28;
        }
        //Month
        else if(Day == daysPerMonth[Month - 1]) {
                Month++;
                Day = 1;
            
        }
        //Day
        else { Day++; }
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