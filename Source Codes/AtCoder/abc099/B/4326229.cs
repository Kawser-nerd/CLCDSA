using System;
using System.Linq;

namespace B.Stone_Monument
{
    class Program
    {
        static void Main(string[] args)
        {
            var ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = ab[0];
            int b = ab[1];

            //int NSum(int n) => n == 0 ? 0 : n + NSum(n - 1);

            Console.WriteLine(NSum((b - a) - 1) - a);
        }

        static int NSum(int n)
        {
            return n == 0 ? 0 : n + NSum(n - 1);
        }
    }
}