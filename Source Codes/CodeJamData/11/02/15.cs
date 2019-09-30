using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace GCJ11QRQ2
{
    class Q2
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');

                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(bits)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(string[] bits)
        {
            int combineCount = int.Parse(bits[0]);
            var combines = new Dictionary<char, List<KeyValuePair<char,char>>>();
            for (int i = 0; i < combineCount; i++)
            {
                Add(combines, bits[i + 1][0], bits[i + 1][1], bits[i + 1][2]);
                Add(combines, bits[i + 1][1], bits[i + 1][0], bits[i + 1][2]);
            }
            int opposeCount = int.Parse(bits[1 + combineCount]);
            var opposes = new Dictionary<char, List<char>>();
            for (int i = 0; i < opposeCount; i++)
            {
                Add(opposes, bits[i + 2 + combineCount][0], bits[i + 2 + combineCount][1]);
                Add(opposes, bits[i + 2 + combineCount][1], bits[i + 2 + combineCount][0]);
            }
            string toProcess = bits[3 + combineCount + opposeCount].Substring(0, int.Parse(bits[2 + combineCount + opposeCount]));
            List<char> toFormat = new List<char>();
            Dictionary<char, int> current = new Dictionary<char, int>();
            foreach (char c in toProcess)
            {
                if (toFormat.Count == 0)
                {
                    toFormat.Add(c);
                    Add(current, c);
                }
                else
                {
                    char prev = toFormat[toFormat.Count - 1];
                    bool combined = false;
                    List<KeyValuePair<char, char>> combineList;
                    if (combines.TryGetValue(prev, out combineList))
                    {
                        int pos = combineList.FindIndex(delegate(KeyValuePair<char, char> check) { return check.Key == c; });
                        if (pos >= 0)
                        {
                            toFormat.RemoveAt(toFormat.Count - 1);
                            toFormat.Add(combineList[pos].Value);
                            Add(current, combineList[pos].Value);
                            Remove(current, prev);
                            combined = true;
                        }
                    }
                    bool opposed = false;
                    if (!combined)
                    {
                        List<char> opposeList;
                        if (opposes.TryGetValue(c, out opposeList))
                        {
                            foreach (char o in opposeList)
                            {
                                if (current.ContainsKey(o))
                                {
                                    toFormat.Clear();
                                    current.Clear();
                                    opposed = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (!combined && !opposed)
                    {
                        toFormat.Add(c);
                        Add(current, c);
                    }
                }
            }
            string result = "[" + string.Join(", ", toFormat) + "]";
            return result;
        }

        private static void Remove(Dictionary<char, int> current, char prev)
        {
            current[prev] = current[prev] - 1;
            if (current[prev] <= 0)
                current.Remove(prev);
        }

        private static void Add(Dictionary<char, int> current, char p)
        {
            if (current.ContainsKey(p))
                current[p] = current[p] + 1;
            else
                current[p] = 1;
        }

        private static void Add(Dictionary<char, List<char>> opposes, char p, char p_2)
        {
            List<char> cList;
            if (!opposes.TryGetValue(p, out cList))
            {
                cList = new List<char>();
                opposes[p] = cList;
            }
            cList.Add(p_2);
        }

        private static void Add(Dictionary<char, List<KeyValuePair<char, char>>> combines, char p, char p_2, char p_3)
        {
            List<KeyValuePair<char, char>> cList;
            if (!combines.TryGetValue(p, out cList))
            {
                cList = new List<KeyValuePair<char, char>>();
                combines[p] = cList;
            }
            cList.Add(new KeyValuePair<char, char>(p_2, p_3));
        }
    }
}
