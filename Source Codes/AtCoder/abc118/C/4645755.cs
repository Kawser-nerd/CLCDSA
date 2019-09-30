using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cShaprTest
{
    class Program
    {
        public static int N { get; private set; }
        public static int A { get; private set; }
        public static int B { get; private set; }
        public static int C { get; private set; }

        private static int max;
        private static int[] l;

        static void Main(string[] args)
        {
            var NABC = Console.ReadLine().Split().Select(int.Parse).ToArray();
            N = NABC[0];

            var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            var res = input[0];
            for (var i = 0; i < N; i++)
            {
                res = Gcd(res, input[i]);
            }
            Console.WriteLine(res);
        }
        
        public static int Gcd(int a, int b)
        {
            if (b == 0) return a;
           return Gcd(b, a % b);
        }
    }
}