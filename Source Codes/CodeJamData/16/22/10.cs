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
        string bestC = String.Empty;
        string bestJ = String.Empty;

        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] temp = inputStream.ReadLine().Split(' ');
            string C = temp[0];
            string J = temp[1];
            int N = C.Length;

            bestC = String.Empty;
            bestJ = String.Empty;

            Solve(C, J, N);

            outputStream.WriteLine("Case #{0}: {1} {2}", testCase, bestC, bestJ);
        }

        private void Solve(string C, string J, int N)
        {
            int q = -1;
            int d = -1;

            for (int i = 0; i < N; i++)
            {
                if (C[i] != J[i])
                {
                    d = i;
                    break;
                }

                if (C[i] == '?')
                    q = i;
            }

            if (q != -1)
            {
                char[] CA = C.ToCharArray();
                char[] JA = J.ToCharArray();

                for (int i = 0; i < q; i++)
                {
                    if (CA[i] == '?')
                        CA[i] = '0';
                    if (JA[i] == '?')
                        JA[i] = '0';
                }

                C = new string(CA);
                J = new string(JA);
            }            

            if (d == -1)
                Solve0(C, J, N);
            else if (q == -1)
                Solve1(C, J, N, d);
            else
                Solve2(C, J, N, d, q);
        }

        private void Solve0(string C, string J, int N)
        {
            char[] CA = C.ToCharArray();
            char[] JA = J.ToCharArray();

            for (int i = 0; i < N; i++)
            {
                if (CA[i] == '?')
                    CA[i] = '0';
                if (JA[i] == '?')
                    JA[i] = '0';
            }

            Check(new string(CA), new string(JA));
        }

        private void Solve1(string C, string J, int N, int d)
        {
            char[] CA = C.ToCharArray();
            char[] JA = J.ToCharArray();

            int num1 = -1;
            int num2 = -1;

            if (CA[d] != '?')
                num1 = (int)(CA[d] - '0');

            if (JA[d] != '?')
                num2 = (int)(JA[d] - '0');

            if (num1 != -1 && num2 != -1)
            {
                Solve3(C, J, N, num1 > num2);
            }
            else if (num1 == -1)
            {
                if (num2 > 0)
                {                    
                    CA[d] = (char)(num2 - 1 + '0');

                    Solve3(new string(CA), new string(JA), N, false);
                }                

                if (num2 < 9)
                {
                    CA[d] = (char)(num2 + 1 + '0');

                    Solve3(new string(CA), new string(JA), N, true);
                }

                CA[d] = (char)(num2 + '0');

                Solve(new string(CA), new string(JA), N);
            }
            else
            {
                if (num1 > 0)
                {
                    JA[d] = (char)(num1 - 1 + '0');

                    Solve3(new string(CA), new string(JA), N, true);
                }

                if (num1 < 9)
                {
                    JA[d] = (char)(num1 + 1 + '0');

                    Solve3(new string(CA), new string(JA), N, false);
                }

                JA[d] = (char)(num1 + '0');

                Solve(new string(CA), new string(JA), N);
            }
        }

        private void Solve2(string C, string J, int N, int d, int q)
        {
            char[] CA = C.ToCharArray();
            char[] JA = J.ToCharArray();

            CA[q] = '1';
            JA[q] = '0';

            Solve3(new string(CA), new string(JA), N, true);

            CA[q] = '0';
            JA[q] = '1';

            Solve3(new string(CA), new string(JA), N, false);

            CA[q] = '0';
            JA[q] = '0';

            Solve(new string(CA), new string(JA), N);
        }

        private void Solve3(string C, string J, int N, bool first)
        {
            char[] CA = C.ToCharArray();
            char[] JA = J.ToCharArray();

            for (int i = 0; i < N; i++)
            {
                if (CA[i] == '?')
                    CA[i] = first ? '0' : '9';
                if (JA[i] == '?')
                    JA[i] = first ? '9' : '0';
            }

            Check(new string(CA), new string(JA));
        }

        private void Check(string C, string J)
        {
            if (String.IsNullOrEmpty(bestC) || String.IsNullOrEmpty(bestJ))
            {
                bestC = C;
                bestJ = J;
                return;
            }

            long bc = Int64.Parse(bestC);
            long bj = Int64.Parse(bestJ);
            long nc = Int64.Parse(C);
            long nj = Int64.Parse(J);

            if (Math.Abs(nc - nj) < Math.Abs(bc - bj) || (Math.Abs(nc - nj) == Math.Abs(bc - bj) && nc < bc) || (Math.Abs(nc - nj) == Math.Abs(bc - bj) && nc == bc && nj < bj))
            {
                bestC = C;
                bestJ = J;
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
