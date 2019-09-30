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
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int A = s[0];
            int B = s[1];
            int K = s[2];

            for(int i = 1; i <= B; i++)
            {
                if(A<=i && i <= B)
                {
                    if (i - A < K || B - i< K)
                    {
                        Console.WriteLine(i);
                    }
                }
            }
        }
    }
}