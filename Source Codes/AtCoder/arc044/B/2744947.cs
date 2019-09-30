using System.Collections.Generic;
using System.Linq;
using System.Text;
class P
{
    static long mod = 1000000007;
    static void Main()
    {
        int n = ReadInt();
        int[] a = ReadInts(n);
        int[] d = new int[a.Max() + 1];
        foreach (var i in a)
            d[i]++;
        long ans = 1;
        if (d[0] != 1)
        {
            WriteLine(0);
            return;
        }
        if (a[0] != 0)
        {
            WriteLine(0);
            return;
        }
        for (int i = 0; i < d.Length - 1; i++)
        {
            long s = d[i];
            long g = d[i + 1];
            ans = ans * Pow((Pow(2, s) - 1), g) % mod;
        }
        for (int i = 0; i < d.Length; i++)
        {
            long dn = d[i];
            long p = dn * (dn - 1) / 2;
            ans = ans * Pow(2, p) % mod;
        }
        WriteLine(ans);
        return;
    }
    static long Pow(long a, long n)
    {
        if (n == 0) return 1;
        long z = Pow(a, n / 2);
        z = z * z % mod;
        if (n % 2 == 1) z = z * a % mod;
        return z;
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