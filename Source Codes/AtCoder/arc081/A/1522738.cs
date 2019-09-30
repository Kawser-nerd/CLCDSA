using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC081
{
    public class C
    {
        private void Run()
        {
            Console.ReadLine();
            var g = Console.ReadLine().Trim().Split().Select(long.Parse)
                .GroupBy(x => x)
                .Where(x => x.Count() > 1)
                .SelectMany(x => Enumerable.Repeat(x.Key, x.Count() / 2))
                .OrderByDescending(x => x)
                .ToArray();
            Console.WriteLine(g.Length < 1 ? 0 : g[0] * g[1]);
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}