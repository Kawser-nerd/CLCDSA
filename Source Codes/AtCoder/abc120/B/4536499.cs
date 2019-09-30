using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC120
{
    class Program
    {
        static void Main(string[] args)
        {
            B();
        }

        static void B()
        {
            var ABK = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var A = ABK[0];
            var B = ABK[1];
            var K = ABK[2];

            var k = A > B ? A : B;
            var a = new List<int>();
            for (var i = 1; i <= k; i++)
            {
                if (A % i == 0 && B % i == 0)
                    a.Add(i);
            }
            Console.WriteLine(a.OrderByDescending(x => x).ToList()[K-1]);
        }
    }
}