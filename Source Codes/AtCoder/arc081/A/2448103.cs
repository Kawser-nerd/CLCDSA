using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC81_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Array.Sort(a);
            Array.Reverse(a);
            long b = 0;
            int bi = 0;
            long c = 0;
            for (int i = 0; i < n-1; i++)
            {
                if (a[i] == a[i+1])
                {
                    b = a[i];
                    bi = i + 2;
                    break;
                }
            }
            if (bi > n-2)
            {
                Console.WriteLine(0);
                return;
            }
            for (int i = bi; i < n - 1; i++)
            {
                if(a[i] == a[i+1])
                {
                    c = a[i];
                    break;
                }
            }
            if (c == 0)
            {
                Console.WriteLine(0);
                return;
            }

            Console.WriteLine(c * b);
        }
    }
}