using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        long[] ABC = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Console.WriteLine((((ABC[0] * ABC[1]) % 1000000007) * ABC[2]) % 1000000007);
    }
}