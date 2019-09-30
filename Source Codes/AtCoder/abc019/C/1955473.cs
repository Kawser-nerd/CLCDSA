using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        Console.WriteLine(Console.ReadLine().Split().Select(parse).Distinct().Count());
    }
    static int parse(string s)
    {
        int i = int.Parse(s);
        while (i % 2 == 0) i /= 2;
        return i;
    }
}