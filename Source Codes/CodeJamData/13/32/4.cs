using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam2013
{
    public class P2CB
    {
        private const string mInputFile = @"E:\work\codejam2013\data\B-small-attempt0.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2CB();
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
            var xd = ints[0];
            int yd = ints[1];

            StringBuilder sb = new StringBuilder();
            int x = 0;
            int y = 0;
            int l = 1;
            if (x < xd)
            {
                sb.Append("E");
                x++;
            }
            else
            {
                sb.Append("W");
                x--;
            }

            l = 2;
            while (x < xd)
            {
                sb.Append("W");
                sb.Append("E");
                x++;
            }

            while (x > xd)
            {
                sb.Append("E");
                sb.Append("W");
                x--;
            }

            while (y < yd)
            {
                sb.Append("S");
                sb.Append("N");
                y++;
            }

            while (y > yd)
            {
                sb.Append("N");
                sb.Append("S");
                y--;
            }

            return sb.ToString();
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
