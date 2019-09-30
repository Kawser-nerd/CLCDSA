using System;
using System.Collections.Specialized;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        // ?
        int ans = 0;

        // ??
        int[] inp = MyConsole.ReadInt(' ');

        // ??
        ans = inp[0] - inp[1];
        if (ans < 0)
        {
            ans = 0;
        }
        
        // ??
        MyConsole.WriteLine(ans);
    }
}

class MyConsole
{
    // ???????????
    public static string ReadStr() { return Console.ReadLine(); }
    public static int ReadInt() { return int.Parse(Console.ReadLine()); }
    public static long ReadLong() { return long.Parse(Console.ReadLine()); }
    public static string[] ReadStr(char sep) { return Console.ReadLine().Split(sep); }
    public static int[] ReadInt(char sep) { return Console.ReadLine().Split(sep).Select(x => int.Parse(x)).ToArray(); }
    public static long[] ReadLong(char sep) { return Console.ReadLine().Split(sep).Select(x => long.Parse(x)).ToArray(); }

    public static void WriteLine(object param) { Console.WriteLine(param); }
}