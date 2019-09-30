using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.WriteLine(elapsedDate(2014, 5, 17) - elapsedDate(int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine())));
    }
    static int elapsedDate(int y,int m,int d)
    {
        if (m <= 2)
        {
            y--;
            m += 12;
        }
        return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
    }
}