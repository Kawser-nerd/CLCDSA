using System;
//using System.Collections.Generic;
//using System.Linq;
class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split();
        long n, x;
        n = long.Parse(s[0]);
        x = long.Parse(s[1]);
        C.WriteLine(f(n, x));
    }
    static long f(long n, long x)
    {
        if (x == 0)
            return 0;
        return 3 * (n - GCD(n, x));
    }
    static long GCD(long u, long v)
    {
        long k, t;
        k = 0;
        while ((0 == (u & 1)) && (0 == (v & 1)))
        {
            k++;
            u /= 2;
            v /= 2;
        }
        if ((u & 1) == 0)
            t = u / 2;
        else
            t = -v;
        do
        {
            while ((t & 1) == 0) t /= 2;
            if (t > 0)
                u = t;
            else
                v = -t;
            t = u - v;
        } while (0 != t);
        return u * (1 << (int)k);
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