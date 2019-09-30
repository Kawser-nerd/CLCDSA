using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC091D
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = line[0];
            int K = line[1];

            long ans = 0;
            for(int b = K + 1; b <= N; b++)
            {
                int ta = 0;
                if (K == 0) { ans += N; continue; }
                if (N % b == 0)
                {
                    ans += N / b * (b - K);
                    continue;
                }
                if (N % b >= K)
                {
                    ta = N % b - K + 1;
                }
                int tb = N / b * (b - K);
                ans += ta + tb;
            }

            Console.WriteLine(ans);
            Console.ReadKey();
        }
    }
}