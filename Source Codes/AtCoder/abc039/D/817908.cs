using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _039D
{
    class Program
    {
        static void Main(string[] args)
        {
            var buff = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var H = buff[0];
            var W = buff[1];
            var S = new string[H];
            for (int i = 0; i < H; i++)
            {
                S[i] = Console.ReadLine();
            }
            var canvas = new bool[H, W];    // t -> white
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (S[i][j] == '.')
                    {
                        var d = new int[] { -1, 0, 1 };
                        for (int k = 0; k < 3; k++)
                        {
                            for (int l = 0; l < 3; l++)
                            {
                                if (0 <= i + d[k] && i + d[k] < H && 0 <= j + d[l] && j + d[l] < W)
                                {
                                    canvas[i + d[k], j + d[l]] = true;
                                }
                            }
                        }
                    }
                }
            }
            var canvas2 = new bool[H, W];   // t -> black
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    var d = new int[] { -1, 0, 1 };
                    for (int k = 0; k < 3; k++)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            if (0 <= i + d[k] && i + d[k] < H && 0 <= j + d[l] && j + d[l] < W && !canvas[i + d[k], j + d[l]])
                            {
                                canvas2[i, j] = true;
                            }

                        }
                    }
                    if ((canvas2[i, j] && S[i][j] == '#') || (!canvas2[i, j] && S[i][j] == '.')) { }
                    else { Console.WriteLine("impossible"); return; }
                }
            }
            Console.WriteLine("possible");
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(canvas[i, j] ? "." : "#");
                }
                Console.WriteLine();
            }
        }
    }
}