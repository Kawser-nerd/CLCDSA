using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.AtCoder_Crackers
{
    class Program
    {
        static void Main(string[] args)
        {
            var N_K = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = N_K[0];
            int K = N_K[1];
            var ans = int.MaxValue;

            if (N % K == 0) ans = 0;
            else ans = 1;

            Console.WriteLine(ans);
        }
    }
}