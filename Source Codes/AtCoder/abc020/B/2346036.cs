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
            var tmp = Console.ReadLine().Split();
            int n = int.Parse(tmp[0] + tmp[1]);
            Console.WriteLine((2 * n).ToString());

        }
    }
}