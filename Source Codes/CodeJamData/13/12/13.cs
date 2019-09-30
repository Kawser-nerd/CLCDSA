using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ1B
{
    class Program
    {
        static long E;
        static long R;
        static long[] values;

        static long best(long e, int step)
        {
            if (step >= values.Length)
                return 0;
            var max = 0L;
            for (int i = 0; i <= e; i++)
                max = Math.Max(max, best(Math.Min(E, e - i + R), step + 1) + i * values[step]);
            return max;
        }

        struct FunctionPoint
        {
            public FunctionPoint(long e, long o, long r)
            {
                Energy = e;
                Output = o;
                Rate = r;
            }

            public long Energy;
            public long Output;
            public long Rate;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split();
                E = long.Parse(parts[0]);
                R = Math.Min(E, long.Parse(parts[1]));

                values = Console.ReadLine().Split().Select(long.Parse).ToArray();

                var d = new List<FunctionPoint> { new FunctionPoint(0, 0, 0), new FunctionPoint(E, 0, 0) };
                for (int i = values.Length - 1; i >= 0; i--)
                {
                    var e = 0L;
                    var te = R;
                    var ti = 0;
                    while (d[ti].Energy < te)
                        ti++;
                    var newO = d[ti].Output - d[ti].Rate * (d[ti].Energy - te);
                    var newD = new List<FunctionPoint> { new FunctionPoint(e, newO, 0) };
                    if (d[ti].Energy == te)
                        ti++;
                    while (te < E)
                    {
                        var energyStep = Math.Min(E - te, d[ti].Energy - te);
                        var newRate = Math.Max(values[i], d[ti].Rate);
                        newD.Add(new FunctionPoint(e + energyStep, newD.Last().Output + newRate * energyStep, newRate));
                        e += energyStep;
                        te += energyStep;
                        ti++;
                    }
                    newD.Add(new FunctionPoint(E, newD.Last().Output + values[i] * R, values[i]));
                    d = newD;
                }

                Console.WriteLine("Case #{0}: {1}", testNumber, d.Last().Output);
            }
        }
    }
}
