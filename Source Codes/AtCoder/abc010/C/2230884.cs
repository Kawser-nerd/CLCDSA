using System;
using System.Linq;

namespace abc010_3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int canwalk = x[4] * x[5];
            int n = int.Parse(Console.ReadLine());
            bool ret = false;
            for (int i = 0; i < n; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                double kyori1 =
                    Math.Pow(x[0] - a[0],2) +
                    Math.Pow(x[1] - a[1],2);
                double kyori2 =
                    Math.Pow(x[2] - a[0],2) +
                    Math.Pow(x[3] - a[1],2);
                kyori1 = Math.Sqrt(kyori1); kyori2 = Math.Sqrt(kyori2);
                if (kyori1 + kyori2 <= canwalk) ret = true;
            }
            Console.WriteLine(ret ? "YES" : "NO");
        }
    }
}