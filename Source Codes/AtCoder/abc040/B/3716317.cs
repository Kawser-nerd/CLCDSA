using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());

        if (n == 1)
        {
            Console.WriteLine(0);
            return;
        }

        var min = int.MaxValue;
        for (var w = 1; w < n; w++)
        {
            var h = n / w;
            var div = n % w;

            var result = Math.Abs(h - w) + div;
            if (result < min)
            {
                min = result;
            }
        }

        Console.WriteLine(min);
    }
}