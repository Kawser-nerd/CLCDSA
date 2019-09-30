using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace A
{
    [TestFixture]
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int D = Convert.ToInt32(tmp[0]);
            int N = Convert.ToInt32(tmp[1]);

            int[] K = new int[N];
            int[] S = new int[N];

            for (int i = 0; i < N; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                K[i] = Convert.ToInt32(tmp[0]);
                S[i] = Convert.ToInt32(tmp[1]);
            }

            double time = 0;

            for (int i = 0; i < N; i++)
            {
                time = Math.Max(time, 1.0 * (D - K[i]) / S[i]);
            }

            double res = 1.0 * D / time;

            outputStream.WriteLine("Case #{0}: {1:0.0000000}", testCase, res);
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\A-small.in", "..\\..\\Output\\A-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\A-large.in", "..\\..\\Output\\A-large.out");
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
