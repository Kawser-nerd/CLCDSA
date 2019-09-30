using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> x = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        List<int> y = new List<int>(x);
        y.Sort();

        int idx = n / 2;
        for (int i = 0; i < n; i++)
        {
            if(x[i] < y[idx])
            {
                Console.WriteLine(y[idx]);
            }
            else
            {
                Console.WriteLine(y[idx - 1]);
            }
        }       
    }
}