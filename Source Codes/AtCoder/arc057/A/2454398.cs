using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC57_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            long a = long.Parse(s[0]);
            long k = long.Parse(s[1]);
            int n = int.MaxValue;
            long p = a;
            long q = 0;
            if (k == 0)
            {

                Console.WriteLine(2e12 - a);
                return;
            }
            for (int i = 0; i < n; i++)
            {
                
                if (p + q >= 2e12)
                {
                    Console.WriteLine(i);
                    return;
                }
                p *= 1 + k;
                q += (long)Math.Pow(1 + k, i);
            }
        }
    }
}