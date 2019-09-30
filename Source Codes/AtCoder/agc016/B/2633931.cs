using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
class Program
{
    static void Main()
    {
        int n = C.NextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = C.NextInt();
        HashSet<int> hs = new HashSet<int>();
        foreach (var i in a)
            hs.Add(i);
        if (hs.Count > 2)
            C.WriteLine("No");
        if (hs.Count == 2)
        {
            int M, m;
            M = hs.Max();
            m = hs.Min();
            if (M - m != 1)
            {
                C.WriteLine("No");
                Environment.Exit(0);
            }
            int x = a.Count(s => s == m);
            int y = n - x;
            bool f = x < M && 2 * (M - x) <= y;
            C.WriteLine(f ? "Yes" : "No");
        }
        if (hs.Count == 1)
        {
            int k = a[0];
            bool f = k == n - 1 || 2 * k <= n;
            C.WriteLine(f ? "Yes" : "No");
        }
    }
}
//????????????
static class C
{
    public static string NextToken()
    {
        StringBuilder tokenChars = new StringBuilder();
        bool tokenFinished = false;
        bool skipWhiteSpaceMode = true;
        while (!tokenFinished)
        {
            int nextChar = Console.Read();
            if (nextChar == -1)
                tokenFinished = true;
            else
            {
                char ch = (char)nextChar;
                if (char.IsWhiteSpace(ch))
                {
                    if (!skipWhiteSpaceMode)
                    {
                        tokenFinished = true;
                        if (ch == '\r' && (Environment.NewLine == "\r\n"))
                            Console.Read();
                    }
                }
                else
                {
                    skipWhiteSpaceMode = false;
                    tokenChars.Append(ch);
                }
            }
        }
        return tokenChars.ToString();
    }
    public static int NextInt()
    {
        string token = C.NextToken();
        return int.Parse(token);
    }
    public static long NextLong()
    {
        string token = C.NextToken();
        return long.Parse(token);
    }
    public static double NextDouble(bool acceptAnyDecimalSeparator = true)
    {
        string token = C.NextToken();
        if (acceptAnyDecimalSeparator)
        {
            token = token.Replace(',', '.');
            double result = double.Parse(token, CultureInfo.InvariantCulture);
            return result;
        }
        else
        {
            double result = double.Parse(token);
            return result;
        }
    }
    public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true)
    {
        string token = C.NextToken();
        if (acceptAnyDecimalSeparator)
        {
            token = token.Replace(',', '.');
            decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
            return result;
        }
        else
        {
            decimal result = decimal.Parse(token);
            return result;
        }
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
    public static void WriteLines(string[] s) { foreach (var i in s) WriteLine(i); }
    public static void WriteLines(char[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(long[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(int[] c) { foreach (var i in c) WriteLine(i); }
    public static void WriteLines(double[] d) { foreach (var i in d) WriteLine(i); }
}