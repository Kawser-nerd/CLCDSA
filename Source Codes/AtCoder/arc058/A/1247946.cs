using System;
using System.Linq;

namespace arc058_aarc058_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            string[] d = Console.ReadLine().Split();
            bool find = false;
            while (!find)
            {
                find = true;
                for (int i = 0; i < x[1]; i++)
                {
                    if (x[0].ToString().Contains(d[i]))
                    {
                        find = false;
                    }
                }
                x[0]++;
            }
            Console.WriteLine(--x[0]);
        }
    }
}