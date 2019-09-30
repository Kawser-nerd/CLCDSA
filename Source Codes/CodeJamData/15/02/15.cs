using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

// Julgodis 2015
namespace Q2015_B
{
    class Guest {
        public int Pancakes;
        public Guest(int P)
        {
            Pancakes = P;
        }

        public override string ToString()
        {
            return "" + Pancakes;
        }
    }

    class TestCase
    {
        public Guest[] Guests;
    }

    class Program
    {
        static int IntDiv(int a, int b) { 
            return (int)Math.Floor((float)(a - 1) / (float)b);
        }

        static int Solve(TestCase testCase)
        {
            int minutes = 0;

            minutes = testCase.Guests.Max(x => x.Pancakes);
            int threshold = 2;
            while (threshold < minutes) {
                var sum = testCase.Guests.Sum(x => IntDiv(x.Pancakes, threshold));
                minutes = Math.Min(minutes, sum + threshold);
                threshold++;
            }

            return minutes;
        }

        static void Main(string[] args)
        {
            var input = args[0];
            var output = args[1];

            var fileData = File.ReadAllLines(input);
            var cases = ParseInput(fileData);

            int i = 0;
            var data = "";
            foreach (var testCase in cases)
            {
                var result = Solve(testCase);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                data += "Case #" + (i + 1) + ": " + result + "\n";
                i++;
            }

            File.WriteAllText(output, data);
            return;
        }

        static TestCase[] ParseInput(String[] lines)
        {
            var cases = new List<TestCase>();

            int T = Int32.Parse(lines[0]);
            int C = 1;
            for (int i = 0; i < T; i++)
            {
                var testCase = new TestCase();
                var eaters = new List<Guest>();
                var nonEmpty = Int32.Parse(lines[C++]);
                var data = lines[C++].Split(' ');

                for (int j = 0; j < nonEmpty; j++)
                {
                    eaters.Add(new Guest(Int32.Parse(data[j])));
                }

                testCase.Guests = eaters.ToArray();
                cases.Add(testCase);
            }

            return cases.ToArray();
        }
    }
}
