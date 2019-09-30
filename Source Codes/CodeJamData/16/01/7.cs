using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test0.in", "A-small-attempt0.in", "A-large.in" }[2];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round0(input, output);
            }
        }

        static void Round0(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var N = int.Parse(fileInput.ReadLine());

                var Last = 0;
                if (N != 0)
                {
                    var B = new bool[10];
                    var count = 0;
                    for (int i = 1; ; i++)
                    {
                        Last = i * N;
                        for (var M = Last; M > 0; M /= 10)
                        {
                            var D = M % 10;
                            if (!B[D]) { B[D] = true; count++; }
                        }
                        if (count == 10) break;
                    }
                }

                var result = string.Format("Case #{0}: {1}", t + 1, Last == 0 ? "INSOMNIA" : Last.ToString());
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
