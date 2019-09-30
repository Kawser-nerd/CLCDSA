using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_015_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] s = new int[6];
            for (int i = 0; i < n; i++)
            {
                double[] a = Console.ReadLine().Split().Select(Double.Parse).ToArray();
                if (a[0] >= 35) { s[0]++; }
                else if (a[0] >= 30) { s[1]++; }
                else if (a[0] >= 25) { s[2]++; }
                if (a[1] >= 25) { s[3]++; }
                if (a[0] >= 0 && a[1] < 0) { s[4]++; }
                if (a[0] < 0) { s[5]++; }
            }
            Console.WriteLine("{0} {1} {2} {3} {4} {5}",s[0],s[1],s[2],s[3],s[4],s[5]);
            Console.ReadLine(); }
    }
}