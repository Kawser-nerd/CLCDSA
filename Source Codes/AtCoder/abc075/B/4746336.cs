using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            B();
        }

        static void B()
        {
            var HW = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var H = HW[0];
            var W = HW[1];

            var dx = new List<int> { 0, 1, 1, 1, 0, -1, -1, -1 };
            var dy = new List<int> { -1, -1, 0, 1, 1, 1, 0, -1 };
            var S = new List<List<string>>();
            for (var h = 0; h < H; h++)
            {
                S.Add(Console.ReadLine().Select(x => x.ToString()).ToList());
            }

            for (var h = 0; h < H; h++)
            {
                for (var w = 0; w < W; w++)
                {
                    if (S[h][w] == "#")
                        continue;

                    var bomCount = 0;
                    for (var i = 0; i < dx.Count; i++)
                    {
                        var y = dy[i] + h;
                        var x = dx[i] + w;

                        if (!(y >= 0 && y < H && x >= 0 && x < W))
                            continue;

                        if (S[y][x] == "#")
                            bomCount++;
                    }
                    S[h][w] = bomCount.ToString();
                }
            }

            foreach (var a in S)
            {
                foreach (var b in a)
                    Console.Write(b);
                Console.WriteLine("");
            }
        }
    }
}