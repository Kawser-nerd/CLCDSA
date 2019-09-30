using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC026B
{
    class Program
    {
        static Dictionary<long, int> primeFactors;
        static List<long> keys;
        static long sum = 0;
        static long N;

        static void Main(string[] args)
        {
            N = long.Parse(Console.ReadLine());
            primeFactors = new Dictionary<long, int>();

            long i = 2;
            long tmp = N;
            while (i * i <= N)
            {
                if (tmp % i == 0)
                {
                    tmp /= i;
                    if (primeFactors.ContainsKey(i))
                    {
                        primeFactors[i]++;
                    }
                    else
                    {
                        primeFactors[i] = 1;
                    }
                }
                else
                {
                    i++;
                }
            }
            if(tmp != 1)
            {
                if (primeFactors.ContainsKey(tmp))
                {
                    primeFactors[tmp]++;
                }
                else
                {
                    primeFactors[tmp] = 1;
                }
            }

            keys = new List<long>();
            foreach (var k in primeFactors.Keys)
            {
                //Console.WriteLine("prime factor:{0}", k);
                keys.Add(k);
            }

            calc(1, 0);

            if(sum > N)
            {
                Console.WriteLine("Abundant");
            }
            else if(sum < N)
            {
                Console.WriteLine("Deficient");
            }
            else
            {
                Console.WriteLine("Perfect");
            }

        }

        static void calc(long factor, int i)
        {
            if (i < keys.Count)
            {
                //Console.WriteLine("loop: {0}^{1}", keys[i], primeFactors[keys[i]]);
                for (int j = 0; j <= primeFactors[keys[i]]; j++)
                {
                    calc(factor, i + 1);
                    factor *= keys[i];
                }
            }
            else
            {
                //Console.WriteLine("factor:{0}", factor);
                if(factor != N)
                    sum += factor;
            }
        }

    }
}