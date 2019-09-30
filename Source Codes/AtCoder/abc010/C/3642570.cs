using System;
using System.Collections.Generic;

namespace Atcoder
{
    class Program
    {
        static int txa, tya, txb, tyb, t, v, n ;
        static int[] x, y;
        static double disAtoI,disItoB;

        static string ans = "NO";
        static void Main(string[] arg)
        {
            Solve();
       //     Console.ReadLine();
        }
        static void Solve()
        {
            string[] vs = Console.ReadLine().Split();
            txa = int.Parse(vs[0]);
            tya = int.Parse(vs[1]);
            txb = int.Parse(vs[2]);
            tyb = int.Parse(vs[3]);
            t = int.Parse(vs[4]);
            v = int.Parse(vs[5]);
            n = int.Parse(Console.ReadLine());

            x = new int[n];
            y = new int[n];
            for (int i = 0; i < n; i++)
            {
                vs = Console.ReadLine().Split();
                x[i] = int.Parse(vs[0]);
                y[i] = int.Parse(vs[1]);
            }

            for (int i = 0; i < n; i++)
            {
                disAtoI = Math.Sqrt(Math.Abs(x[i] - txa) * Math.Abs(x[i] - txa)
                               + Math.Abs(y[i] - tya) * Math.Abs(y[i] - tya));
                disItoB = Math.Sqrt(Math.Abs(x[i] - txb) * Math.Abs(x[i] - txb)
                               + Math.Abs(y[i] - tyb) * Math.Abs(y[i] - tyb));
                if (disAtoI+disItoB<=t*v)
                {
                    ans = "YES";break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}