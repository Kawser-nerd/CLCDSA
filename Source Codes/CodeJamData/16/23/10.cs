using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace C
{
    [TestFixture]
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            int N = Convert.ToInt32(inputStream.ReadLine());
            string[] F = new string[N];
            string[] S = new string[N];

            for (int i = 0; i < N; i++)
            {
                string[] tmp = inputStream.ReadLine().Split(' ');

                F[i] = tmp[0];
                S[i] = tmp[1];
            }

            int res = 0;

            for (int i = 0; i < (1 << N); i++)
            {
                HashSet<string> first = new HashSet<string>();
                HashSet<string> second = new HashSet<string>();

                for (int j = 0; j < N; j++)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        first.Add(F[j]);
                        second.Add(S[j]);
                    }
                }

                bool ok = true;
                int cnt = 0;

                for (int j = 0; j < N; j++)
                {
                    if ((i & (1 << j)) == 0)
                    {
                        if (!first.Contains(F[j]) || !second.Contains(S[j]))
                        {
                            ok = false;
                            break;
                        }

                        cnt++;
                    }
                }

                if (ok)
                    res = Math.Max(res, cnt);
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\C-small.in", "..\\..\\Output\\C-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\C-large.in", "..\\..\\Output\\C-large.out");
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
