using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var value = 0;
        for (int i = 0; i < n; i++)
        {
            value += i + 1;
        }

        Console.WriteLine(value);
    }
}