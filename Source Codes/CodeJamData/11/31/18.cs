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
        public long y;
        public long x;
        public List<string> grid = new List<string>();



        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();

            var tokens = testLine.Split(' ');

            results.y = long.Parse(tokens[0]);
            results.x = long.Parse(tokens[1]);

            for (int i = 0; i < results.y; i++)
            {
                results.grid.Add(inputFile.ReadLine());
            }

            
            return results;
        }

    }
}