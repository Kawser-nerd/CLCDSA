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
            string S = inputStream.ReadLine();
            int[] A = new int[26];
            int[] N = new int[10];

            for (int i = 0; i < S.Length; i++)
            {
                A[Change(S[i])]++;
            }

            Check(A, N, "ZERO", 0, 'Z');
            Check(A, N, "TWO", 2, 'W');
            Check(A, N, "FOUR", 4, 'U');
            Check(A, N, "SIX", 6, 'X');
            Check(A, N, "EIGHT", 8, 'G');
            Check(A, N, "SEVEN", 7, 'S');
            Check(A, N, "FIVE", 5, 'V');
            Check(A, N, "THREE", 3, 'T');
            Check(A, N, "ONE", 1, 'O');
            Check(A, N, "NINE", 9, 'I');

            for (int i = 0; i < A.Length; i++)
            {
                if (A[i] > 0)
                    throw new ApplicationException("i");
            }

            string res = String.Empty;

            for (int i = 0; i < 10; i++)
            {
                while (N[i] > 0)
                {
                    res += i.ToString();
                    N[i]--;
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        private void Check(int[] A, int[] N, string number, int i, char c)
        {
            N[i] = A[Change(c)];

            for (int j = 0; j < number.Length; j++)
            {
                A[Change(number[j])] -= N[i];
            }
        }

        private int Change(char c)
        {
            return c - 'A';
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
