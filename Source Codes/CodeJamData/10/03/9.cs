using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QRC
{
    class ProblemData
    {
        int R;
        int k;
        int[] gList;

        public static void InitData()
        {

        }

        public static ProblemData Parse(StreamReader stream)
        {
            var ints = stream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var intlist = stream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            return new ProblemData()
            {
                R = ints[0],
                k = ints[1],
                gList = intlist
            };
        }

        IEnumerable<int> gEnum()
        {
            while (true)
            {
                foreach (int g in gList)
                    yield return g;
            }
        }

        public string Calc()
        {
            int gindex = 0;
            long money = 0;

            for (int roundIndex = 0; roundIndex < R; roundIndex++)
            {
                int restSeat = k;
                int startIndex = gindex;

                while (restSeat >= gList[gindex])
                {
                    restSeat -= gList[gindex];

                    gindex++;
                    
                    if (gindex == gList.Length)
                        gindex = 0;

                    if (gindex == startIndex)
                        break;
                }

                money += k - restSeat;
                
                if (gindex == 0)
                {
                    int repeatround = roundIndex + 1;
                    int repeatTimes = R / repeatround;
                    roundIndex = repeatTimes * repeatround - 1;
                    money *= repeatTimes;
                }
            }

            return money.ToString();
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
                    yield return ProblemData.Parse(stream);
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
            string problemName = "C";
            string dataFileName = problemName + "-small-attempt0";
            //string dataFileName = problemName + "-small-attempt1";
            //string dataFileName = problemName + "-small-attempt2";
            //string dataFileName = problemName + "-large";

            var solve = new SolveProblem(dataFileName);
            solve.SolveAndWrite();
        }
    }
}
