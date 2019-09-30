using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        var s = Console.ReadLine().Split(' ');
        if (int.Parse(s[0]) <= 8 && int.Parse(s[1]) <= 8)
            Console.WriteLine("Yay!");
        else
            Console.WriteLine(":(");

    }
}