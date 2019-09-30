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
            int n = int.Parse(tmp[0]);
            int x = int.Parse(tmp[1]);

            var a = Console.ReadLine().Split().Select(t => int.Parse(t)).ToArray();


            bool[] exists = new bool[n];

            int i = 0;
            int sum = 0;
            while (true)
            {
                int t = x % 2;
                sum += a[i] * t;
                i++;
                x /= 2;

                if (x == 0)
                    break;

            }
            Console.WriteLine(sum);

        }

    }
}