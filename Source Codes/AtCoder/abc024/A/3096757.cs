using System;
using System.Collections;
using System.Collections.Generic;
using System.Web;
namespace WpfApp1
{
    class program
    {
        static int Max(int a,int b)
        {
            if (a <= b) return b;
            else return a;
        }
        static void Main(string[] args)
        {
            int a, b, c, k, s, t;
            string[] f = Console.ReadLine().Split(' ');
            a = int.Parse(f[0]);
            b = int.Parse(f[1]);
            c = int.Parse(f[2]);
            k = int.Parse(f[3]);
            f = Console.ReadLine().Split(' ');
            s = int.Parse(f[0]);
            t = int.Parse(f[1]);
            if (s + t >= k)
            {
                Console.WriteLine(a * s + b * t - (s + t) * c);
            }
            else
            {
                Console.WriteLine(a * s + b * t);
            }
        }
    }
}