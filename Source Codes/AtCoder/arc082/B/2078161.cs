using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;

public class Test
{
    public static void Main()
    {
        Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int res = 0;
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] == i + 1)
            {
                i++;
                res++;
            }
        }
        Console.WriteLine(res);
    }
}