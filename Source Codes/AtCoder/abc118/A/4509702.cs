using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        // ?
        int ans = 0;

        // ??
        int[] inp = ConsoleReader.ReadInt(' ');

        // ??
        int a = inp[0];
        int b = inp[1];

        if ((b % a) == 0)
        {
            ans = a + b;
        }
        else
        {
            ans = b - a;
        }
        
        //??
        Console.WriteLine(ans);
    }
}

class ConsoleReader
{
    // ???????????
    public static string ReadString() { return Console.ReadLine(); }
    public static int ReadInt() { return int.Parse(Console.ReadLine()); }
    public static string[] ReadString(char sep) { return Console.ReadLine().Split(sep); }
    public static int[] ReadInt(char sep) { return Console.ReadLine().Split(sep).Select(x => int.Parse(x)).ToArray(); }
}