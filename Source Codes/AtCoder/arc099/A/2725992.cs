using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //????????????
        //k-1????1??(k-1)*2???r
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int minInd = a.ToList().IndexOf(1);
        Console.WriteLine((nk[0] - 1) / (nk[1] - 1) + ((nk[0] - 1) % (nk[1] - 1) != 0 ? 1 : 0));
    }
}