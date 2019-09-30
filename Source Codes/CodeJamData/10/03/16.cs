using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using(StreamReader sr = new StreamReader("in.txt"))
            {
                using (StreamWriter sw = new StreamWriter("out.txt"))
                {
                    IEnumerator<string> tokenizer = Tokens(sr, new char[] { ' ', '\t' }).GetEnumerator();
                    long C = GetLong(tokenizer);
                    for (int c = 0; c < C; c++)
                    {
                        int runs = GetInt(tokenizer);
                        int peopleOnCoaster = GetInt(tokenizer);
                        int groupCount = GetInt(tokenizer);
                        int[] groups = new int[groupCount];
                        for (int i = 0; i < groupCount; i++)
                            groups[i] = GetInt(tokenizer);

                        sw.WriteLine("Case #{0}: {1}", c+1, Answer(runs, peopleOnCoaster, groups));
                    }
                }
            }
        }

        private static long Answer(int runs, int maxPeopleOnCoaster, int[] groups)
        {
            long euros = 0;

            TripCacheEntry[] cache = new TripCacheEntry[groups.Length];
            int g = 0;
            for (int i = 0; i < runs; i++)
            {
                TripCacheEntry tripResults = MakeTrip(i, maxPeopleOnCoaster, g, groups, cache, euros);

                if (tripResults.EncounteredCount == 2) // we have been here before, once
                {
                    int runsToGo = runs - i - 1;
                    int cycleLength = i - tripResults.RunAtFirstEncounter;
                    if (runsToGo > cycleLength) //We can short-circut a bit
                    {
                        int cyclesToShortCircut = runsToGo / cycleLength;
                        long eurosPerCycle = euros - tripResults.EurosAtFirstEncounter;
                        euros += eurosPerCycle * cyclesToShortCircut;
                        i += cyclesToShortCircut * cycleLength;
                    }
                }
                euros += tripResults.EurosMadeForThisTrip;
                g = tripResults.FirstGroupInLineNextRun;
                
            }

            return euros;
        }
        
        struct TripCacheEntry
        {
            public int EncounteredCount;
            public int FirstGroupInLineNextRun;
            public int RunAtFirstEncounter;
            public long EurosAtFirstEncounter;
            public long EurosMadeForThisTrip; 
        }
 

        private static TripCacheEntry MakeTrip(int currentRun, int maxPeopleOnCoaster, int firstGroupInLine, int[] groups, TripCacheEntry[] cache, long currentEuroCount)
        {
            if (cache[firstGroupInLine].EncounteredCount == 0)
            {
                cache[firstGroupInLine].RunAtFirstEncounter = currentRun;
                cache[firstGroupInLine].EurosMadeForThisTrip = groups[firstGroupInLine];
                maxPeopleOnCoaster -= groups[firstGroupInLine];
                int g = (firstGroupInLine + 1) % groups.Length;
                for (;
                    g != firstGroupInLine && maxPeopleOnCoaster - groups[g] >= 0; 
                    g = ((g + 1) % groups.Length))
                {
                    
                    cache[firstGroupInLine].EurosMadeForThisTrip += groups[g];
                    maxPeopleOnCoaster -= groups[g];
                }

                cache[firstGroupInLine].FirstGroupInLineNextRun = g;
                cache[firstGroupInLine].EurosAtFirstEncounter = currentEuroCount;
                
            }

            cache[firstGroupInLine].EncounteredCount++;
            return cache[firstGroupInLine];
        }

        #region Parsing
        static int GetInt(IEnumerator<string> tokenizer)
        {
            int ret;
            if (tokenizer.MoveNext() && int.TryParse(tokenizer.Current, out ret))
                return ret;
            else
            {
                throw new Exception("Not parsable");
            }
        }

        static long GetLong(IEnumerator<string> tokenizer)
        {
            long ret;
            if (tokenizer.MoveNext() && long.TryParse(tokenizer.Current, out ret))
                return ret;
            else
            {
                throw new Exception("Not parsable");
            }
        }

        static IEnumerable<string> Tokens(StreamReader reader, char[] delimit)
        {
            while (!reader.EndOfStream)
            {
                string[] tokens = reader.ReadLine().Split(delimit, StringSplitOptions.RemoveEmptyEntries);
                foreach (string str in tokens)
                {
                    yield return str;
                }
            }
        }
        #endregion Parsing
    }

}
