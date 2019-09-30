using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam2013
{
    public class P2CA
    {
        private const string INPUT_FILE = @"E:\work\codejam2013\data\A-large.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2CA();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(INPUT_FILE);
            Console.WriteLine(INPUT_FILE + ".out");
            using (mOutput = new StreamWriter(INPUT_FILE + ".out"))
            using (mInput = new StreamReader(INPUT_FILE))
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
            string[] strs = mInput.ReadLine().Split();
            var name = strs[0];
            var n = int.Parse(strs[1]);
            var l = name.Length;

            long[] ends = new long[l];
            for (int i = 0; i < l; i++)
            {
                if (!IsConsonant(name[i]))
                    ends[i] = 0;
                else
                    ends[i] = i > 0 ? ends[i - 1] + 1 : 1;
            }

            //long[] begins= new long[l];
            //for (int i = l-1; i >= 0; i--)
            //{
            //    if (IsConsonant(name[i]))
            //        begins[i] = i < l - 1 ? begins[i + 1] + 1 : 0;
            //}

            long[] t = new long[l];
            for (int i = 0; i < l; i++)
                if (ends[i] >= n)
                    t[i] = i + 2 - n;
                else
                    t[i] = i > 0 ?  t[i - 1] : 0;

            long sum = 0;
            for (int i = 0; i < l; i++)
                    sum = sum + t[i];
            
            return "" + sum;
        }

        private bool IsConsonant(char c)
        {
            return !"aeiou".Contains(c);
        }

        #region Utilities Methods

        private int[] ReadIntsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private long[] ReadLongsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(long.Parse).ToArray();
        }

        private double[] ReadDoublesFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => double.Parse(x)).ToArray();
        }

        private IEnumerable<string> ReadStrings()
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
