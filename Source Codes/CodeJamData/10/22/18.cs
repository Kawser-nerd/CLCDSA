using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {

            var cs = Console.ReadLine();
            int C = Convert.ToInt32(cs);
            for (int c = 0; c < C; c++)
            {
                var nkbt = Console.ReadLine().Split().ToArray();
                int N = Convert.ToInt32(nkbt[0]);
                int K = Convert.ToInt32(nkbt[1]);
                int B = Convert.ToInt32(nkbt[2]);
                int T = Convert.ToInt32(nkbt[3]);

                int[] X = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();
                int[] V = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();

                Debug.Assert(X.Length == N);
                Debug.Assert(V.Length == N);

                int res = 0;
                int fast = 0;
                int slow = 0;
                for (int i = N - 1; i >= 0 && fast < K; i--)
                {
                    if ((B - X[i]) <= (T * V[i])) // fast enough
                    {
                        res += slow; // must swap with slow ones before
                        fast++; // can reach the barn
                    }
                    else
                        slow++;
                }
                if (fast == K)
                    Console.WriteLine("Case #{0}: {1}", c + 1, res);
                else
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", c + 1);

            }
        }
    }
}
