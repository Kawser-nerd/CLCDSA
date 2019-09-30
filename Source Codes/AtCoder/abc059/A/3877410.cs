using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => x.Substring(0, 1).ToUpper()).ToList();
        Console.WriteLine(input[0] + input[1] + input[2]);
    }
}