using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 1; i <= t; ++i)
            {
                Console.Write("Case #" + i + ":");
                var parts = Console.ReadLine().Split();
                ulong k = ulong.Parse(parts[0]);
                ulong c = ulong.Parse(parts[1]);
                ulong s = ulong.Parse(parts[2]);
                if (k > c * s) Console.Write(" IMPOSSIBLE");
                else
                    for (ulong ii = 0; ii < k; )
                    {
                        ulong p = 0;
                        for (ulong j = 0; j < c && ii < k; ++j, ++ii)
                            p = p * k + ii;
                        Console.Write(" " + (p + 1));
                    }
                Console.WriteLine();
            }
        }
    }
}
