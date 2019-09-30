using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var a = int.Parse(Console.ReadLine());
        var b = int.Parse(Console.ReadLine());
        var n = int.Parse(Console.ReadLine());

        while (true)
        {
            if (n >= a && n >= b && n % a == 0 && n % b == 0)
            {
                Console.WriteLine(n);
                return;
            }

            n++;
        }
    }
}