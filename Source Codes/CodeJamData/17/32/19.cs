using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public class Parent
    {
        public static void Solve()
        {
            using (var input = new StreamReader(@"..\..\input.txt"))
            using (var output = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    var line = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

                    var AC = line[0];
                    var AJ = line[1];

                    var C = new Frag[AC];
                    for (var i = 0; i < C.Length; i++)
                    {
                        line = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        C[i] = new Frag
                        {
                            Start = line[0],
                            End = line[1]
                        };
                    }

                    var J = new Frag[AJ];
                    for (var i = 0; i < J.Length; i++)
                    {
                        line = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        J[i] = new Frag
                        {
                            Start = line[0],
                            End = line[1]
                        };
                    }

                    var result = "2";
                    if (C.Length == 2)
                    {
                        result = Read(C);
                    }
                    else if (J.Length == 2)
                    {
                        result = Read(J);
                    }

                    output.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }

        private static string Read(Frag[] C)
        {
            string result;
            C = C.OrderBy(s => s.Start).ToArray();
            if (C[1].End - C[0].Start <= 720
                || (1440 - C[1].Start + C[0].End) <= 720)
            {
                result = "2";
            }
            else
            {
                result = "4";
            }

            return result;
        }
    }

    internal class Frag
    {
        public int Start;
        public int End;
    }
}
