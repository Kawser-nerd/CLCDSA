using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var Q = int.Parse(Console.ReadLine());
            var simi = new int[100001];
            for (int i = 1; i < 100001; i++)
            {
                if (i % 2 == 0)
                {
                    simi[i] = simi[i - 1];
                }else
                {
                    if (IsPrime(i) && IsPrime((i + 1) / 2))
                    {
                        simi[i] = simi[i - 1] + 1;
                    }else
                    {
                        simi[i] = simi[i - 1];
                    }
                }
            }

            for (int i = 0; i < Q; i++)
            {
                var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                Console.WriteLine(simi[input[1]] - simi[input[0] - 1]);
            }
        }

        public static bool IsPrime(int num)
        {
            if (num < 2) return false;
            else if (num == 2) return true;
            else if (num % 2 == 0) return false;

            for (int i = 3; i <= Math.Sqrt(num); i += 2)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}