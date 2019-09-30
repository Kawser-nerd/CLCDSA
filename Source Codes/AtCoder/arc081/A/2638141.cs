using System;
using System.Collections.Generic;
using System.Linq;
//using System.Text;
class Program
{
    static void Main()
    {
        int n = C.ReadInt();
        int[] a = C.ReadInts(n);
        Array.Sort(a);
        List<int> l = new List<int>();
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == a[i - 1])
            {
                l.Add(a[i]);
                i--;
            }
        }
        if (l.Count < 2)
            C.WriteLine(0);
        else
            C.WriteLine((long)l[0] * l[1]);
    }
}
//????????????
static class C
{
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out long l);
    public static long ReadLong()
    {
        long l;
        scanf("%ld", out l);
        return l;
    }
    public static int ReadInt()
    {
        return (int)ReadLong();
    }
    public static int[] ReadInts(int n)
    {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = ReadInt();
        return nums;
    }
    public static long[] ReadLongs(int n)
    {
        long[] nums = new long[n];
        for (int i = 0; i < n; i++)
            nums[i] = ReadLong();
        return nums;
    }
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
    public static void WriteLine(string[] s)
    {
        for (int i = 0; i < s.Length - 1; i++)
            Write(s[i] + " ");
        WriteLine(s[s.Length - 1]);
    }
    public static void WriteLine(char[] c)
    {
        for (int i = 0; i < c.Length - 1; i++)
            Write(c[i] + " ");
        WriteLine(c[c.Length - 1]);
    }
    public static void WriteLine(long[] n)
    {
        for (int i = 0; i < n.Length - 1; i++)
            Write(n[i] + " ");
        WriteLine(n[n.Length - 1]);
    }
    public static void WriteLine<T>(ICollection<T> ic)
    {
        foreach (var i in ic)
            Write(i + " ");
        WriteLine("\b");
    }
    public static void WriteLine(int[] n)
    {
        for (int i = 0; i < n.Length - 1; i++)
            Write(n[i] + " ");
        WriteLine(n[n.Length - 1]);
    }
    public static void WriteLine(double[] d)
    {
        for (int i = 0; i < d.Length - 1; i++)
            Write(d[i] + " ");
        WriteLine(d[d.Length - 1]);
    }
    public static void WriteLines(string[] s) { foreach (var i in s) WriteLine(i); }
    public static void WriteLines(char[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(long[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(int[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(double[] d) { foreach (var i in d) WriteLine(i); }
    public static void WriteLines<T>(ICollection<T> ic) { WriteLines(ic.ToArray()); }
}