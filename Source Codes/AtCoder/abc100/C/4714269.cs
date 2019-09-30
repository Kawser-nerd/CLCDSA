using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static bool isOdd(int a)
    {
        return ((a & 1) == 0) ? false : true;
    }
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        for (int i = 0; i < N; i++)
            a[i] = int.Parse(s[i]);
        int ctr=0;
        while (true)
        {
            bool OddOnly = true;
            for (int i = 0; i < N; i++)
            {
                if (!isOdd(a[i]))
                {
                    OddOnly = false;
                    break;
                }
            }
            if (OddOnly)
                break;
            for (int i = 0; i < N; i++)
            {
                while ((a[i] & 1) == 0)
                {
                    a[i] >>= 1;
                    ctr++;
                }
            }
        }
        Console.WriteLine(ctr);
    }
}