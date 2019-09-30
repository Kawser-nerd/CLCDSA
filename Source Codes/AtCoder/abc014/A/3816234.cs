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
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            Console.WriteLine(a % b == 0 ? 0 : b - (a % b));
        }

    }
}