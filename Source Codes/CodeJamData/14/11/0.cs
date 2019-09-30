using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static int ParseIntFromStr(string str)
            {
                int result;
                if (!int.TryParse(str, out result))
                    throw new Exception(string.Format("Invalid str: {0}", str));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromStr(lineStr);
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            public static IEnumerable<int> ReadLineInts()
            {
                return ReadLineFragments().Select(ParseIntFromStr);
            }
        }


        private static Int64 Encode(string s)
        {
            Int64 res = 0, pow2 = 1;
            for (int i = 0; i < s.Length; ++i)
            {
                res += pow2*(s[i] == '1' ? 1 : 0);
                pow2 <<= 1;
            }
            return res;
        }

        static int Bits(Int64 a)
        {
            if (a == 0) return 0;
            return (int)(a & 1) + Bits(a >> 1);
        }

        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();

            for (var test = 1; test <= testCases; ++test)
            {
                var input = InputParser.ReadLineInts().ToArray();
                var n = input[0];
                var L = input[1];
                var line = Console.ReadLine();
                var mamy = line.Split(' ').Select(Encode).ToArray();
                line = Console.ReadLine();
                var chcemy = new HashSet<Int64>(line.Split(' ').Select(Encode));

                var best = 100;
                foreach (var x in chcemy)
                {
                    var zmiana = mamy[0] ^ x;
                    if (mamy.Select(y => y ^ zmiana).All(chcemy.Contains))
                        best = Math.Min(best, Bits(zmiana));
                }

                Console.WriteLine("Case #{0}: {1}", test, best == 100 ? "NOT POSSIBLE" : best.ToString());
            }
        }
    }
}
