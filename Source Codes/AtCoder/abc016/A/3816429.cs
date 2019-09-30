using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        private const string V = "nO";

        static void Main(string[] args)
        {
            new Program().Solve();
        }

        void Solve()
        {
            var tmp = Console.ReadLine().Split();
            int m = int.Parse(tmp[0]);
            int d = int.Parse(tmp[1]);
            Console.WriteLine(m % d == 0 ? "YES" : "NO");

        }

    }
}