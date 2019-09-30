using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1B_Problem_B
{
    public class CaseData
    {
        private List<Pair> m_BoxPairs;
        private List<Pair> m_ToyPairs;


        public CaseData(List<Pair> boxPairs, List<Pair> toyPairs)
        {
            m_BoxPairs = boxPairs;
            m_ToyPairs = toyPairs;
        }

        public string Solve()
        {
            int currentBoxPairIndex = 0;
            long currentBoxPairCount = 0;
            int currentToyPairIndex = 0;
            long currentToyPairCount = 0;

            long boxedToys = 0;

            long bestBoxed = SolveRecurse(currentBoxPairIndex, currentBoxPairCount, currentToyPairIndex, currentToyPairCount, boxedToys);

            return bestBoxed.ToString();
        }


        private long SolveRecurse(int currentBoxPairIndex, long currentBoxPairCount, int currentToyPairIndex, long currentToyPairCount, long boxedToys)
        {
            // if they are the same always process
            var currentBoxPair = m_BoxPairs[currentBoxPairIndex];
            var currentToyPair = m_ToyPairs[currentToyPairIndex];
            if (currentBoxPairCount == currentBoxPair.Y)
            {
                currentBoxPairCount = 0;
                currentBoxPairIndex++;
                if (currentBoxPairIndex == m_BoxPairs.Count)
                {
                    return boxedToys;
                }
                currentBoxPair = m_BoxPairs[currentBoxPairIndex];
            }
            if (currentToyPairCount == currentToyPair.Y)
            {
                currentToyPairCount = 0;
                currentToyPairIndex++;
                if (currentToyPairIndex == m_ToyPairs.Count)
                {
                    return boxedToys;
                }
                currentToyPair = m_ToyPairs[currentToyPairIndex];
            }
            while(currentBoxPair.X == currentToyPair.X)
            {
                long numToProcess = long.MaxValue;
                numToProcess = Math.Min(numToProcess, currentToyPair.Y - currentToyPairCount);
                numToProcess = Math.Min(numToProcess, currentBoxPair.Y - currentBoxPairCount);
                boxedToys += numToProcess;
                currentBoxPairCount += numToProcess;
                currentToyPairCount += numToProcess;
                if(currentBoxPairCount == currentBoxPair.Y)
                {
                    currentBoxPairCount = 0;
                    currentBoxPairIndex++;
                    if(currentBoxPairIndex == m_BoxPairs.Count)
                    {
                        return boxedToys;
                    }
                    currentBoxPair = m_BoxPairs[currentBoxPairIndex];
                }
                if (currentToyPairCount == currentToyPair.Y)
                {
                    currentToyPairCount = 0;
                    currentToyPairIndex++;
                    if (currentToyPairIndex == m_ToyPairs.Count)
                    {
                        return boxedToys;
                    }
                    currentToyPair = m_ToyPairs[currentToyPairIndex];
                }
            }
            // they are not the same 2 choices move box line or move toy line
            long bestMove = long.MinValue;
            long numberToNextToyLine = currentToyPair.Y - currentToyPairCount;
            long numberToNextBoxLine = currentBoxPair.Y - currentBoxPairCount;
            // move toyline
            bestMove = Math.Max(bestMove, SolveRecurse(currentBoxPairIndex, currentBoxPairCount, currentToyPairIndex, currentToyPairCount + numberToNextToyLine, boxedToys));
            bestMove = Math.Max(bestMove, SolveRecurse(currentBoxPairIndex, currentBoxPairCount + numberToNextBoxLine, currentToyPairIndex, currentToyPairCount, boxedToys));

            return bestMove;
        }
    }

    public class Pair
    {
        public long X { get; set; }
        public long Y { get; set; }

        public Pair(long x, long y)
        {
            X = x;
            Y = y;
        }
    }

    class Program
    {
        const string INPUT_FILE = "C-small-attempt1.in";
        const string OUTPUT_FILE = "C-small-attempt1.out";

        static void Main(string[] args)
        {
            Console.WriteLine(long.MaxValue);
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<long>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count == 2);
                var numBoxes = ints[0];
                var numToys = ints[1];

                var boxData = lines[currentLineNumber];
                currentLineNumber++;
                var boxPairs = new List<Pair>();
                {
                    var tokens = boxData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Assert(tokens.Length %2 == 0);
                    for(int j=0; j<tokens.Length;j+=2)
                    {
                        var boxCount = long.Parse(tokens[j]);
                        var boxType = long.Parse(tokens[j + 1]);
                        boxPairs.Add(new Pair(boxType, boxCount));
                    }
                }

                var toyData = lines[currentLineNumber];
                currentLineNumber++;
                var toyPairs = new List<Pair>();
                {
                    var tokens = toyData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    Debug.Assert(tokens.Length % 2 == 0);
                    for (int j = 0; j < tokens.Length; j += 2)
                    {
                        var toyCount = long.Parse(tokens[j]);
                        var toyType = long.Parse(tokens[j + 1]);
                        toyPairs.Add(new Pair(toyType, toyCount));
                    }
                }
                
                cases.Add(new CaseData(boxPairs, toyPairs));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }

    }
}
