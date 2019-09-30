using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_020_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ans = n[0];
            int u = 0;
            int[] a = new int[n[0]];
            for (int i = 0; i < n[0]; i++) { a[i] = int.Parse(Console.ReadLine()); }
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    u = 0;
                    if (i == j) { continue; }
                    for (int k = 0; k < n[0]; k++)
                    {
                        if (k % 2 == 0) { if (i != a[k]) { u++; } }
                        else { if (j != a[k]) { u++; } }
                    }
                    ans = Math.Min(ans, u);

                }
            }
            Console.WriteLine(ans*n[1]);
            Console.ReadLine();
        }
    }
}