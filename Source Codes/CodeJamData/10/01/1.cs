using System;
using System.Collections.Generic;
using System.IO;

public class Myon
{
    Myon() { }
    public static int Main()
    {
        return new Myon().calc();
    }

    public int calc()
    {
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] st = Console.ReadLine().Split(' ');
            int t1 = int.Parse(st[0]);
            int t2 = int.Parse(st[1]);
            int j;
            for (j = t1 - 1; j >= 0; j--) if ((t2 >> j) % 2 == 0) break;
            if (j == -1) Console.WriteLine("Case #" + (i + 1) + ": ON");
            else Console.WriteLine("Case #" + (i + 1) + ": OFF");
        }
        return 0;
    }
}