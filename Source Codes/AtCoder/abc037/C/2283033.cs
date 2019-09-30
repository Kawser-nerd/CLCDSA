using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc_037_C
{
    class Program
    {
        static void Main(string[] args)
        {
            //long ans = 0;
            long[] n = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
           // long bubun_sum =0;
            long[] s = new long[n[0]-n[1]+1];
            for (long i = 0; i < a.Length - n[1]+1 ; i++)
            {
                if (i == 0) { for (long i1 = 0; i1 < n[1]; i1++) { s[0] += a[i1]; } }
                else
                {
                   s[i]=s[i-1]-a[i-1]+a[i+n[1]-1];
                }
            }
            Console.WriteLine(s.Sum());
            Console.ReadLine();
        }
    }
}