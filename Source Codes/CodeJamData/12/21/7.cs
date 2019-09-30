using System;
using System.Collections.Generic;
using System.IO;
using System.Globalization;
using System.Threading;

namespace A
{
    class Program
    {
        static string iFile = "A-small.in";
        static string oFile = "A-small.out";
        //static string iFile = "A-large.in";
        //static string oFile = "A-large.out";

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(iFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(oFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        static void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int N = Convert.ToInt32(tmp[0]);

            int[] scores = new int[N];
            int full = 0;

            for (int i = 0; i < N; i++)
            {
                scores[i] = Convert.ToInt32(tmp[i + 1]);
                full += scores[i];
            }

            outputStream.Write("Case #{0}:", testCase);

            for (int i = 0; i < N; i++)
            {
                double low = 0;
                double high = 1;
                double eps = 0.000000001;

                while (high - low > eps)
                {
                    double medium = (high + low) / 2;

                    double rest = 1 - medium;

                    for (int j = 0; j < N; j++)
                    {
                        if (i != j)
                        {
                            double t = (scores[i] - scores[j] + medium * full) / full;

                            if (t > 0)
                                rest -= t;

                            if (rest < 0)
                                break;
                        }
                    }

                    if (rest < 0)
                        high = medium;
                    else
                        low = medium;
                }

                double result = (high + low) / 2;
                outputStream.Write(" {1:0.000000}", testCase, result * 100);
            }

            outputStream.WriteLine();
        }
    }
}
