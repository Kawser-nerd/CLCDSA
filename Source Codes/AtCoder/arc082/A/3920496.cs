using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C072
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] s = Console.ReadLine().Split(' ');
            int amax = s.Select(x => int.Parse(x)).Max();
            int[] a = new int[amax + 1];

            foreach (string c in s)
            {
                int i = int.Parse(c);
                a[i]++;
            }

            int max = 0;
            for (int i = 0; i <= amax; i++)
            {
                int sum = a[i];
                if (i > 0) sum += a[i - 1];
                if (i < amax) sum += a[i + 1];
                if (sum > max) max = sum;
            }
            Console.WriteLine(max);
        }
    }
}