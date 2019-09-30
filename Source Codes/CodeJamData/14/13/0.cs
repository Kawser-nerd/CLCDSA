using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
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


        static Random rand = new Random();

        static int[] GenerateBad(int n)
        {
            var res = new int[n];
            for (int i = 0; i < n; ++i)
                res[i] = i;
            for (int i = 0; i < n; ++i)
            {
                var p = rand.Next(0, n);
                var tmp = res[i];
                res[i] = res[p];
                res[p] = tmp;
            }
            return res;
        }

        static int[] GenerateGood(int n)
        {
            var res = new int[n];
            for (int i = 0; i < n; ++i)
                res[i] = i;
            for (int i = 0; i < n; ++i)
            {
                var p = rand.Next(i, n);
                var tmp = res[i];
                res[i] = res[p];
                res[p] = tmp;
            }
            return res;
        }


        static int Judge(int[] perm)
        {
            int a = 0;
            for (int i = 0; i < perm.Length; ++i)
                if (perm[i] >= i)
                    ++a;
            return a;
        }

        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();
            
            for (var test = 1; test <= testCases; ++test)
            {
                var n = InputParser.ReadLineInt();
               // if (n!=1000)
                 //   throw new Exception("aaaa");
                var input = InputParser.ReadLineInts().ToArray();

                bool good = Judge(input) <= (500.45 + 528.9)/2.0;
                Console.WriteLine("Case #{0}: {1}", test, good ? "GOOD" : "BAD");
            }

            /*
            const int N = 1000;

            var totalBad = 0.0;
            var totalGood = 0.0;

            var T = 100000;
            for (int exp = 0; exp < T; ++exp)
            {
                var bad = GenerateBad(N);
                var badScore = Judge(bad);
                totalBad += badScore;
                var good = GenerateGood(N);
                var goodScore = Judge(good);
                totalGood += goodScore;
            }
            Console.WriteLine((totalBad/T) + " " + (totalGood/T));
            Console.ReadLine();*/
        }
    }
}
