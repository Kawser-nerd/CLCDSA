using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC80_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(long.Parse).ToArray();

            int co = 0;
            int c4 = 0;

            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 1) co++;
                if (a[i] % 4 == 0) c4++;

            }
            if (c4 >= co || (co + c4 == n && co - c4 == 1))
            {

                Console.WriteLine("Yes");
            }
            else
            {

                Console.WriteLine("No");
            }
        }
    }
}