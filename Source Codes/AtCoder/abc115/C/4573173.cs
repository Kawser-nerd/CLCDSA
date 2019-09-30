using System;
using System.Linq;

namespace ABC115C
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = line[0]; int K = line[1];

            int[] h = new int[N];

            for(var i = 0; i < N; i++)
            {
                h[i] = int.Parse(Console.ReadLine());
            }

            Array.Sort(h);
            
            int hlen = 1000000000;

            for(var i = 0; i < N - K + 1; i++)
            {
                int hmin = h[i]; int hmax = h[i + K - 1];
                if(hmax - hmin < hlen)
                {
                    hlen = hmax - hmin;
                }
            }

            Console.WriteLine(hlen);
        }
    }
}