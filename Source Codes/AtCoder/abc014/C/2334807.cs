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
            
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                str = Console.ReadLine().Split(' ');
                a[i] = int.Parse(str[0]);
                b[i] = int.Parse(str[1]);
            }

            int[] info = new int[1000001];
            for (int i = 0; i < n; i++) {
                info[a[i]]++;
                if (b[i]+1 <= 1000000) info[b[i]+1]--;
            }

            int m = 0;
            int p = 0;
            for (int i = 0; i <= 1000000; i++) {
                p += info[i];
                m = Math.Max(m, p);
            }

            Console.WriteLine(m);

            // Console.WriteLine(0);
        }
    }
}