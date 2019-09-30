using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split(' ');
        var a = int.Parse(s[0]);
        var b = int.Parse(s[1]);
        var c = int.Parse(s[2]);

        if (a == b) Console.WriteLine(c);
        else if (b == c) Console.WriteLine(a);
        else if (c == a) Console.WriteLine(b);
    }
}