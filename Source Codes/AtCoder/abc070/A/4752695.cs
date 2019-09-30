using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        Console.WriteLine(s[0] == s[2] ? "Yes" : "No");
    }
}