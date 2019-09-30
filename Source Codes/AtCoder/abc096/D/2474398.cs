using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Solve();
        }

        void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            var ansNumbers = Enumerable.Range(1, 55555)
                .Where(x => IsPrimeNumber(x))
                .Where(x => x % 5 == 1)
                .Take(n)
                .ToArray();
            Console.WriteLine(string.Join(" ", ansNumbers));


        }

        bool IsPrimeNumber(int n)
        {
            if (n <= 1)
                return false;
            for (int i = 2; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}