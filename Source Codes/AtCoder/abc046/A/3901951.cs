using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int a = int.Parse(cin[0]);
        int b = int.Parse(cin[1]);
        int c = int.Parse(cin[2]);

        if (a == b || b == c || a == c)
        {
            if (a == b && b == c)
            {
                Console.WriteLine(1);
            }
            else
            {
                Console.WriteLine(2);
            }
        }
        else
        {
            Console.WriteLine(3);
        }
    }
}