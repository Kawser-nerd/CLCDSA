using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nck = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] t = Enumerable.Repeat(0, nck[0]).Select(_ => int.Parse(Console.ReadLine())).OrderBy(x => x).ToArray();

        int count = 0;
        int busfinish = -1;
        int buscapa = nck[1];
        for (int i = 0; i < t.Length; i++)
        {
            if (t[i] <= busfinish && 0 < buscapa)
            {
                buscapa--;
            }
            else
            {
                count++;
                busfinish = t[i] + nck[2];
                buscapa = nck[1] - 1;
            }
        }
        Console.WriteLine(count);
    }
}