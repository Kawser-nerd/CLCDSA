using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        double dave = a.Average();
        if (dave == Math.Floor(a.Average()))
        {
            int ave = (int)dave;
            int nowamari = 0;
            int res = 0;
            foreach (var i in a)
            {
                if (nowamari != 0) res++;
                nowamari += i - ave;
            }
            Console.WriteLine(res);
        }
        else
        {
            Console.WriteLine(-1);
        }
    }
}