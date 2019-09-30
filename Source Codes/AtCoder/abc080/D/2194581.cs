using System;
using System.Linq;

namespace abc080_d
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] channels = new int[x[1],100010];
            for (int i = 0; i < x[0]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray(); a[2]--;
                channels[a[2],a[0]]++; channels[a[2],a[1]]--;
            }
            int[] b = new int[100010];
            for (int i = 0; i < 100010; i++)
            {
                for (int j = 0; j < x[1]; j++)
                {
                    if (channels[j,i] == 1) b[i - 1]++;
                    else b[i] += channels[j,i];
                }
            }
            int now = 0; int max = 0;
            for (int i = 0; i < 100010; i++)
            {
                now += b[i];
                max = Math.Max(now,max);
            }
            Console.WriteLine(max);
        }
    }
}