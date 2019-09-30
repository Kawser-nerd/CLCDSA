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
            int N = Convert.ToInt32(inputStream.ReadLine());
            string[] S = new string[N];
            int[] indx = new int[N];

            for (int i = 0; i < N; i++)
            {
                S[i] = inputStream.ReadLine();
            }

            int res = 0;

            while (true)
            {
                char c = S[0][indx[0]];

                for (int i = 1; i < N; i++)
                {
                    if (S[i][indx[i]] != c)
                    {
                        outputStream.WriteLine("Case #{0}: Fegla Won", testCase);
                        return;
                    }
                }

                bool finish = true;
                bool repeated = false;
                int add = 0;
                int remove = 0;

                for (int i = 0; i < N; i++)
                {
                    if (indx[i] + 1 < S[i].Length)
                    {
                        finish = false;

                        if (S[i][indx[i] + 1] == c)
                        {
                            repeated = true;
                            remove++;
                        }
                    }

                    add = N - remove;
                }

                if (finish)
                    break;

                if (repeated)
                {
                    res += Math.Min(add, remove);

                    for (int i = 0; i < N; i++)
                    {
                        if (indx[i] + 1 < S[i].Length && S[i][indx[i] + 1] == c)
                            indx[i]++;
                    }
                }
                else
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (indx[i] + 1 == S[i].Length)
                        {
                            outputStream.WriteLine("Case #{0}: Fegla Won", testCase);
                            return;
                        }

                        indx[i]++;
                    }
                }
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
