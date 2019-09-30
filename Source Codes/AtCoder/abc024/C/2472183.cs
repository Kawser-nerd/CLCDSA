using System;
using System.Linq;

namespace abc024_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] movemin = new int[x[1]]; int[] movemax = new int[x[1]];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                movemin[i] = a[0]; movemax[i] = a[1];
            }
            for (int i = 0; i < x[2]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                if (a[0] < a[1])
                {
                    int ret = 0;
                    for (; a[0] < a[1]; ret++)
                    {
                        if (movemin[ret] <= a[0] && a[0] <= movemax[ret]) a[0] = movemax[ret];
                    }
                    Console.WriteLine(ret);
                }
                else
                {
                    int ret = 0;
                    for (; a[0] > a[1]; ret++)
                    {
                        if (movemin[ret] <= a[0] && a[0] <= movemax[ret]) a[0] = movemin[ret];
                    }
                    Console.WriteLine(ret);
                }
            }
        }
    }
}