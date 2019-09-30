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
            var tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int c = tmp[2];
            int min = Math.Min(tmp[0], tmp[1]);
            int count = c / min;
            Console.WriteLine(count);
        }
    }
}