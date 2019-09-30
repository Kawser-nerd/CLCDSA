using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace QRB
{
    class ProblemData
    {
        BigInteger[] IntList;

        public static void InitData()
        {

        }

        public static ProblemData Parse(string line)
        {
            var ints = line.Split(' ').Skip(1).Select(s => BigInteger.Parse(s));

            return new ProblemData()
            {
                IntList = ints.ToArray()
            };
        }

        public string Calc()
        {
            Array.Sort(IntList);
            var list = IntList.Skip(1).Select(i => i - IntList[0]).ToArray();

            var gcd = list.Aggregate((a, b) => BigInteger.GreatestCommonDivisor(a, b));

            if (gcd == BigInteger.One)
                return "0";

            var result = gcd - (IntList[0] % gcd);
            if (result == gcd)
                return "0";

            return result.ToString();
        }
    }

    class SolveProblem
    {
        string DataFileName;

        public SolveProblem(string dataFileName)
        {
            DataFileName = dataFileName;
        }

        IEnumerable<ProblemData> ReadData()
        {
            using (var stream = File.OpenText(DataFileName + ".in"))
            {
                var linenum = int.Parse(stream.ReadLine());
                for (int index = 0; index < linenum; index++)
                {
                    yield return ProblemData.Parse(stream.ReadLine());
                }
            }
        }

        public void SolveAndWrite()
        {
            var dataList = ReadData();
            ProblemData.InitData();
            var resultList = dataList.Select(d => d.Calc());

            using (var stream = File.CreateText(DataFileName + ".out"))
            {
                int count = 1;
                foreach (var result in resultList)
                {
                    stream.WriteLine("Case #{0}: {1}", count, result);
                    count++;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string problemName = "B";
            string dataFileName = problemName + "-small-attempt0";
            //string dataFileName = problemName + "-small-attempt1";
            //string dataFileName = problemName + "-small-attempt2";
            //string dataFileName = problemName + "-large";

            var solve = new SolveProblem(dataFileName);
            solve.SolveAndWrite();
        }
    }
}
