using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        int a = 0;
        int b = 0;
        if (n[0] >= 900)
        {
            if(n[0] >= 990)
            {
                a = 999;
            }
            else
            {
                a = n[0] + 10 * ((999 - n[0]) / 10);
            }
        }
        else
        {
            a = n[0] + 100 * ((999 - n[0]) / 100);
        }
        if (n[1] <= 199)
        {
            if (n[1] <= 109)
            {
                b = 100;
            }
            else
            {
                b = n[1] - 10 * ((n[1] - 100) / 10);
            }
        }
        else
        {
            b = n[1] - 100 * ((n[1] - 100) / 100);
        }
        Console.WriteLine(Math.Max(n[0] - b, a - n[1]));
    }
}