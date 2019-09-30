using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int s = int.Parse(Console.ReadLine());

        if (s == 1 || s == 2)
        {
            Console.WriteLine(4);
            return;
        }

        int ans = 1;
        while (s > 1)
        {
            if (s % 2 == 1) s = 3 * s + 1;
            else s = s / 2;
            ans++;
        }

        Console.WriteLine(ans + 1);
    }
}