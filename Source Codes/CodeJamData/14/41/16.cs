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

            int N = Convert.ToInt32(tmp[0]);
            int X = Convert.ToInt32(tmp[1]);

            int[] S = new int[N];

            tmp = inputStream.ReadLine().Split(' ');

            for (int i = 0; i < N; i++)
            {
                S[i] = Convert.ToInt32(tmp[i]);
            }

            Array.Sort<int>(S);

            int res = 0;

            for (int i = 0, j = N - 1; i <= j; j--)
            {
                if (i != j && S[i] + S[j] <= X)
                    i++;

                res++;
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
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
