using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoroSort
{
    class GoroSort
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                new GoroSort().Solve();
            }
        }

        private void Solve()
        {
            var n = int.Parse(Console.ReadLine());
            var a = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s) - 1).ToArray();

            var t = 0;
            var done = new bool[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                if (!done[i])
                {
                    var cycle = 0;
                    int j = i;
                    do
                    {
                        done[j] = true;
                        j = a[j];
                        cycle++;
                    }
                    while (i != j);
                    if (cycle > 1)
                        t += cycle;
                }
            }

            Console.WriteLine("{0}.000000", t);
        }
    }
}
