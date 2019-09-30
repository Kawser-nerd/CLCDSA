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
            int n, s, t, w, a, ans = 0;
            string[] f = Console.ReadLine().Split(' ');
            n = int.Parse(f[0]);
            s = int.Parse(f[1]);
            t = int.Parse(f[2]);
            w = int.Parse(Console.ReadLine());
            if (s <= w && w <= t) ans++;
            for(int i = 1; i < n; i++)
            {
                a = int.Parse(Console.ReadLine());
                w += a;
                if (s <= w && w <= t) ans++;
            }
            Console.WriteLine(ans);
        }
    }
}