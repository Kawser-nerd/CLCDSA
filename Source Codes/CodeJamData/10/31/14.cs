using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RopeIntranet
{
    class Program
    {
        struct pair
        {
            public int a, b;
        }

        public static  int solve()
        {
            int n = Int32.Parse(Console.ReadLine());
            pair []p = new pair[n];
            for (int i = 0; i < n; i++)
            {
                String[] s = Console.ReadLine().Split(' ');
                p[i].a = Int32.Parse(s[0]);
                p[i].b = Int32.Parse(s[1]);
            }
            //for (int i = 0; i < n; i++)
            //{
            //    Console.WriteLine(p[i].a + ":" + p[i].b);
            //}
            int ret = 0;
            for (int i = 0; i < n; i++)
            {
                int a = p[i].a, b = p[i].b;
                for (int j = i + 1; j < n; j++)
                {
                    //Console.WriteLine((p[j].a < a && b < p[j].b) + " " + (p[j].a > a && b > p[j].b));
                    if ((p[j].a < a && b < p[j].b) ||
                        (p[j].a > a && b > p[j].b)
                        )
                    {
                        ret++;
                    }
                }
            }
            return ret;

        }
        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #" + (i + 1) + ": " + solve());
            }
        }
    }
}
