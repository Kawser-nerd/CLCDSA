using System;
using System.Linq;

namespace arc036_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] sleep = new int[x[0]];
            for (int i = 0; i < x[0]; i++)
            {
                sleep[i] = int.Parse(Console.ReadLine());
            }
            int time = sleep[0] + sleep[1] + sleep[2];
            bool ng = false;
            for (int i = 3; i < x[0] && !ng; i++)
            {
                if (time < x[1])
                {
                    ng = true;
                    Console.WriteLine(i);
                }
                else
                {
                    time += sleep[i] - sleep[i - 3];
                }
            }
            if (!ng && time < x[1])
            {
                ng = true;
                Console.WriteLine(x[0]);
            }
            else if (!ng)
            {
                Console.WriteLine(-1);
            }
        }
    }
}