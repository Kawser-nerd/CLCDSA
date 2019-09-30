using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QRA
{
    class ProblemData
    {
        public int N;
        public int K;

        public static void InitData()
        {

        }

        public static ProblemData Parse(string line)
        {
            var ints = line.Split(' ').Select(s => int.Parse(s)).ToArray();
            return new ProblemData()
            {
                N = ints[0],
                K = ints[1]
            };
        }

        public string Calc()
        {
            int temp = K - ((K >> N) << N);
            bool result = temp == (1 << N) - 1;
            return result ? "ON" : "OFF";
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
            var solve = new SolveProblem("A-small-attempt0");
            solve.SolveAndWrite();
        }
    }
}
