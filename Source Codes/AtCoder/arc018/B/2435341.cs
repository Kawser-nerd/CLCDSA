using System;
using System.Linq;

namespace arc018_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[,] point = new long[n, 2];
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                point[i, 0] = x[0]; point[i, 1] = x[1];
            }
            int ret = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        long area = Math.Abs(
                            (point[j, 0] - point[i, 0]) * (point[k, 1] - point[j, 1]) -
                            (point[j, 1] - point[i, 1]) * (point[k, 0] - point[j, 0]));
                        if (area % 2 == 0 && area > 0) ret++;
                    }
                }
            }
            Console.WriteLine(ret);
        }
    }
}