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
            var inputs = File.ReadAllLines(@"../../D-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                int[] numbers = inputs[x + 1].Split(' ').Select(int.Parse).ToArray();
                int X = numbers[0];
                int R = numbers[1];
                int C = numbers[2];
                int L = Math.Max(R, C);
                int S = Math.Min(R, C);
                bool creatorWin = false;

                if ((R * C) % X != 0)
                {
                    creatorWin = true;
                }
                else if (X >= 7)
                {
                    creatorWin = true;
                }
                else if (X <= 2)
                {
                    creatorWin = false;
                }
                else if (X == 3)
                {
                    creatorWin = (L < 3) || (S < 2);
                }
                else if (X == 4)
                {
                    creatorWin = (L < 4) || (S < 2) || (S == 2);
                }
                else if (X == 5)
                {
                    creatorWin = (L < 5) || (S < 3) || ((S == 3) && (L < 10));
                }
                else // (X == 6)
                {
                    creatorWin = (L < 6) || (S < 3) || (S == 3);
                }

                outputs.AppendLine(string.Format("Case #{0}: ", x + 1) + (creatorWin ? "RICHARD" : "GABRIEL"));
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }
    }
}
