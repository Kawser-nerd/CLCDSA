using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS {
    class Bullseye {
        private const string ProblemLetter = "A";
        private readonly StreamReader _reader;
        private readonly StreamWriter _writer;

        public Bullseye(StreamReader reader, StreamWriter writer) {
            _reader = reader;
            _writer = writer;
        }
        static void Main(string[] args) {
            var difficulty = args[0];
            var inputFile = string.Format("{0}-{1}.in", ProblemLetter, difficulty);
            var outputFile = string.Format("{0}-{1}.out", ProblemLetter, difficulty);
            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
                new Bullseye(reader, writer).Run();
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
            var r = BigInteger.Parse(line[0]);
            var t = BigInteger.Parse(line[1]);
            BigInteger left = BigInteger.Zero, right = t;
            while (right > left + 1) {
                var mid = (left + right) / 2;
                if (func(r, mid) > t)
                    right = mid;
                else
                    left = mid;
            }
            if (func(r, left) > t) return (left - 1).ToString();
            if (func(r, right) > t) return left.ToString();
            return right.ToString();
        }

        private static BigInteger func(BigInteger r, BigInteger k) {
            return 2 * r * k + 2 * k * k - k;
        }
    }
}
