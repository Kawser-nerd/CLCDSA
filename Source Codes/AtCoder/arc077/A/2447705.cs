using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC77_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var ans = new int[10000000];
            int left = 10000000 / 2;
            int right = left + 1;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == (n - 1) % 2)
                {
                    ans[left--] = a[i];
                }
                else
                {
                    ans[right++] = a[i];
                }
            }
            for (int i = left+1; i < right; i++)
            {
                Console.Write(ans[i] + " ");
            }
            Console.WriteLine();
        }
    }
}