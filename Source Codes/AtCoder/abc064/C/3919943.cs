using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C064
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] s1 = Console.ReadLine().Split(' ');

            int[] color = new int[8];
            int freeCount = 0;
            foreach (string s in s1)
            {
                int c = int.Parse(s) / 400;
                if (c >= 8) freeCount++;
                else color[c]++;
            }

            int min = color.Count(x => x > 0);
            if (min == 0)
            {
                min = 1; freeCount--;
            }

            int max = min + freeCount;
            Console.WriteLine(min.ToString() + " " + max.ToString());
        }

    }
}