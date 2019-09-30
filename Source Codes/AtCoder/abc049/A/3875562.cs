using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var c = Console.ReadLine();
        var vow = new List<string> { "a", "e", "i", "o", "u" };
        if (vow.Any(x => x == c))
        {
            Console.WriteLine("vowel");
        }
        else
        {
            Console.WriteLine("consonant");
        }
    }
}