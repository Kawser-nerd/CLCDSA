using System;
using System.Linq;

namespace arc010_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool end = false;
            int i;
            for (i = 0; i < x[1] && !end; i++)
            {
                if (x[0] <= x[2])
                {
                    x[0] += x[3];
                }
                x[0] -= int.Parse(Console.ReadLine());
                if (x[0] < 0)
                {
                    end = true;
                }
            }
            Console.WriteLine(end ? i.ToString() : "complete");
        }
    }
}