using System;
using System.Linq;

namespace abc014_3
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] color = new int[1000100];
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                color[x[0]]++; color[x[1] + 1]--;
            }
            int max = 0; int now = 0;
            for (int i = 0; i < color.Count(); i++)
            {
                now += color[i];
                max = Math.Max(now,max);
            }
            Console.WriteLine(max);
        }
    }
}