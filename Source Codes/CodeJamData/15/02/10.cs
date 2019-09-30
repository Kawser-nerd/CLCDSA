using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../B-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                int D = int.Parse(inputs[x * 2 + 1]);
                int[] plates = inputs[x * 2 + 2].Split(' ').Select(int.Parse).ToArray();
                int height = plates.Max();
                int ans = height;
                for (int h = 1; h < height; h++)
                {
                    int move = NumberOfMoves(plates, h);
                    int time = move + h;
                    ans = Math.Min(ans, time);
                }
                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, ans));
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }

        static int NumberOfMoves(int[] plates, int target)
        {
            int move = 0;
            foreach (var p in plates)
            {
                int m = (int)Math.Ceiling((double)p / (double)target) - 1;
                move += m;
            }
            return move;
        }
    }
}
