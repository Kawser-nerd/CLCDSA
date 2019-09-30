using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class AtCodeeeeeeeeeeeeeeeeeeeer
    {
        static void Main(string[] args)
        {
            int[] HW = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int H = HW[0];
            int W = HW[1];

            for (int i = 0; i < H+2; i++)
            {
                if (i == 0 || i == H+1)
                {
                    for (int j = 0; j < W+2; j++)
                    {
                        Console.Write("#");
                    }
                    Console.Write("\r\n");
                }
                else
                {
                    Console.WriteLine("#" + Console.ReadLine() + "#");
                }
            }
        }
    }
}