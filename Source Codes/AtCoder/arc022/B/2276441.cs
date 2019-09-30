using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using System.Threading.Tasks;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int max = 0;
        int lastInd = 0;
        int[] table = Enumerable.Repeat(-1, 100001).ToArray();
        for (int i = 0; i < a.Length; i++)
        {
            lastInd = Math.Max(lastInd, table[a[i]] + 1);
            table[a[i]] = i;
            max = Math.Max(max, i - lastInd + 1);
        }
        Console.WriteLine(max);



    }
}