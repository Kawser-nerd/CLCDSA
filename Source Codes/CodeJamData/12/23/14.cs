#define SMALL
//#define LARGE

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
    internal class Template {
        private const string ProblemLetter = "C";
#if SMALL
        private const string ProblemType = "small";
#elif LARGE
        private const string ProblemType = "large";
#endif

        private static void Main(string[] args) {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (var reader = new StreamReader(string.Format("{0}-{1}.in", ProblemLetter, ProblemType)))
            using (var writer = new StreamWriter(string.Format("{0}-{1}.out", ProblemLetter, ProblemType)))
                new Template { reader = reader, writer = writer }.Run();
        }

        private TextReader reader;
        private TextWriter writer;
        private int test;

        private Dictionary<int, int> maskOf = new Dictionary<int, int>();

        private void Run() {
            int testNumber = ReadInt();
            for (test = 1; test <= testNumber; test++) {
                maskOf.Clear();
                var a = ReadInput();
                int mask1 = -1, mask2 = -1;
                for (int mask = 0; mask < (1 << 20); ++mask) {
                    var nums = GetNumsByMask(a, mask);
                    int sum = nums.Sum();
                    if (maskOf.ContainsKey(sum)) {
                        mask1 = mask;
                        mask2 = maskOf[sum];
                        break;
                    }
                    else {
                        maskOf[sum] = mask;
                    }
                }

                string answer = "Impossible";
                if (mask1 > 0) {
                    var nums1 = GetNumsByMask(a, mask1);
                    string s1 = string.Join(" ", nums1);
                    var nums2 = GetNumsByMask(a, mask2);
                    string s2 = string.Join(" ", nums2);
                    answer = s1 + "\n" + s2;
                }
                WriteAnswer(answer);
            }
        }

        private List<int> GetNumsByMask(int[] a, int mask) {
            List<int> ans = new List<int>();
            for (int i = 0; i < 20; ++i)
                if ((mask & (1 << i)) > 0)
                    ans.Add(a[i]);
            return ans;
        }

        private void WriteAnswer(string answer) {
            writer.WriteLine("Case #{0}:\n{1}", test, answer);
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
