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
            var inputs = File.ReadAllLines(@"../../A-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                var digits = inputs[x + 1].Split(' ').Select(int.Parse).ToArray();
                int R = digits[0];
                int C = digits[1];
                int W = digits[2];
                int quo = C / W;
                int rem = C % W;
                int partitions = rem == 0 ? quo : quo + 1;
                int lastRowFire = (partitions - 1) + W;
                int baseFire = quo * (R - 1);
                int ans = baseFire + lastRowFire;
                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, ans));
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }
    }
}
