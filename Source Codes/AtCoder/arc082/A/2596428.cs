using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int[] count = new int[a.Max() + 1];
        int am = a.Max();
        for (int i = 0; i < n; i++)
        {
            int m = a[i];
            if (m > 0)
                count[m - 1]++;
            count[m]++;
            if (m < am)
                count[m + 1]++;
        }
        C.WriteLine(count.Max());
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