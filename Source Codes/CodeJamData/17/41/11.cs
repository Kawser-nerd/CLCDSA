using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        private StreamReader inputStream = new StreamReader("in.txt");
        private StreamWriter outputStream = new StreamWriter("out.txt");

        static void Main(string[] args)
        {
            var program = new Program();
            program.RunAllTestCases();
            program.outputStream.Flush();
            program.outputStream.Close();
        }

        public void RunAllTestCases()
        {
            int testCasesCount = this.ReadInteger();
            foreach (var testCaseIndex in Enumerable.Range(1, testCasesCount))
            {
                string testCaseResult = this.RunTestCase();
                outputStream.WriteLine($"Case #{testCaseIndex}: {testCaseResult}");
            }
        }

        private string RunTestCase()
        {
            var components = this.ReadIntegers();
            var N = components[0];
            var P = components[1];
            var tmp1 = this.ReadIntegers().Select(n => n % P).ToArray();
            var tmp2 = tmp1.GroupBy(n => n).ToArray();
            var groups = tmp2.ToDictionary(g => g.Key, g => g.Count());
            var counts = new int[P];
            foreach (var g in groups) {
                counts[g.Key] = g.Value;
            }

            int freshGroups = counts[0];
            if (P == 2)
            {
                freshGroups += (counts[1] + 1) / 2;
            }
            else if (P == 3) {
                var min = Math.Min(counts[1], counts[2]);
                freshGroups += min;
                counts[1] -= min;
                counts[2] -= min;
                freshGroups += (counts[1] + 2) / 3;
                freshGroups += (counts[2] + 2) / 3;
            }

            string result = "" + freshGroups;
            return result;
        }

        private string ReadString()
        {
            return this.inputStream.ReadLine();
        }

        private string[] ReadStrings(string separator)
        {
            return this.inputStream.ReadLine().Split(new [] { separator }, StringSplitOptions.None);
        }

        private T[] ReadComponents<T>(string separator, Func<string, T> parseComponent)
        {
            return this.ReadStrings(separator).Select(element => parseComponent(element)).ToArray();
        }

        private int ReadInteger()
        {
            return int.Parse(this.ReadString());
        }

        private double ReadDouble()
        {
            return double.Parse(this.ReadString());
        }

        private int[] ReadIntegers()
        {
            return this.ReadComponents(" ", int.Parse);
        }

        private double[] ReadDoubles()
        {
            return this.ReadComponents(" ", double.Parse);
        }
    }
}
