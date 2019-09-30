using System;
using System.Linq;

namespace arc017_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ren = 1;
            int ret = x[1] == 1 ? 1 : 0;
            int mae = int.Parse(Console.ReadLine());
            for (int i = 1; i < x[0]; i++)
            {
                int now = int.Parse(Console.ReadLine());
                if (mae < now) ren++;
                else ren = 1;
                if (ren >= x[1]) ret++;
                mae = now;
            }
            Console.WriteLine(ret);
        }
    }
}