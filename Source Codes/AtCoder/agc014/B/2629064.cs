using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split();
        int n, m;
        n = int.Parse(s[0]);
        m = int.Parse(s[1]);
        List<int> l = new List<int>();
        for (int i = 0; i < m; i++)
        {
            s = Console.ReadLine().Split();
            int a, b;
            a = int.Parse(s[0]);
            b = int.Parse(s[1]);
            l.Add(a);
            l.Add(b);
        }
        int[] count = new int[l.Max() + 1];
        foreach (var i in l)
            count[i]++;
        bool f = true;
        foreach (var i in count)
            f = f && i % 2 == 0;
        C.WriteLine(f ? "YES" : "NO");
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