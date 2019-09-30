using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    public class Program
    {
        int N, L;
        string[] flows;
        string[] devices;

        public void ReadData()
        {
            var ar = ReadArray<int>();
            N = ar[0];
            L = ar[1];
            flows = ReadArray<string>();
            devices = ReadArray<string>();
        }

        public string Solve()
        {
            var devicesSet = new HashSet<string>(devices);

            int minFlips = int.MaxValue;
            for (long i = 0; i < 1 << L; i++)
            {
                int flips = CountBits(i);
                if (flips < minFlips)
                {
                    var flowSet = new HashSet<string>();
                    foreach (string flow in flows)
                    {
                        flowSet.Add(Flip(flow, i));
                    }
                    if (flowSet.SetEquals(devicesSet))
                    {
                        minFlips = flips;
                    }
                }
            }
            return minFlips < int.MaxValue ? minFlips.ToString() : "NOT POSSIBLE";
        }

        private string Flip(string flow, long i)
        {
            char[] flipped = flow.ToCharArray();
            int j = 0;
            while (i != 0)
            {
                if ((i & 0x1L) == 0x1L)
                {
                    flipped[j] = flipped[j] == '0' ? '1' : '0';
                }
                i >>= 1;
                j++;
            }
            return new string(flipped);
        }

        private int CountBits(long i)
        {
            int bits = 0;
            while (i != 0)
            {
                if ((i & 0x1L) == 0x1L) bits++;
                i >>= 1;
            }
            return bits;
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");
            string expectedFileName = filename.Replace(".in", ".expected");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Program();
                    problem.ReadData();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }

            if (File.Exists(expectedFileName))
            {
                CompareOutputToExpected(outFileName, expectedFileName);
            }
        }

        private static void CompareOutputToExpected(string outFileName, string expectedFileName)
        {
            string[] expected = File.ReadAllLines(expectedFileName);
            string[] actual = File.ReadAllLines(outFileName);
            for (int i = 0; i < Math.Max(expected.Length, actual.Length); i++)
            {
                string lineActual = i < actual.Length ? actual[i].Trim() : "** missing **";
                string lineExpected = i < expected.Length ? expected[i].Trim() : "** missing **";
                if (lineActual != lineExpected)
                {
                    Console.WriteLine("{0}: Expected: {1} Actual: {2}", (i + 1), lineExpected, lineActual);
                }
            }
        }

        #region Readers

        private static string ReadWord()
        {
            StringBuilder word = new StringBuilder();
            while (reader.Peek() >= 0)
            {
                char c = (char)reader.Read();
                if (Char.IsControl(c) || Char.IsWhiteSpace(c))
                    break;
                word.Append(c);
            }
            return word.ToString();
        }

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
