using System;
using System.Collections.Specialized;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        // ?
        //int ans = 0;
        string ans = string.Empty;
        //long ans = 0;
        //double ans = 0;

        // ??
        string inp = MyConsole.ReadStr();

        // ??
        char[] chrs = inp.ToCharArray().Where((elm, idx) => (idx + 1) % 2 == 1).ToArray();
        ans = new string(chrs);

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