using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split();
        var a = int.Parse(s[0]);
        var b = int.Parse(s[2]);

        if (s[1] == "+") Console.WriteLine(a + b);
        else Console.WriteLine(a - b);
    }
}