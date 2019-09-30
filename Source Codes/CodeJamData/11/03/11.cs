using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int[] value = new int[n];
                int sum = 0;
                int xorsum = 0;
                int min = 100000000;
                for (int i = 0; i < n; ++i)
                {
                    value[i] = Convert.ToInt32(str[i]);
                    sum += value[i];
                    xorsum ^= value[i];
                    if (value[i] < min) min = value[i];
                }
                if (xorsum == 0)
                {
                    Console.WriteLine("Case #{0}: {1}", curCase + 1, sum - min);
                }
                else
                {
                    Console.WriteLine("Case #{0}: NO", curCase + 1);
                }
            }
        }
    }
}
