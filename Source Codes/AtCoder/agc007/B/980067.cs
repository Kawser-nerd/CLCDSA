using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AGC007
{
    public class B
    {
        private void Run()
        {
            var N = int.Parse(Console.ReadLine().Trim());
            var P = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();

            var dx = new int[N];

            for (int i = 0; i < P.Length; i++)
            {
                dx[P[i] - 1] = i;
            }
            var A = new int[N];
            var B = new int[N];
            for (int i = 0; i < N; i++)
            {
                A[i] = 1 + N * i + dx[i];
                B[i] = 1000000000 - N * i;
            }
            Console.WriteLine(string.Join(" ", A));
            Console.WriteLine(string.Join(" ", B));
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}