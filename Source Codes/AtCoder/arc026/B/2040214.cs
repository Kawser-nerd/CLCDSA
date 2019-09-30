using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        long a = long.Parse(Console.ReadLine());
        long res = -a;
        int sqrta = (int)Math.Ceiling(Math.Sqrt(a));
        for (int i = 1; i < sqrta; i++)
        {
            if (a % i == 0)
            {
                if (a / i == i) res += i;
                else res += (a / i) + i;
            }
        }
        Console.WriteLine(a == res ? "Perfect" : (a > res ? "Deficient" : "Abundant"));
    }

}