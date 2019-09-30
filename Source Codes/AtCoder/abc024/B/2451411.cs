using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int count = 0;
            int[] c =new int[a[0]];
            int d = 0;
            bool first = false;

            for(int i = 0; i < a[0]; i++)
            {
                int b = int.Parse(Console.ReadLine());
                c[i] = b;

                if (first)
                {
                    d = c[i] - c[i - 1];

                    if (d <= a[1])
                    {
                        count += d;
                    }
                    else
                    {
                        count += a[1];
                    }
                }
                else
                {
                    count += a[1];
                }

                first = true;
               
            }
            Console.WriteLine(count);
        }
    }
}