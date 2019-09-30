using System;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        var chars = s.ToCharArray();

        for (var i = 0; i < chars.Length; i += 2)
        {
            Console.Write(chars[i]);
        }

        Console.WriteLine();
    }
}