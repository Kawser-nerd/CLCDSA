using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC029D
{
    class Program
    {

        static void Main()
        {
            int H, W, N;
            {
                var HWN = Console.ReadLine().Split().Select(int.Parse).ToArray();
                H = HWN[0];
                W = HWN[1];
                N = HWN[2];
            }

            int[] minY = new int[H + 2];
            {
                for (int i = 0; i < H + 2; i++) minY[i] = W + 1;
                for (int i = 0; i < N; i++)
                {
                    int[] XY = Console.ReadLine().Split().Select(int.Parse).ToArray();
                    minY[XY[0]] = Math.Min(minY[XY[0]], XY[1]);
                }
            }

            int count = 1;
            int width = 1;
            for (int i = 2; i < H + 1; i++)
            {
                if (minY[i] <= width) break;
                else if (minY[i] == width +1)
                {
                    count++;
                }
                else if (minY[i] > width +1)
                {
                    width++;
                    count++;
                }
            }

            Console.WriteLine(count);
            Console.ReadKey();
        }
    }
}