using System;
using System.Linq;

namespace arc015_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] ret = new int[6];
            for (int i = 0; i < n; i++)
            {
                double[] x = Console.ReadLine().Split().Select(double.Parse).ToArray();
                if (x[0] >= 35)
                {
                    ret[0]++;
                }
                else if (x[0] >= 30)
                {
                    ret[1]++;
                }
                else if (x[0] >= 25)
                {
                    ret[2]++;
                }
                else if (0 > x[0])
                {
                    ret[5]++;
                }
                if (x[1] >= 25)
                {
                    ret[3]++;
                }
                else if (x[0] >= 0 && 0 > x[1])
                {
                    ret[4]++;
                }
            }
            for (int i = 0; i < 5; i++)
            {
                Console.Write(ret[i] + " ");
            }
            Console.WriteLine(ret[5]);
        }
    }
}