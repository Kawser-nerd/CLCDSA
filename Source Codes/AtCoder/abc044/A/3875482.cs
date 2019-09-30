using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var k = int.Parse(Console.ReadLine());
        var x = int.Parse(Console.ReadLine());
        var y = int.Parse(Console.ReadLine());

        var val = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < k)
            {
                val += x;
            }
            else
            {
                val += y;
            }
        }

        Console.WriteLine(val);
    }
}