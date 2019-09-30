using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            var a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            var count = a.Count(num => num != 0);
            var sum = a.Where(num => num != 0).Sum();
            Console.WriteLine(Math.Ceiling((double)sum / count));
        }
    }
}