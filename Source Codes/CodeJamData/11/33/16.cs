using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Template
{
    public class Program
    {
        private const string InputFileName = @"C:\disk\input.in";
        private const string OutputFileName = @"C:\disk\output.out";

        public static void Main()
        {
            using (StreamReader sr = new StreamReader(InputFileName))
            using (StreamWriter sw = new StreamWriter(OutputFileName))
            {
                int numberOfTests = int.Parse(sr.ReadLine());
                for (int testNumber = 1; testNumber <= numberOfTests; testNumber++)
                {
                    //input
                    string[] line = sr.ReadLine().Split(' ');
                    int players = int.Parse(line[0]);
                    long lowest = long.Parse(line[1]);
                    long highest = long.Parse(line[2]);

                    SortedSet<long> tempFrequencies = new SortedSet<long>();
                    line = sr.ReadLine().Split(' ');
                    for (int i = 0; i < players; i++)
                    {
                        tempFrequencies.Add(long.Parse(line[i]));
                    }
                    List<long> frequencies = tempFrequencies.ToList();
                    frequencies.Sort();

                    //logic
                    bool possible = false;
                    long tone = -1;
                    long bcd = 1;
                    for (long i = lowest; i <= highest && !possible; i++)
                    {
                        if (IsAvailableSubTone(frequencies, i))
                        {
                            possible = true;
                            tone = i;
                        }
                    }

                    Console.Write("Case #{0}: ", testNumber);
                    sw.Write("Case #{0}: ", testNumber);
                    if (possible)
                    {
                        Console.WriteLine("{0}", tone);
                        sw.WriteLine("{0}", tone);
                    }
                    else
                    {
                        Console.WriteLine("NO", testNumber);
                        sw.WriteLine("NO", testNumber);
                    }
                }
            }
        }

        private static bool IsAvailableSubTone(List<long> frequencies, long tone)
        {
            foreach (long frequency in frequencies)
            {
                if (frequency % tone != 0 &&
                    tone % frequency != 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
