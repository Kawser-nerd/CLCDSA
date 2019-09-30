using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC028_D
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inps = Console.ReadLine().Split(' ');
            int N = int.Parse(inps[0]);
            int K = int.Parse(inps[1]);

            Console.WriteLine(med(N, K));
        }

        static double med(int N, int K)
        {
            long denom = (long)N * N * N;
            long numer = (long)1 + (long)3 * (K - 1 + N - K) + (long)6 * (N - K) * 1 * (K - 1);

            return (double)numer / denom;
        }
    }
}