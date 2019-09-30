using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] qhsd = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long n = long.Parse(Console.ReadLine());
        if (qhsd[1] > qhsd[0] * 2)
        {
            qhsd[1] = qhsd[0] * 2;
        }
        if (qhsd[2] > qhsd[1] * 2)
        {
            qhsd[2] = qhsd[1] * 2;
        }
        if (qhsd[3] > qhsd[2] * 2)
        {
            qhsd[3] = qhsd[2] * 2;
        }
        Console.WriteLine(qhsd[3] * (n/2) + qhsd[2] * (n % 2));
    }
}