using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Solve();
        }

        void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            var tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int a = tmp[0];
            int b = tmp[1];
            int k = int.Parse(Console.ReadLine());
            var p = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            bool shortest = true;
            var h = new HashSet<int>();
            h.Add(a);
            h.Add(b);
            for (int i = 0; i < p.Length; i++)
            {
                if (h.Contains(p[i]))
                {
                    shortest = false;
                    break;
                }
                else
                {
                    h.Add(p[i]);
                }
            }
            Console.WriteLine(shortest ? "YES" : "NO");
        }
    }
}