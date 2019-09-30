using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int min = int.MaxValue;
        
        for (int i = -100; i <= 100; i++)
        {
            int sum = 0;
            foreach (int n in a)
            {
                sum += (i - n) * (i - n);
            }
            min = Math.Min(min, sum);
        }
        Console.WriteLine(min);
    }
}