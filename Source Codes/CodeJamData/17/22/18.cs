using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace B
{
    [TestFixture]
    public class Program
    {
        private static char[] map = new char[] { 'R', 'O', 'Y', 'G', 'B', 'V' };

        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int N = Convert.ToInt32(tmp[0]);
            int[] colors = new int[6];

            for (int i = 1; i < 7; i++)
            {
                colors[i - 1] = Convert.ToInt32(tmp[i]);
            }

            int[] res = new int[N];
            int prev = -1;
            int best = -1;

            for (int i = 0; i < N; i++)
            {
                res[i] = -1;
            }

            for (int j = 0; j < 6; j++)
            {
                if (colors[j] > 0 && (best == -1 || colors[j] > colors[best]))
                    best = j;
            }

            for (int i = 0; i < N && colors[best] > 0; i += 2)
            {
                colors[best]--;
                res[i] = best;
            }

            for (int i = 0; i < N; i++)
            {
                if (res[i] != -1)
                {
                    prev = res[i];
                    continue;
                }

                best = -1;

                for (int j = 0; j < 6; j++)
                {
                    if (j != prev && colors[j] > 0 && (best == -1 || colors[j] > colors[best]))
                        best = j;
                }                

                if (best == -1)
                {
                    outputStream.WriteLine("Case #{0}: IMPOSSIBLE", testCase);
                    return;
                }

                prev = best;
                colors[best]--;
                res[i] = best;
            }

            if (res[0] == res[N - 1])
            {
                outputStream.WriteLine("Case #{0}: IMPOSSIBLE", testCase);
                return;
            }

            string result = "";

            for (int i = 0; i < N; i++)
            {
                result += map[res[i]];
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, result);
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\B-small.in", "..\\..\\Output\\B-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\B-large.in", "..\\..\\Output\\B-large.out");
        }

        private void TestInput(string inputFile, string outputFile)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(inputFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(outputFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        #endregion
    }
}
