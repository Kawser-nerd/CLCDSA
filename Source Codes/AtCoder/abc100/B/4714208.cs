using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static int F(int s)
    {
        int ctr = 0;
        while (s % 100 == 0)
        {
            ctr++;
            s /= 100;
        }
        return ctr;
    }

    public static void Main()
    {
        var s = Console.ReadLine().Split(' ');
        int D = int.Parse(s[0]);
        int N = int.Parse(s[1]);
        int ctr = 0;
        for (int i = 1; ; i++)
        {
            if (D == F(i))
                ctr++;
            if (ctr == N)
            {
                Console.WriteLine(i);
                break;
            }
        }
    }
}