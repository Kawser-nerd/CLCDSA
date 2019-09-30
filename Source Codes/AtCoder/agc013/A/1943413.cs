using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] ABC = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int status = 0;
        int last = 0;
        int res = 1;
        foreach (var item in ABC)
        {
            switch (status)
            {
                case 0:
                if (last != 0 && last != item)
                {
                    if (last > item) status = -1;
                    if (last < item) status = 1;
                }
                break;
                case 1:
                if (last > item)
                {
                    status = 0;
                    res++;
                }
                break;
                case -1:
                if (last < item)
                {
                    status = 0;
                    res++;
                }
                break;
            }
            last = item;
        }
        Console.WriteLine(res);
    }
}