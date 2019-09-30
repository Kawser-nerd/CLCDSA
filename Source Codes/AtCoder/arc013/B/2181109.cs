using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC013B
{
    class Program
    {
        static void Main(string[] args)
        {
            var C = int.Parse(Console.ReadLine());

            int[] l1 = new int[C];
            int[] l2 = new int[C];
            int[] l3 = new int[C];

            for(int i = 0; i < C; i++)
            {
                var line = Console.ReadLine().Split().Select(int.Parse).ToArray().OrderByDescending(X => X).ToArray();
                l1[i] = line[0];
                l2[i] = line[1];
                l3[i] = line[2];
            }

            Console.WriteLine(l1.Max() * l2.Max() * l3.Max());
            Console.ReadKey();
        }
    }
}