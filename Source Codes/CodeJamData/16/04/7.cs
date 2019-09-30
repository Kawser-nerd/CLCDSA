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
            var filename = new[] { "test.in", "D-small-attempt0.in", "D-large.in" }[2];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round0D(input, output);
            }
        }

        static void Round0D(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var items = fileInput.ReadLine().Split(' ').Select(i => int.Parse(i)).ToArray();
                var K = items[0];
                var C = items[1];
                var S = items[2];

                var list = new List<long>();
                if (K <= C * S)
                {
                    for (int i = 0; i < K; i += C)
                    {
                        var student = 0L;
                        for (int j = 0; j < C; j++)
                        {
                            student *= K;
                            student += (i + j) % K;
                        }
                        list.Add(student + 1);
                    }
                }
                var result = string.Format("Case #{0}: {1}", t + 1, list.Count == 0 ? "IMPOSSIBLE" : string.Join(" ", list));
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
