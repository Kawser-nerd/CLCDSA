using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int cy = 0, cx = 0,ct =0;
            for (int i = 0; i < N; i++)
            {
                string[] p = Console.ReadLine().Split(' ');
                int t = int.Parse(p[0]);
                int x = int.Parse(p[1]);
                int y = int.Parse(p[2]);

                var d = Math.Abs(cy - y) + Math.Abs(cx - x);
                if(t - ct - d >= 0 && (t - ct - d) % 2 == 0)
                {

                }
                else
                {
                    Console.WriteLine("No");
                    return;
                }

                cx = x;
                cy = y;
                ct = t;
            }
            Console.WriteLine("Yes");
        }
    }
}