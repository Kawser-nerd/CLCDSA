using System;
using System.Linq;

namespace arc089_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] now = new int[] { 0,0 }; int time = 0;
            bool ret = true;
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int move = Math.Abs(now[0] - x[1]) + Math.Abs(now[1] - x[2]);
                if (move <= x[0] - time && (move - (x[0] - time)) % 2 == 0)
                {
                    now[0] = x[1]; now[1] = x[2];
                    time = x[0];
                }
                else
                {
                    ret = false;
                }
            }
            Console.WriteLine(ret ? "Yes" : "No");
        }
    }
}