using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

// Julgodis 2015
namespace Q2015_A
{
    class Audience {
        public int Shyness;
        public bool Standing = false;

        public Audience(int S) {
            Shyness = S;
        }
    }

    class TestCase {
        public int MaxShyness;
        public Audience[] Audience;
    }

    class Program
    {
        static int Solve(TestCase testCase) 
        {
            int standing = 0;
            int friends = 0;

            while (true) {
                var change = false;
                var notStanding = testCase.Audience.Where(x => !x.Standing);
                if(notStanding.Count() == 0)
                    break;

                foreach (var guy in notStanding) {
                    if (standing >= guy.Shyness) {
                        standing++;
                        guy.Standing = true;
                        change = true;
                    }
                }

                if (!change) {
                    friends++;
                    standing++;
                }
            }

            return friends;
        }

        static void Main(string[] args)
        {
            var input = args[0];
            var output = args[1];

            var fileData = File.ReadAllLines(input);
            var cases = ParseInput(fileData);

            int i = 0;
            var data = "";
            foreach (var testCase in cases) {
                var result = Solve(testCase);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                data += "Case #" + (i + 1) + ": " + result + "\n";
                i++;
            }

            File.WriteAllText(output, data);
            return;
        }

        static TestCase[] ParseInput(String[] lines) {
            var cases = new List<TestCase>();

            int T = Int32.Parse(lines[0]);
            for (int i = 1; i < T + 1; i++) {
                var data = lines[i].Split(' ');

                var SMax = Int32.Parse(data[0]);
                var testCase = new TestCase();
                testCase.MaxShyness = SMax;

                var aduience = new List<Audience>();

                for (int j = 0; j < testCase.MaxShyness + 1; j++) {
                    var C = Int32.Parse(""+data[1][j]);

                    for (int k = 0; k < C; k++ )
                        aduience.Add(new Audience(j));
                }

                testCase.Audience = aduience.ToArray();
                cases.Add(testCase);
            }

            return cases.ToArray();
        }
    }
}
