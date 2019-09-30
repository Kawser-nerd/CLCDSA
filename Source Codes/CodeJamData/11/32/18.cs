using System.Collections.Generic;
using System.IO;

namespace CodeJam
{
    public abstract class TestCaseDataRequired
    {
        public long CaseNumber;
        public string Results;
    }


    public class TestCaseData : TestCaseDataRequired
    {
        public long TwiceNormalSpeed = 1;
        public double TwiceBoostedSpeed = 2;
        public long MaxSpeedboosters;
        public long HoursToBuildSpeedBoosters;
        public long StarToTravilTo;
        public long C;
        public List<long> DistanceBetweenStars = new List<long>();



        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();

            var tokens = testLine.Split(' ');


            results.MaxSpeedboosters = long.Parse(tokens[0]);
            results.HoursToBuildSpeedBoosters = long.Parse(tokens[1]);
            results.StarToTravilTo = long.Parse(tokens[2]);
            results.C = long.Parse(tokens[3]);

            for (int i = 0; i < results.C; i++)
            {
                results.DistanceBetweenStars.Add(long.Parse(tokens[4 + i]));
            }

            
            return results;
        }

    }
}