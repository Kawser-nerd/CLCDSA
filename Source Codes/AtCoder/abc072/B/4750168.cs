using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        for (int i = 0; i < s.Length; i += 2)
        {
            Console.Write(s[i]);
        }
        Console.WriteLine();
    }
}