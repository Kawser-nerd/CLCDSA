using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());
            int Y = int.Parse(Console.ReadLine());

            if (N <= K)
            {
                Console.WriteLine(N*X);
            }
            else
            {
                Console.WriteLine(
                    X*K+Y*(N-K) 
                    );
            }
        }
    }
}