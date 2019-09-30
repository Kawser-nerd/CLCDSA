using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var b = Console.ReadLine();
        var pair = new Dictionary<string, string>(4);
        pair.Add("A", "T");
        pair.Add("C", "G");
        pair.Add("T", "A");
        pair.Add("G", "C");

        Console.WriteLine(pair[b]);
    }
}