using System;
using System.Linq;

namespace ABC084_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var Q = int.Parse(Console.ReadLine());
            int n = 100000;
            bool[] p = new bool[n + 1];
            p[1] = true;
            for (int i = 2; i <= (int)Math.Sqrt(n); i++)
            {
                if (p[i]) continue;
                for (int j = 2; j * i <= n; j++)
                    p[i * j] = true;
            }

            int[] l = new int[n + 1];
            for (int i = 1; i <= n; i++)
                l[i] = l[i - 1] + (!p[i] && !p[(i + 1) / 2] ? 1 : 0);

            for (int i = 0; i < Q; i++)
            {
                var lr = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Console.WriteLine(l[lr[1]] - l[lr[0]-1]);
            }
        }
    }
}