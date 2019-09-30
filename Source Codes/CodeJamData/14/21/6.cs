using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_A
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
                output.Flush();
            }
        }

        private static string HandleCase(TextReader input)
        {
            int numStrings = int.Parse(input.ReadLine());
            List<StringReduced> strings = new List<StringReduced>();
            for (int i = 0; i < numStrings; i++)
            {
                strings.Add(new StringReduced(input.ReadLine()));
            }

            // check all strings can match
            for (int i = 1; i < numStrings; i++)
                if (!strings[0].CanMatch(strings[i]))
                    return "Fegla Won";

            // add the average and median string
            string average = "";
            string median = "";
            for (int curPart = 0; curPart < strings[0].substrings.Count; curPart++)
            {
                average += new string(strings[0].substrings[curPart].Item1, (int)Math.Round(strings.Average(str => str.substrings[curPart].Item2)));
                median += new string(strings[0].substrings[curPart].Item1, Median(strings, curPart));
            }
            strings.Add(new StringReduced(average));
            strings.Add(new StringReduced(median));
            const int addedItems = 2;

            // make moves to string matrix
            int[,] movesToMatchMatrix = new int[numStrings, numStrings + addedItems];
            for (int row = 0; row < numStrings; row++)
                for (int col = 0; col < numStrings + addedItems; col++)
                    movesToMatchMatrix[row, col] = strings[row].MovesToMatch(strings[col]);

            // calculate minimum moves
            int min = int.MaxValue;
            for (int col = 0; col < numStrings + addedItems; col++)
                min = Math.Min(min, SumCol(col, movesToMatchMatrix));

            return min.ToString();
        }

        private static int Median(List<StringReduced> strings, int curpart)
        {
            var sorted = strings.OrderBy(str => str.substrings[curpart].Item2).ToList();
            double mid = (sorted.Count - 1) / 2.0;
            return (int)(Math.Round((sorted[(int)(mid)].substrings[curpart].Item2 + sorted[(int)(mid + 0.5)].substrings[curpart].Item2) / 2.0));
        }

        private static int SumCol(int col, int[,] matrix)
        {
            int sum = 0;
            for (int row = 0; row < matrix.GetLength(0); row++)
            {
                sum += matrix[row, col];
            }
            return sum;
        }

        private class StringReduced
        {
            public List<Tuple<char, int>> substrings;

            public StringReduced(string original)
            {
                substrings = new List<Tuple<char, int>>();
                int index = 1;
                char ch = original[0];
                int count = 1;
                while (index < original.Length)
                {
                    if (original[index] == ch)
                    {
                        count++;
                    }
                    else
                    {
                        substrings.Add(new Tuple<char, int>(ch, count));
                        ch = original[index];
                        count = 1;
                    }
                    index++;
                }
                substrings.Add(new Tuple<char, int>(ch, count));
            }

            public bool CanMatch(StringReduced other)
            {
                // if number of substrings is different, they can't match
                if (this.substrings.Count != other.substrings.Count)
                    return false;

                // if order is different, they can't match
                for (int i = 0; i < this.substrings.Count; i++)
                    if (this.substrings[i].Item1 != other.substrings[i].Item1)
                        return false;

                return true;
            }

            public int MovesToMatch(StringReduced other)
            {
                int moves = 0;
                for (int i = 0; i < this.substrings.Count; i++)
                {
                    moves += Math.Abs(this.substrings[i].Item2 - other.substrings[i].Item2);
                }
                return moves;
            }
        }
    }
}
