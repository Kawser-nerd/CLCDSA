using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static long N, K;
    static long[] a, b;

    public static void Main(string[] args)
    {
        //checked
        {
            {
                var input = Console.ReadLine().Split();
                N = long.Parse(input[0]);
                K = long.Parse(input[1]);
            }
            a = new long[N];
            b = new long[N];
            for (int i = 0; i < N; i++)
            {
                var input = Console.ReadLine().Split();
                a[i] = int.Parse(input[0]);
                b[i] = int.Parse(input[1]);
            }

            var slot = new long[a.Max()+1];

            for (int i = 0; i < N; i++)
            {
                slot[a[i]] += b[i];
            }
            
            long k = 0;
            long ans;
            for (ans = 0; ans < slot.Length; ans++)
            {
                k += slot[ans];
                if (k >= K)
                    break;
            }

            Console.WriteLine(ans);
        }
    }
}