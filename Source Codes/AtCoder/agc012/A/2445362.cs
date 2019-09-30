using System;
using System.Linq;
namespace AGC012A
{
    class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Array.Sort(a);
            long ans = 0;
            for (int i = 2; i <= 2 * n; i += 2)
                ans += a[3 * n - i];
            Console.WriteLine(ans);
        }
    }
}