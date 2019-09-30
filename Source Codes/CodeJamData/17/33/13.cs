using System;
using System.Linq;
using GoogleCodeJam.Utilities;

namespace GoogleCodeJam2017.Round1C
{
    public class C
    {
        public static void Main(string[] args)
        {
            var numberOfCases = IO.ReadInt();
            for (var i = 0; i < numberOfCases; i++)
            {
                var result = Calculate();
                IO.WriteDouble(i + 1, result);
            }
        }

        public static double Calculate()
        {
            var input = IO.ReadIntArray();
            var n = input[0];
            var k = input[1];
            var u = IO.Read(decimal.Parse);
            var p = IO.ReadArray(decimal.Parse).OrderBy(x => x).ToArray();

            if (p.Length == 1)
            {
                return (double)Math.Min(1, p[0] + u);
            }

            for (var i = 1; i < p.Length; i++)
            {
                if (p[i] > p[0])
                {
                    var diff = p[i] - p[0];
                    var required = diff * i;
                    var toAssign = Math.Min(u, required);
                    var toAssignPerUnit = toAssign / i;
                    for (var j = 0; j < i; j++)
                    {
                        p[j] += toAssignPerUnit;
                    }
                    u -= toAssign;
                }
            }

            var remainder = u / p.Length;

            var prob = p.Aggregate(1m, (current, t) => current * (t + remainder));

            return (double)(prob < 0 ? 0 : prob > 1 ? 1 : prob);
        }
    }
}