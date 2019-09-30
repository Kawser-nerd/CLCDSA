using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().ToCharArray();
        s[3] = '8';
        Console.WriteLine(s);
    }
}