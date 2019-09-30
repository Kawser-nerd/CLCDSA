using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC100C
{
    static class MainClass
    {

        public static void Main(string[] args)
        {


            int N = int.Parse(Console.ReadLine());
            var alst = Console.ReadLine().Split(' ');//.AsQueryable();//.Cast<int?>();
            int ans = 0;


            foreach (string a in alst)
            {
                ans += PF2(int.Parse(a));
            }

            Console.WriteLine(ans);
          

            return;


        }

        public static int PF2(int n)
        {
            int ans = 0;
            while (n > 0)
            {
                int res = n % 2;
                if (res == 0)
                {
                    ans++;
                    n = n / 2;
                }
                else
                {
                    n = 0;
                }
            }


            return ans;
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