using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] xy = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();

        int time = 0;
        int count = 0;
        int aind = 0;
        int bind = 0;
        int pos = 1;
        while (true)
        {
            if (pos < 0)
            {
                while (b[bind] < time)
                {
                    bind++;
                    if (bind >= b.Length)
                    {
                        goto end;
                    }
                }
                time = b[bind] + xy[1];
            }
            else
            {
                while (a[aind] < time)
                {
                    aind++;
                    if (aind >= a.Length)
                    {
                        goto end;
                    }
                }
                time = a[aind] + xy[0];
            }
            Debug.WriteLine($"{time} {aind} {bind}");
            count++;
            pos *= -1;
        }
        end:;
        Console.WriteLine(count / 2);
    }
}