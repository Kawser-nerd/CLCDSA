using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam2013
{
    public class P2AB
    {
        private const string mInputFile = @"E:\work\codejam2013\data\B-small-attempt0.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2AB();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (mOutput = new StreamWriter(mInputFile + ".out"))
            using (mInput = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(mInput.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    WriteResult(i + 1, RunTest());
                }
            }
        }

        private string RunTest()
        {
            var ints = ReadIntsFromLine();
            var E = ints[0];
            var R = ints[1];
            var N = ints[2];

            var V = ReadIntsFromLine();

            decimal[] gains = new decimal[E + 1];
            decimal[] gains2 = new decimal[E + 1];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j <= E; j++)
                    gains2[j] = 0;

                for (int e = 0; e <= E; e++)
                {
                    for (int e2 = 0; e2 <= e; e2++)
                    {
                        decimal g = e2*V[i];
                        int newEngery = Math.Min(E, e - e2 + R);
                        gains2[(int) newEngery] = Math.Max(gains2[newEngery], gains[e] + g);
                    }
                }
                //var temp = gains;
                //gains = gains2;
                //gains2 = temp;

                for (int j = 0; j <= E; j++)
                    gains[j] = gains2[j];
            }

            return "" + gains2.Max();
        }

        #region Utilities Methods

        private int[] ReadIntsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private double[] ReadDoublesFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => double.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings()
        {
            string line = null;
            while ((line = mInput.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void WriteResult(int testNum, string result)
        {
            mOutput.WriteLine(string.Format("Case #{0}: {1}", testNum, result));
        }

        #endregion
    }
}
