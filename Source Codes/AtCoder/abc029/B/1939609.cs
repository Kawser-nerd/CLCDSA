using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int res = 0;
        for (int i = 0; i < 12; i++)
        {
            if (Console.ReadLine().Contains('r')) res++;
        }
        Console.WriteLine(res);
    }
}