using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    // http://abc023.contest.atcoder.jp/tasks/abc023_b
    public class Abc023_b
    {
#if !Development
		public static void Main(string[] args)
		{
			Abc023_b.Solve(args);
		}
#endif

        public static void Solve(string[] args)
        {
            var N = ReadLineInt()[0];
            var S = ReadLineString()[0];
            var totalStep = 0;
            var str = "b";
            var result = step1(S, str, totalStep, N);

            Console.WriteLine(result);
        }

        private static int step1(string S, string str, int totalStep, int length)
        {
            if (S == str) return totalStep;
            else if (str.Length > length) return -1;

            totalStep++;

            str = "a" + str + "c";
            return step2(S, str, totalStep, length);
        }
        private static int step2(string S, string str, int totalStep, int length)
        {
            if (S == str) return totalStep;
            else if (str.Length > length) return -1;
            totalStep++;

            str = "c" + str + "a";
            return step3(S, str, totalStep, length);
        }
        private static int step3(string S, string str, int totalStep, int length)
        {
            if (S == str) return totalStep;
            else if (str.Length > length) return -1;
            totalStep++;

            str = "b" + str + "b";
            return step1(S, str, totalStep, length);
        }

        public static List<string> ReadLineString() { return Console.ReadLine().Split(' ').ToList(); }
        public static List<int> ReadLineInt() { return Console.ReadLine().Split(' ').Select(str => int.Parse(str)).ToList(); }
    }
}