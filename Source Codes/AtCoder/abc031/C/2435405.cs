using System;
using System.Linq;

namespace abc031_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = int.MinValue;
            for (int i = 0; i < n; i++)
            {
                int maxpoint = int.MinValue;
                int maxat = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    int tak = 0; int aok = 0;
                    for (int k = Math.Min(i, j); k <= Math.Max(i, j); k++)
                    {
                        if ((k - Math.Min(i, j)) % 2 == 0) tak += x[k];
                        else aok += x[k];
                    }
                    if (aok > maxpoint)
                    {
                        maxpoint = aok;
                        maxat = j;
                    }
                }
                int now = 0;
                for (int k = Math.Min(i, maxat); k <= Math.Max(i, maxat); k++)
                {
                    if ((k - Math.Min(i, maxat)) % 2 == 0) now+= x[k];
                }
                ret = Math.Max(ret, now);
            }
            Console.WriteLine(ret);
        }
    }
}