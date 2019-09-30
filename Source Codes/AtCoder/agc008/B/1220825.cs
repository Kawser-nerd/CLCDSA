using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC008Repainting
{
    class Program
    {
        static void Main(string[] args)
        {
            int N, K;
            string[] vals = Console.ReadLine().Split(' ');
            N = int.Parse(vals[0]);
            K = int.Parse(vals[1]);
            int[] a = new int[N];
            vals = Console.ReadLine().Split(' ');
            for(int i=0; i < N; i++)
            {
                a[i] = int.Parse(vals[i]);
            }

            long[] cuma = new long[N + 1];
            for(int i=1; i <= N; i++)
            {
                cuma[i] = cuma[i - 1] + a[i - 1];
            }

            long[] cumb = new long[N + 1];
            for(int i=1; i <= N; i++)
            {
                cumb[i] = cumb[i - 1];
                if (a[i - 1] > 0)
                    cumb[i] += a[i - 1];
            }

            long maxScore = long.MinValue;
            long s;
            for(int i=0; i <= N - K; i++)
            {
                s = cuma[i + K] - cuma[i];
                if (s < 0)
                    s = 0;
                s += cumb[i] + (cumb[N] - cumb[i + K]);
                if (maxScore < s)
                    maxScore = s;
            }
            Console.WriteLine(maxScore);
        }
    }
}