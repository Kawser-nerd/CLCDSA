using System;
using System.Linq;

namespace agc004_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = x[0];
            long[,] time = new long[n,n];
            for (int i = 0; i < n; i++)//??????
            {
                int min = a[i];
                for (int j = 0; j < n; j++)//??????
                {
                    min = Math.Min(min,a[(i - j + n) % n]);
                    time[i,j] = min;
                }
            }
            long ret = long.MaxValue;
            for (long i = 0; i < n; i++)
            {
                long now = 0;
                for (int j = 0; j < n; j++)
                {
                    now += time[j,i];
                }
                ret = Math.Min(ret,now + x[1] * i);
            }
            Console.WriteLine(ret);
        }
    }
}