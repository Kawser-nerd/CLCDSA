using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc_017_C
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = new int[n[1]+2];
            int max = 0;
            for (int i = 0; i < n[0]; i++)
            {
                int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[s[0]] += s[2];
                a[s[1] + 1] -= s[2];
                max += s[2];
            }
            for (int i = 1; i < a.Length; i++)
            {
                a[i] = a[i - 1] + a[i];
            }
            a[0] = int.MaxValue;
            a[a.Length - 1] = int.MaxValue;
            Console.WriteLine(max-a.Min());
            Console.ReadLine();

        }
    }
}