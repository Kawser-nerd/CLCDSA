using System;
using System.Linq;

namespace B___Two_Colors_Card_Game
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Si = Enumerable.Range(1, N).Select(_ => Console.ReadLine()).ToArray();
            var M = int.Parse(Console.ReadLine());
            var Ti = Enumerable.Range(1, M).Select(_ => Console.ReadLine()).ToArray();

            var array = Si.Union(Ti).Distinct().ToArray();
            var SiGroup = Si.GroupBy(x => x).ToArray();
            var TiGroup = Ti.GroupBy(x => x).ToArray();
            int res = 0;

            foreach (var e in array)
            {
                var plus = SiGroup.Any(g => g.Key == e) ? SiGroup.Single(g => g.Key == e).Count() : 0;
                var minus = TiGroup.Any(g => g.Key == e) ? TiGroup.Single(g => g.Key == e).Count() : 0;
                res = Math.Max(res, plus - minus);
            }

            Console.WriteLine(res);
        }
    }
}