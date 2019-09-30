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
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var N = input[0];
            var M = input[1];
            var Q = input[2];
            var cityL = new int[M];
            var cityR = new int[M];
            for(var i = 0; i < M; i++)
            {
                input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                cityL[i] = input[0];
                cityR[i] = input[1];
            }

            var rails = new int[N + 1, N + 1];

            for(var i = 0; i < M; i++)
            {
                rails[cityL[i], cityR[i]]++;
            }

            for(var i = 1; i <= N; i++)
            {
                for(var j = 1; j <= N; j++)
                {
                    rails[i, j] += rails[i, j - 1];
                }
            }

            for(var i = 0; i < Q; i++)
            {
                input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                var p = input[0];
                var q = input[1];
                var ans = 0;
                for (var j = p; j <= q; j++)
                {
                    ans += rails[j, q] - rails[j, p - 1];
                }
                Console.WriteLine(ans);
            }
        }
    }
}