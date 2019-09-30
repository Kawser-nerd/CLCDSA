using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace A
{
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            string L = tmp[0];
            int N = L.Length;
            int n = Convert.ToInt32(tmp[1]);

            long[] res = new long[N + 1];

            int cnt = 0;

            for (int i = 0; i < N; i++)
            {
                if (L[i] == 'a' || L[i] == 'e' || L[i] == 'i' || L[i] == 'o' || L[i] == 'u')
                {
                    res[i + 1] = res[i];
                    cnt = 0;
                }
                else
                {                    
                    cnt++;

                    if (cnt >= n)
                        res[i + 1] = i + 1 - n + 1;
                    else
                        res[i + 1] = res[i];
                }
            }

            long result = 0;

            for (int i = 0; i < N; i++)
            {
                result += res[i + 1];
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, result);
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
