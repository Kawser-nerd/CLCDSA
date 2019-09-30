using System;
using System.Linq;

namespace Bmondai
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var n = N;
            var sum = 0;
            while (n > 0)
            {
                sum += n % 10;
                n = n / 10;
            }
            if (N % sum == 0)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}