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

                    var data = new Cake[N];
                    for (var i = 0; i < data.Length; i++)
                    {
                        line = input.ReadLine().Split().Select(s => long.Parse(s)).ToArray();
                        data[i] = new Cake
                        {
                            R = line[0],
                            H = line[1]
                        };
                    }

                    data = data.OrderByDescending(s => s.R).ThenByDescending(s => s.H).ToArray();

                    var max = 0M;
                    for (var i = 0; i < data.Length; i++)
                    {
                        var test = data.Skip(i + 1).ToArray();
                        if (test.Length < K - 1)
                            break;

                        var sub = test.Select(s => 2M * (decimal)Math.PI * s.R * s.H).OrderByDescending(s => s).Take((int)K - 1).Sum();
                        var area = data[i].R * data[i].R * (decimal)Math.PI + sub + 2M * (decimal)Math.PI * data[i].R * data[i].H;
                        if (area > max)
                            max = area;
                    }

                    output.WriteLine("Case #{0}: {1:0.000000}", currentCase, max);
                }
            }
        }
    }

    public class Cake
    {
        public long R;
        public long H;
    }
}
