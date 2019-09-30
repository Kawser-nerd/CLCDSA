using System;
using System.Linq;

namespace abc035_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] koma = new int[x[0]];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                koma[a[0]]++; if (a[1] + 1 < x[0]) koma[a[1] + 1]--;
            }
            long sum = 0;
            for (int i = 0; i < x[0]; i++)
            {
                sum += koma[i];
                Console.Write(sum % 2);
            }
            Console.WriteLine();
        }
    }
}