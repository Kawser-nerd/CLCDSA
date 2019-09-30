using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        int a = 5000;
        int b = 5000;
        int c = 5000;
        for (int i = 0; i < nk[0]; i++)
        {
            a = b;
            b = c;
            c = int.Parse(Console.ReadLine());

            if (a + b + c < nk[1])
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
        Console.WriteLine(-1);

    }
}