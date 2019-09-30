using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS {
    class ManageYourEnergy {
        private const string ProblemLetter = "B";
        private readonly StreamReader _reader;
        private readonly StreamWriter _writer;

        public ManageYourEnergy(StreamReader reader, StreamWriter writer) {
            _reader = reader;
            _writer = writer;
        }
        static void Main(string[] args) {
            var difficulty = args[0];
            var inputFile = string.Format("{0}-{1}.in", ProblemLetter, difficulty);
            var outputFile = string.Format("{0}-{1}.out", ProblemLetter, difficulty);
            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
                new ManageYourEnergy(reader, writer).Run();
        }

        private void Run() {
            int testCount = int.Parse(_reader.ReadLine());
            for (int test = 1; test <= testCount; ++test) {
                var answer = SolveTest();
                _writer.WriteLine("Case #{0}: {1}", test, answer);
            }
        }

        private string SolveTest() {
            var line = _reader.ReadLine().Split(' ');
            int E = int.Parse(line[0]), R = int.Parse(line[1]), N = int.Parse(line[2]);
            var prio = _reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var dp = new int[N, E + 1];
            for (int e = 0; e <= E; ++e)
                dp[N - 1, e] = e * prio[N - 1];
            for (int i = N - 2; i >= 0; --i) {
                for (int e = 0; e <= E; ++e) {
                    dp[i, e] = Enumerable.Range(0, e + 1).Max(s => s * prio[i] + dp[i + 1, Math.Min(e - s + R, E)]);
                }
            }
            return dp[0, E].ToString();
        }
    }
}
