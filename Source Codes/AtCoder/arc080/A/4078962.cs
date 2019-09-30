using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long[] a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        long multitwo = 0;
        long multifour = 0;

        for(long i = 0; i < n; i++)
        {
            if (a[i] % 4 == 0)
            {
                multifour++;
            }
            else if(a[i] % 2 ==0)
            {
                multitwo++;
            }
        }

        if(multitwo + multifour * 2 >= n)
        {
            Console.WriteLine("Yes");
        }
        else if (multitwo == 0 && multifour * 2 + 1 >= n)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}