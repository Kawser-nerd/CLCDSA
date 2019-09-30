using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        if (n < 1200) Console.WriteLine("ABC");
        else if (n < 2800) Console.WriteLine("ARC");
        else Console.WriteLine("AGC");
    }
}