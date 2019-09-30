using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC120B
{
    class MainClass
    {

        static int[] s;
        static int[] n;

        public static void Main(string[] args)
        {

            s = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);

            var g = Gcd(s[0],s[1]);

            var anslst = new List<int>();
            for(int i = 1; i <= g; i++)
            {
                if (g % i == 0)
                {
                    anslst.Add(i);
                }
            }

            anslst.Sort((x,y)=>y.CompareTo(x));
            Console.WriteLine(anslst[s[2] - 1]);
        }


        public static long Gcd(long a, long b)
        {
            long tmp;
            // a<b???
            if (a >= b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }

            if (a == 0)
            {
                return b;
            }

            tmp = a;
            a = b % a;
            b = tmp;
            return Gcd(a, b);

        }


        public static IEnumerable<long> PF(long n)
        {
            long i = 2;
            long tmp = n;

            while (i * i <= n) //?1
            {
                if (tmp % i == 0)
                {
                    tmp /= i;
                    yield return i;
                }
                else
                {
                    i++;
                }
            }
            if (tmp != 1) yield return tmp;//????????
        }
    }
}