using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            long t = long.Parse(s[1]);
            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var d = new int[n - 1];
            long sum = t;
            for (int i = 0; i < n - 1; i++)
            {
                sum += a[i + 1] - a[i] >= t  ? t : a[i + 1] - a[i];
            }

            Console.WriteLine(sum);
        }
    }
}