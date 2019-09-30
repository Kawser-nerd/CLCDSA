using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        int[] e = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int b = int.Parse(Console.ReadLine());
        int[] l = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int c = 0;
        foreach (var i in l)
            if (e.Contains(i))
                c++;
        //C.WriteLine(c);
        if (c < 3)
            C.WriteLine(0);
        if (c == 3)
            C.WriteLine(5);
        if (c == 4)
            C.WriteLine(4);
        if (c == 5 && l.Contains(b))
            C.WriteLine(2);
        if (c == 5 && !l.Contains(b))
            C.WriteLine(3);
        if (c == 6)
            C.WriteLine(1);
    }
}
//???????????
static class C
{
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern void printf(string s);
    public static void Write(string s) { printf(s); }
    public static void Write(char c) { printf(c.ToString()); }
    public static void Write(long n) { printf(n.ToString()); }
    public static void Write(int n) { printf(n.ToString()); }
    public static void Write(double d) { printf(d.ToString()); }
    public static void WriteLine() { printf("\n"); }
    public static void WriteLine(string s) { printf(s + "\n"); }
    public static void WriteLine(char c) { WriteLine(c.ToString()); }
    public static void WriteLine(long n) { WriteLine(n.ToString()); }
    public static void WriteLine(int n) { WriteLine(n.ToString()); }
    public static void WriteLine(double d) { WriteLine(d.ToString()); }
    public static void WriteLines(string[] s) { foreach (var i in s) WriteLine(i); }
    public static void WriteLines(char[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(long[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(int[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(double[] d) { foreach (var i in d) WriteLine(i); }
}