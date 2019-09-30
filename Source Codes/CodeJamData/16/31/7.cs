using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1C.QuestionA
{
    public class Solution : ISolution
    {
        public string GetInputFile() { return @"D:\projects\VS2015\gcj\gcj\Round1C\QuestionA\A-large.in"; }

        public string DoIteration(Scanner input, Output output)
        {
            int parties = input.NextInt();
            Dictionary < char, int> senators = new Dictionary<char, int>();

            for (int i = 0; i < parties; i++)
            {
                senators.Add((char) (i + 65), input.NextInt());
            }

            StringBuilder str = new StringBuilder();

            while (senators.Any(s => s.Value > 0))
            {
                var maxValue = senators.Aggregate((l, r) => l.Value > r.Value ? l : r).Value;

                var maxSenators = senators.Where(s => s.Value == maxValue);

                if (maxSenators.Count() % 2 == 1)
                {
                    maxSenators = maxSenators.Take(1);
                } else
                {
                    maxSenators = maxSenators.Take(2);
                }

                var first = maxSenators.First();
                var last = maxSenators.Last();

                str.Append(first.Key);
                senators[first.Key]--;

                if (first.Key != last.Key)
                {
                    str.Append(last.Key);
                    senators[last.Key]--;
                }

                str.Append(" ");
            }

            return str.ToString().Substring(0, str.Length - 1);

        }

    }


    #region Boilerplate code identical for every GCJ entry
    public class Program
    {
        public static void Main(string[] args)
        {
            Solution solution = new Solution();
            Scanner input = new Scanner(solution.GetInputFile());
            Output output = new Output(solution.GetInputFile().Replace(".in", ".out"));

            int tests = input.NextInt();
            for (int i = 0; i < tests; i++)
            {
                string result = solution.DoIteration(input, output);
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, result));
            }
        }
    }
    public interface ISolution
    {
        string GetInputFile();
        string DoIteration(Scanner input, Output output);
    }
    public class Scanner
    {
        public readonly string[] lines;

        public int cursorChar,
            cursorLine;

        public Scanner(string file)
        {
            lines = File.ReadAllLines(file);
        }

        public string NextLine()
        {
            string result = string.Empty;

            if (lines[cursorLine].Length >= cursorChar)
            {
                result = lines[cursorLine].Substring(cursorChar).TrimEnd('\r', '\n');
            }

            cursorLine += 1;
            cursorChar = 0;

            return result;
        }

        public string NextWord()
        {
            string result;
            int locationOfSpace = lines[cursorLine].IndexOf(' ', cursorChar);

            if (locationOfSpace == -1)
            {
                result = lines[cursorLine].Substring(cursorChar);
                cursorLine += 1;
                cursorChar = 0;
            }
            else
            {
                int wordLength = locationOfSpace - cursorChar;
                result = lines[cursorLine].Substring(cursorChar, wordLength);
                cursorChar += wordLength + 1;
            }

            return result;
        }

        public int NextInt()
        {
            return int.Parse(NextWord());
        }

        public T Next<T>()
        {
            return (T)Convert.ChangeType(NextWord(), typeof(T));
        }
    }
    public class Output
    {
        private readonly string file;

        public Output(string file)
        {
            this.file = file;
            if (File.Exists(file))
            {
                File.Delete(file);
            }
        }

        public void WriteLine(object line)
        {
            using (StreamWriter writer = new StreamWriter(file, true))
            {
                writer.WriteLine(line.ToString());
            }
            Debug.WriteLine(line.ToString(), "[Out]");
        }
    }
    #endregion
}
