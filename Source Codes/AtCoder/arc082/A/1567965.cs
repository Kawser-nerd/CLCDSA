using System;
using System.Linq;
 
namespace arc082_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = new int[100010];
            for (int i = 0; i < n; i++) a[x[i]]++;
            int max = a[0] + a[1] + a[2];
            int now = a[0] + a[1] + a[2];
            for (int i = 3; i < 100010; i++)
            {
                now -= a[i - 3]; now += a[i];
                max = Math.Max(max, now);
            }
            Console.WriteLine(max);
        }
    }
}