using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test.in", "C-small-attempt0.in", "C-large.in" }[2];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round0C(input, output);
            }
        }

        static void Round0C(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var items = fileInput.ReadLine().Split(' ').Select(i => int.Parse(i)).ToArray();
                var N = items[0];
                var J = items[1];
                {
                    var result = string.Format("Case #{0}:", t + 1);
                    Console.WriteLine(result);
                    fileOutput.WriteLine(result);
                }
                var list = new List<uint>();
                {
                    //var M = (uint)Math.Pow(10, N / 2.0);
                    var M = 10000u;
                    for (uint i = 2; i <= M; i++)
                    {
                        var b = false;
                        var m = (uint)Math.Sqrt(i);
                        foreach (var j in list)
                        {
                            if (j > m) break;
                            if (i % j == 0) { b = true; break; }
                        }
                        if (!b) list.Add(i);
                    }
                }

                var count = 0;
                var min = (uint)(1ul << (N - 1)) + 1;
                var max = (uint)(1ul << N) - 1;
                for (var jam = min; jam <= max; jam += 2)
                {
                    var divisors = new ulong[9];
                    BigInteger coin10 = 0ul;
                    var check = false;
                    for (var bs = 2u; bs <= 10u; bs++)
                    {
                        BigInteger coin = 0ul;
                        {
                            var j = jam;
                            BigInteger b = 1ul;
                            for (int i = 0; i < N; i++)
                            {
                                if ((j & 1) > 0) coin += b;
                                j >>= 1; b *= bs;
                            }
                        }
                        if (bs == 10) coin10 = coin;

                        {
                            var b = false;
                            //var m = (uint)Math.Sqrt(coin);
                            foreach (var j in list)
                            {
                                //if (j > m) break;
                                if (coin % j == 0) { b = true; divisors[bs - 2] = j; break; }
                            }
                            if (!b) { check = true; break; }
                        }
                        
                    }
                    if (check) continue;

                    var result = string.Format("{0} {1}", coin10, string.Join(" ", divisors));
                    Console.WriteLine(result);
                    fileOutput.WriteLine(result);
                    if (++count == J) break;
                }
            }
        }

    }
}
