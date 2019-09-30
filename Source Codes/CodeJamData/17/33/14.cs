using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public static class Syrup
    {
        public static void Solve()
        {
            using (var input = new StreamReader(@"..\..\input.txt"))
            using (var output = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    var line = input.ReadLine().Split().Select(s => long.Parse(s)).ToArray();
                    var N = line[0];
                    var K = line[1];

                    var U = decimal.Parse(input.ReadLine());
                    var P = input.ReadLine().Split().Select(s => decimal.Parse(s)).ToArray();


                    P = P.OrderBy(s => s).Concat(new[] { 1.0M }).ToArray();
                    var consec = 1;
                    for (var i = 0; i < P.Length - 1; i++)
                    {
                        if (U <= 0M)
                            break;
                        var next = P[i + 1];
                        var diff = P[i + 1] - P[i];
                        if (diff * consec > U)
                        {
                            for (var m = 0; m <= i; m++)
                                P[m] += (U / consec);
                            U = 0M;
                        }
                        else
                        {
                            for (var m = 0; m <= i; m++)
                                P[m] = P[i + 1];

                            U -= (diff * consec);
                            consec++;
                        }
                    }

                    var result = 1M;
                    for (var i = 0; i < P.Length; i++)
                    {
                        result = result * P[i];
                    }

                    output.WriteLine("Case #{0}: {1:0.000000}", currentCase, result);
                }
            }
        }
    }

    public class Activity
    {
        public long C;
        public long D;
    }
}
