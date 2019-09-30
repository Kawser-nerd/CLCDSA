//#define SMALL
#define LARGE

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace CodeJam2012 {
    internal class SafetyInNumbers {
        private const string ProblemLetter = "A";
#if SMALL
        private const string ProblemType = "small";
#elif LARGE
        private const string ProblemType = "large";
#endif

        private static void Main(string[] args) {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (var reader = new StreamReader(string.Format("{0}-{1}.in", ProblemLetter, ProblemType)))
            using (var writer = new StreamWriter(string.Format("{0}-{1}.out", ProblemLetter, ProblemType)))
                new SafetyInNumbers { reader = reader, writer = writer }.Run();
        }

        private TextReader reader;
        private TextWriter writer;
        private int test;

        private void Run() {
            int testNumber = ReadInt();
            for (test = 1; test <= testNumber; test++) {
                var s = ReadInput();
                double[] y = s.Select((x, i) => GetMinValue(i, s)).ToArray();
                //Console.WriteLine("{0}: {1}", test, y.Sum());
                string answer = string.Join(" ", y.Select(x => string.Format("{0:N6}", x * 100)));
                WriteAnswer(answer);
            }
        }

        private double GetMinValue(int k, int[] all) {
            double l = 0, r = 1.0;
            int sum = all.Sum();
            for (int iter = 0; iter < 1000; ++iter) {
                double m = (l + r) / 2;
                double scoreMy = all[k] + m * sum;
                
                double rest = 1 - m;
                for (int i = 0; i < all.Length; ++i) {
                    if (i != k && scoreMy - all[i] > 1e-7) {
                        double y = (scoreMy - all[i]) / sum;
                        rest -= y;
                    }
                }                

                if (rest > 1e-7)
                    l = m;
                else
                    r = m;
            }
            return r;
        }

        private void WriteAnswer(string answer)
        {
            writer.WriteLine("Case #{0}: {1}", test, answer);
        }

        private int[] ReadInput() {
            return ReadInts().Skip(1).ToArray();
        }

        private int ReadInt() {
            return int.Parse(reader.ReadLine());
        }

        private int[] ReadInts() {
            return
                reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse).ToArray();
        }

        private string[] ReadStringsLine() {
            return reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
