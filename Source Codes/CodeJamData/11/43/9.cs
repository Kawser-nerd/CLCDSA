using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R2ProblemCLarge
{
    class Program
    {
        static bool check(long x)
        {
            long cur = x;
            for (int i = 2; i * i <= x; ++i)
            {
                if (cur % i == 0) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            List<long> prime = new List<long>();
            for (int i = 2; i <= 1000000; ++i)
            {
                if (check(i)) prime.Add(i);
            }
                for (int curCase = 0; curCase < totalCase; ++curCase)
                {
                    long n = Convert.ToInt64(Console.ReadLine());
                    int ans = 0;
                    for (int i = 0; i < prime.Count; ++i)
                    {
                        if (prime[i] > n) break;
                        int cnt = 0;
                        long cur = 1;
                        while (cur <= n)
                        {
                            cur *= prime[i];
                            cnt++;
                        }
                        ans += cnt - 2;
                    }
                    if (n == 1)
                    {
                        Console.WriteLine("Case #{0}: {1}", curCase + 1, 0);
                    }
                    else
                    {
                        Console.WriteLine("Case #{0}: {1}", curCase + 1, ans + 1);
                    }
                }
        }
    }
}
