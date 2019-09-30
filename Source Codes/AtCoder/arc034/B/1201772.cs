using System;
using System.Collections.Generic;

namespace arc034_2
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            List<long> ret = new List<long>();
            int x = 0;
            for (int i = 1; i < Math.Min(n, 154); i++)
            {
                long a = n - i;
                int b = 0;
                for (int j = 0; j < a.ToString().Length; j++)
                {
                    b += int.Parse(a.ToString()[j].ToString());
                }
                if (b == i)
                {
                    x++;
                    ret.Add(a);
                }
            }
            Console.WriteLine(x);
            for (int i = x - 1; i >= 0; i--)
            {
                Console.WriteLine(ret[i]);
            }
        }
    }
}