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
            int N = Convert.ToInt32(inputStream.ReadLine());
            Pair[] A = new Pair[N];
            Pair[] B = new Pair[N];

            string[] tmp = inputStream.ReadLine().Split(' ');

            for (int i = 0; i < N; i++)
            {
                Pair pair = new Pair(Convert.ToInt32(tmp[i]), i);
                A[i] = pair;
                B[i] = pair;
            }

            Array.Sort<Pair>(B);

            int last = N - 1;
            int res = 0;

            for (int i = 0; i < N; i++)
            {
                res += Math.Min(B[i].Second, last - B[i].Second);
                last--;

                for (int j = B[i].Second + 1; j < N; j++)
                {
                    if (A[j].First > B[i].First)
                        A[j].Second--;
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        public class Pair : IComparable<Pair>
        {
            public int First;
            public int Second;

            public Pair(int f, int s)
            {
                this.First = f;
                this.Second = s;
            }

            public int CompareTo(Pair other)
            {
                return this.First.CompareTo(other.First);
            }
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
