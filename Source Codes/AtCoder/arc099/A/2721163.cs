using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class P
{
    static void Main()
    {
        int n = ReadInt();
        int k = ReadInt();
        int[] a = ReadInts(n);
        int ind1 = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 1)
                ind1 = i;
        int ans = 0;
        ans += (n - ind1 - 1) / (k - 1);
        ans += ind1 / (k - 1);
        //WriteLine(ans);
        int r = (n - ind1 - 1) % (k - 1);
        //WriteLine(r);
        int l = ind1 % (k - 1);
        //WriteLine(l);
        if (r + l + 1 <= k && r + l + 1 >= 2)
            ans++;
        else if (r + l + 1 > k)
            ans += 2;
        WriteLine(ans);
    }
    //?????????????
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out long l);
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out double l);
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out char c);
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
    public static string[] ReadStrs(int n)
    {
        string[] s = new string[n];
        for (int i = 0; i < n; i++)
            s[i] = ReadStr();
        return s;
    }
    public static double ReadDouble()
    {
        double d;
        scanf("%lf", out d);
        return d;
    }
    public static char ReadChar()
    {
        char c;
        while (true)
        {
            scanf("%c", out c);
            if (c != '\n' && c != ' ')
                break;
        }
        return c;
    }
    public static string ReadStr()
    {
        StringBuilder sb = new StringBuilder();
        char c;
        do
        {
            scanf("%c", out c);
        } while (c == '\n' || c == ' ');
        sb.Append(c);
        while (true)
        {
            scanf("%c", out c);
            if (c == '\n' || c == ' ')
                break;
            sb.Append(c);
        }
        return sb.ToString();
    }
    public static string ReadLine()
    {
        StringBuilder sb = new StringBuilder();
        char c;
        do
        {
            scanf("%c", out c);
            if (c != '\n')
                sb.Append(c);
        } while (c != '\n');
        return sb.ToString();
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