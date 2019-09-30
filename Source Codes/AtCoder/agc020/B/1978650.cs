using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    void solve()
    {
        int k = int.Parse(Console.ReadLine());
        int[] a = new int[k];
        int idx = 0;
        long max = 2, min = 2;
        bool f_invalid = false;
        string[] buff = Console.ReadLine().Split(' ');
        for (int i = 0; i < k; ++i)
        {
            int p = int.Parse(buff[i]);
            if (idx == 0 || a[idx - 1] != p)
            {
                a[idx++] = p;
            }
        }

        for (int i = idx - 1; i >= 0; --i)
        {
            int g = a[i];
            min = ((min - 1) / g) * g + g;
            max = (max / g) * g + g - 1;
            if (min > max)
            {
                f_invalid = true;
                break;
            }
        }
        if (f_invalid)
        {
            Console.WriteLine("-1");
        }
        else
        {
            Console.WriteLine(min + " " + max);
        }
    }

    public static int Main()
    {
        bool loop = false;
#if ES_DEBUG
        loop = true;
#endif
        do
        {
            new Program().solve();
        } while (loop);
        return 0;
    }
}