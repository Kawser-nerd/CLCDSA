using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B.Palace
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var TA = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var Hn = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var min = double.MaxValue;
            int min_index = int.MaxValue;


            for (int i = 0; i < N; i++)
            {
                var diff = Math.Abs(TA[1] - (TA[0] - Hn[i] * 0.006));

                if (diff < min)
                {
                    min = diff;
                    min_index = i + 1;
                }
            }

            Console.WriteLine(min_index);

        }
    }
}