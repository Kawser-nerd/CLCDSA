using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_056_A
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long ama = (a[2] / a[3]) * a[1] + (a[2] % a[3]) * a[0];
            long min = (a[2] / (int)a[3] + 1) * a[1];
            Console.WriteLine(Math.Min(ama, min));
        }
    }
}