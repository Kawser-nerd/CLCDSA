using System;
using System.Collections.Generic;
using System.Linq;

namespace app
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] str;
            // int N = int.Parse(Console.ReadLine());
            // str = Console.ReadLine().Split(' ');
            // int N = int.Parse(str[0]), M = int.Parse(str[1]), D = int.Parse(str[2]);
            
            str = Console.ReadLine().Split(' ');
            int n = int.Parse(str[0]);
            int X = int.Parse(str[1]);
            str = Console.ReadLine().Split(' ');
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = int.Parse(str[i]);
            }

            int ans = 0;
            int x = X;
            for (int i = 0;i < n; i++) {
                if (x % 2 == 1) {
                    ans += a[i];
                }
                x /= 2;
            }

            Console.WriteLine(ans);

            // Console.WriteLine(0);
        }
    }
}