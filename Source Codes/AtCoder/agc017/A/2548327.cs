using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] np = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(x => int.Parse(x) % 2).ToArray();
        int evenCount = a.Count(x => x == 0);
        int oddCount = a.Count(x => x == 1);
        long comb = 1;
        long oddComb = 0;
        if (np[1] == 0) oddComb++;
        for (int i = 1; i <= oddCount; i++)
        {
            comb = (comb * (oddCount + 1 - i)) / i;
            if (i % 2 == np[1]) oddComb += comb;
        }
        Console.WriteLine(power(2, evenCount) * oddComb);
    }

    static long power(int n, int m)
    {
        long pow = n;
        long res = 1;
        while (m > 0)
        {
            if ((m & 1) == 1) res = res * pow;
            pow = pow * pow;
            m >>= 1;
        }
        return res;
    }
}