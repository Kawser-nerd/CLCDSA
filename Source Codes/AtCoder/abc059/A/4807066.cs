using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split();
        var a = (char)(s[0][0] - 0x20);
        var b = (char)(s[1][0] - 0x20);
        var c = (char)(s[2][0] - 0x20);
        Console.WriteLine("{0}{1}{2}", a, b, c);
    }
}