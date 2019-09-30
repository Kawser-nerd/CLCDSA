using System;
using System.Linq;

namespace arc092_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] redx = new int[n]; int[] redy = new int[n];
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                redx[i] = x[0]; redy[i] = x[1];
            }
            int[] bluex = new int[n]; int[] bluey = new int[n];
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                bluex[i] = x[0]; bluey[i] = x[1];
            }
            Array.Sort(redx,redy); Array.Reverse(redx); Array.Reverse(redy);
            Array.Sort(bluex,bluey);
            bool[] used = new bool[n]; int ret = 0;
            for (int i = 0; i < n; i++)
            {
                int wheremin = -1; int minbluey = int.MaxValue;
                for (int j = 0; j < n; j++)
                {
                    if (!used[j] && redx[i] < bluex[j] && redy[i] < bluey[j])
                    {
                        if (minbluey > bluey[j])
                        {
                            wheremin = j;
                            minbluey = bluey[j];
                        }
                    }
                }
                if (wheremin >= 0)
                {
                    used[wheremin] = true; ret++;
                }
            }
            Console.WriteLine(ret);
        }
    }
}