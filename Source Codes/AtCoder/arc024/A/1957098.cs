using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
        int[] b = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
        int aind = 0;
        int bind = 0;

        int res = 0;
        while (aind < a.Length && bind < b.Length)
        {
            if(a[aind] == b[bind])
            {
                aind++;
                bind++;
                res++;
            }
            else if(a[aind] > b[bind])
            {
                bind++;
            }
            else if(a[aind] < b[bind])
            {
                aind++;
            }
        }
        Console.WriteLine(res);
    }
}