using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] res = new int[6];
        for (int i = 0; i < n; i++)
        {
            double[] a = Console.ReadLine().Split().Select(double.Parse).ToArray();
            if (a[0] >= 35) res[0]++;
            else if (a[0] >= 30) res[1]++;
            else if (a[0] >= 25) res[2]++;
            if (a[1] >= 25) res[3]++;
            if(a[1] < 0)
            {
                if (a[0] >= 0) res[4]++;
                else res[5]++;
            }
        }
        Console.WriteLine(string.Join(" ",res));
    }
}