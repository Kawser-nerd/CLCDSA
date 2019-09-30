using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam.Fourteen.Round1B
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1BA : CodeJamProblem<Round1BATestCase>
    {
        protected override void ParseCase(Round1BATestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            var num = int.Parse(field[0]);
            currentLine++;
            for (int i = 0; i < num; i++)
            {
                currentCase.Strings.Add(lines[currentLine].Split(_delimiterChars)[0]);
                currentLine++;
            }
            
        }
        protected override StringBuilder OutputForEachCase(Round1BATestCase testCase, StringBuilder currentString)
        {
            if (testCase.Moves == null)
                currentString.Append("Fegla Won");
            else
                currentString.Append(testCase.Moves.Value);
            return currentString;
        }
    }

    public class Round1BATestCase : ITestCase
    {
        public List<string> Strings { get; set; }
        public int? Moves { get; set; }

        public class StringInfo
        {
            public StringInfo() { }
            public StringInfo(char letter, int count) 
            {
                Letter = letter;
                Count = count;
            }
            public char Letter { get; set; }
            public int Count { get; set; }
        }

        public Round1BATestCase()
        {
            Strings = new List<string>();
        }

        static Round1BATestCase()
        {
        }

        public void Solve()
        {
            int movesSoFar = 0;
            var sinf = new List<List<StringInfo>>();
            foreach (var s in Strings)
            {
                var thisinf = new List<StringInfo>();
                char p = '0';
                StringInfo lastinf = new StringInfo();
                for(int i=0;i<s.Length;i++)
                {
                    if (s[i] != p)
                    {
                        lastinf = new StringInfo(s[i], 1);
                        thisinf.Add(lastinf);
                    }
                    else
                        lastinf.Count++;
                    p = s[i];
                }
                sinf.Add(thisinf);
            }
            var c = sinf.First().Count;
            if (sinf.Any(x => x.Count != c))
                return;
            int pos = 0;
            while (pos < c)
            {
                if (sinf.Any(x => x[pos].Letter != sinf.First()[pos].Letter))
                    return;
                movesSoFar += GetNumberOfMoves(sinf.Select(x=>x[pos].Count));
                pos++;
            }
            Moves = movesSoFar;
        }

        public int GetNumberOfMoves(IEnumerable<int> counts)
        {
            var min = int.MaxValue;
            var distinct = new HashSet<int>(counts);
            var maxcount = counts.Max();
            foreach (var i in distinct)
                min = Math.Min(min, counts.Select(x => Math.Abs(x - i)).Sum());
            return min;
        }
    }
}
