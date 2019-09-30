using System;
using System.Linq;

namespace ARC068D
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split(' ').Select(aa => int.Parse(aa)).ToArray();

            bool[] ans = new bool[100000];
            int count = 0;
            foreach (int ai in a)
            {
                if (ans[ai])
                {
                    continue;
                }

                ans[ai] = true;
                count++;
            }

            Console.WriteLine(count - (count + 1 ) % 2 );
        }
    }
}