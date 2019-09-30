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
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int A = Convert.ToInt32(tmp[0]);
            int B = Convert.ToInt32(tmp[1]);
            int K = Convert.ToInt32(tmp[2]);

            int res = 0;

            for (int i = 0; i < A; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    if ((i & j) < K)
                        res++;
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
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
