using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

// Julgodis 2015
namespace Q2015_D
{
    class TestCase
    {
        public int X, R, C;
    }

    class Program
    {
        static bool Solve(TestCase testCase)
        {
            var N = testCase.X;
            var W = testCase.C;
            var H = testCase.R;
            var M = Math.Min(W, H);
            var K = Math.Max(W, H);

            // Condition

            /*
             * ###
             * # #
             * ###
             */
            if (N >= 7)
                return true;

            if ((W * H) % N != 0) 
                return true;

            if (N > W && N > H)
                return true;

            if (Math.Floor((float)(N + 1) / 2.0f) > M)
                return true;

            if (N == 1 || N == 2 || N == 3) 
                return false;

            if (N == 4)
                return (M <= 2);

            if (N == 5)
                return (M == 3 && K == 5);

            if (N == 6)
                return M <= 3;

            return false;
        }

        static void Main(string[] args)
        {
            var input = args[0];
            var output = args[1];

            var fileData = File.ReadAllLines(input);
            var cases = ParseInput(fileData);

            long i = 0;
            var data = "";
            foreach (var testCase in cases)
            {
                var result = Solve(testCase);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                data += "Case #" + (i + 1) + ": " + (result ? "RICHARD" : "GABRIEL") + "\n";
                i++;
            }

            File.WriteAllText(output, data);
            return;
        }

        static TestCase[] ParseInput(String[] lines)
        {
            var cases = new List<TestCase>();

            long T = Int64.Parse(lines[0]);
            long C = 1;
            for (long i = 0; i < T; i++)
            {
                var testCase = new TestCase();
                var data = lines[C++].Split(' ');
                testCase.X = Int32.Parse(data[0]);
                testCase.R = Int32.Parse(data[1]);
                testCase.C = Int32.Parse(data[2]);

                cases.Add(testCase);
            }

            return cases.ToArray();
        }
    }
}
