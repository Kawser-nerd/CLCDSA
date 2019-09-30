using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kyoupuro1
{
    class Program
    {

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            var ps = GetPNLs(N);
            var sisuu = new int[ps.Count()];

            for (int m = 1; m <= N; m++)
            {
                for (int i = 0; i < ps.Count; i++)
                {
                    sisuu[i] += E(ps[i], m);
                }
            }
            int dob = sisuu.Count(x => x >= 2);
            int f = sisuu.Count(x => x >= 4);
            int ft = sisuu.Count(x => x >= 14);
            int tf = sisuu.Count(x => x >= 24);
            int sf = sisuu.Count(x => x >= 74);

            int res =
                C(f, 2) * A(dob - 2)
                + tf * A(dob - 1)
                + sf
                + ft * A(f - 1);
            Console.WriteLine(res);
        }

        static int A(int x)
        {
            if (x < 0) return 0;
            else return x;
        }

        static List<int> GetPNLs(int max)
        {
            List<int> prime = new List<int>();
            if (max <= 1) return new List<int> {2};
            for (int i = 2; i <= max; i++)
            {
                bool isPrime = true;
                foreach (var p in prime)
                {
                    if (i % p == 0 && i != p)
                    {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) prime.Add(i);
            }
            return prime;
        }

        static int E(int prime, int n)
        {
            int k = n;
            int c = 0;
            while (k % prime == 0)
            {
                k = k / prime;
                c++;
            }
            return c;
        }

        static int C(int a, int b)
        {
            if (a < b) return 0;
            return F(a) / (F(b) * F(a - b));
        }

        static int F(int n)
        {
            if (n > 1)
                return F(n - 1) * n;
            else
                return 1;
        }
    }
}