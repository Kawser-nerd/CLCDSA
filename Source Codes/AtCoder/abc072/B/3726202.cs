using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();

        for (var i = 0; i < s.Length; i += 2)
        {
            Console.Write(s[i]);
        }
    }
}