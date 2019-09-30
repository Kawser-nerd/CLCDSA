using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace maki
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            if (n == 1) { string k = Console.ReadLine(); Console.WriteLine(k); }
            else
            {
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                {
                    a[i] = int.Parse(Console.ReadLine());
                }

                if (n == 4) { Array.Sort(a); Console.WriteLine(Math.Min(Math.Min(Math.Max(a[0] + a[3], a[1] + a[2]), Math.Max(a[0] + a[2], a[3] + a[1])), Math.Max(a[1] + a[0]+a[2], a[3] ))); }
                else if (n == 3) { Array.Sort(a); Console.WriteLine(Math.Min(Math.Max(a[2], a[1] + a[0]), Math.Max(a[1], a[2] + a[0]))); }
                else{  Console.WriteLine(Math.Max(a[1], a[0])); }
            }    Console.ReadLine();
            
        }
    }
}