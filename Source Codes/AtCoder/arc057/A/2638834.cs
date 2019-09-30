class P
{
    static void Main()
    {
        long a = ReadLong();
        long k = ReadLong();
        if (k == 0)
        {
            WriteLine(2000000000000 - a);
            return;
        }
        int c = 0;
        for (c = 1; ; c++)
        {
            a += 1 + k * a;
            if (a >= 2000000000000)
                break;
        }
        WriteLine(c);
    }
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern int scanf(string format, out long l);
    public static long ReadLong()
    {
        long l;
        scanf("%ld", out l);
        return l;
    }
    [System.Runtime.InteropServices.DllImport("msvcrt.dll")]
    private static extern void printf(string s);
    public static void WriteLine(string s) { printf(s + "\n"); }
    public static void WriteLine(long n) { WriteLine(n.ToString()); }
    public static void WriteLine(int n) { WriteLine(n.ToString()); }
}