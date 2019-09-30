using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        var s = Console.ReadLine().Split(' ');
        var N = int.Parse(s[0]);
        var M = int.Parse(s[1]);

        int l = M / N;
        for (int i = l ; i > 0 ; i--)
        {
            if (M % i == 0)
            {
                Console.WriteLine(i);
                break;
            }
        }
    }
}