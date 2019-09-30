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
        public long NumbOfNotes;
        public long LowNote;
        public long HighNote;
        public List<long> Notes = new List<long>();



        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();

            var tokens = testLine.Split(' ');

            results.NumbOfNotes = long.Parse(tokens[0]);
            results.LowNote = long.Parse(tokens[1]);
            results.HighNote = long.Parse(tokens[2]);

            testLine = inputFile.ReadLine();
            tokens = testLine.Split(' ');

            for (int i = 0; i < results.NumbOfNotes; i++)
            {
                results.Notes.Add(long.Parse(tokens[i]));
            }

            
            return results;
        }

    }
}