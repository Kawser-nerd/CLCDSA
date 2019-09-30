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
            int[] c =new int[a[0]];
            c[0] = int.Parse(Console.ReadLine());
            int d = 0;
            int count = a[1];

            for (int i = 1; i < a[0]; i++)
            {
                c[i] = int.Parse(Console.ReadLine());
                d = c[i] - c[i - 1];
                d = Math.Min(a[1], c[i] - c[i - 1]);
                count += d;
            }
            Console.WriteLine(count);
        }
    }
}