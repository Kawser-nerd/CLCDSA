using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_011_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int aMARI = 0;
            int ans = a[2];int kaishu = a[2];
            while (true)
            {
                if (kaishu +aMARI< a[0]) { break; }
                int u = kaishu;
                kaishu = ((kaishu + aMARI) / a[0]) * a[1];
                aMARI = (u + aMARI) % a[0];
                ans += kaishu;
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}