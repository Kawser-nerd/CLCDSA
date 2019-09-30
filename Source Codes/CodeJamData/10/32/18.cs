using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ1
{
    class B
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int T = int.Parse(input);
            for (int t = 1; t <= T; t++)
            {
                input = Console.ReadLine();
                string[] sp = input.Split(' ');
                long L = long.Parse(sp[0]), P = long.Parse(sp[1]), C = long.Parse(sp[2]);
                int res = 1;
                while (L * C < P)
                {
                    L *= C;
                    res++;
                }

                Console.WriteLine("Case #{0}: {1}", t, (int)  Math.Ceiling( Math.Log(res,2.0) ));
            }
        }
    }
}
