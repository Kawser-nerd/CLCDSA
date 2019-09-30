using System;
using System.Linq;

namespace abc030_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = 0;
            int now = 0;
            int alooked = 0;
            int blooked = 0;
            bool flag = true;
            while (flag)
            {
                for (; alooked < n[0] && a[alooked] < now; alooked++) ;
                if (alooked == n[0])
                {
                    flag = false;
                    break;
                }
                now = a[alooked] + x[0];
                for (; blooked < n[1] && b[blooked] < now; blooked++) ;
                if (blooked == n[1])
                {
                    flag = false;
                    break;
                }
                now = b[blooked] + x[1];
                ret++;
            }
            Console.WriteLine(ret);
        }
    }
}