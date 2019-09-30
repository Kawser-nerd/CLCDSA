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
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            var min = Math.Min(a, b);
            var max = Math.Max(a, b);
            var ans = Math.Min(Math.Abs(a - b), 9 + min - max + 1);
            Console.WriteLine(ans);
        }
    }
}