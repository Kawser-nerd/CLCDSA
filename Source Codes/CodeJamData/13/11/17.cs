using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace codejam2013
{
    public class P2AA
    {
        private const string mInputFile = @"E:\work\codejam2013\data\A-large1.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2AA();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(vol(1, 1));
            Console.WriteLine(vol(2, 1));
            Console.WriteLine(vol(2, 3));

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
            var ints = ReadDecimalFromLine();
            var r = ints[0];
            var t = ints[1];

            decimal l = 1;
            double d = (double) t;
            var d3 = Math.Pow(d, 0.5);
            
            decimal u = Math.Floor((decimal)d3);
            decimal pi = (decimal) Math.PI;
            decimal good = 1;

            while (l < u)
            {
                var m = (l + u)/2;
                //m = Math.Ceiling(m);

                var p = vol(m, r);

                if (p <= t)
                {
                    l = m + 0.5m;
                    good = m;
                }
                else
                {
                    u = m - 0.5m;
                }
            }
            good = Math.Floor((l + u)/2);
            //good = Math.Floor(good);
            //Console.WriteLine(good);
            if (vol(good + 1, r) <= t)
                good = good + 1;
            
            if (vol(good, r) > t)
                good = good - 1;
            
            return "" + good;
        }

        //decimal vol(decimal m, decimal r)
        //{
        //    decimal pi = (decimal)Math.PI;
        //    return m * (2 * pi * r + 1) + m * m * (m - 1);
        //}

        decimal vol(decimal m, decimal r)
        {
            return (m*(2*r + 1) + 2*m*(m - 1));
        }


        #region Utilities Methods

        private BigInteger[] ReadBigIntsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => BigInteger.Parse(x)).ToArray();
        }

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

        private decimal[] ReadDecimalFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => decimal.Parse(x)).ToArray();
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
