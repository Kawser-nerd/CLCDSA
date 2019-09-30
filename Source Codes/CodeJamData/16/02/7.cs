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
            var filename = new[] { "test.in", "B-small-attempt0.in", "B-large.in" }[2];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round0B(input, output);
            }
        }

        static void Round0B(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var S = fileInput.ReadLine();

                var L = S.Length;
                S += '+';

                var count = 0;
                for (var i = 0; i < L; i++)
                {
                    if (S[i] != S[i + 1]) count++;
                }

                var result = string.Format("Case #{0}: {1}", t + 1, count);
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }
    }
}
