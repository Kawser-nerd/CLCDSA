using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] abkl = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Console.WriteLine(abkl[1] * (abkl[2] / abkl[3]) + Math.Min(abkl[0] * (abkl[2] % abkl[3]), abkl[1]));
    }
}