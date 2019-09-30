using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        long sum = 0;
        int max = 0;
        int min = int.MaxValue;
        for (int i = 0; i < nab[0]; i++)
        {
            int a = int.Parse(Console.ReadLine());
            sum += a;
            max = Math.Max(a, max);
            min = Math.Min(a, min);
        }
        if ((max - min) != 0) Console.WriteLine($"{(double)nab[2] / (max - min)} {(nab[1] - (sum / (double)nab[0]) * ((double)nab[2] / (max - min)))}");
        else Console.WriteLine($"-1");
    }
}