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
        public string GetInputFile() { return @"D:\projects\VS2015\gcj\gcj\Round1C\QuestionC\C-large.in"; }

        public string DoIteration(Scanner input, Output output)
        {
            int jackets = input.NextInt(),
                pants = input.NextInt(),
                shirts = input.NextInt(),
                max2combo = input.NextInt();

            List<Combination> result1 = new List<Combination>();
            List<Combination> result2 = new List<Combination>();
            int results = 0;

            for (int jacket_c = 1; jacket_c <= jackets; jacket_c++)
            {
                for (int pant_c = 1; pant_c <= pants; pant_c++)
                {
                    for (int i = 0; i < Math.Min(max2combo, shirts); i++)
                    {
                        var c = new Combination();
                        c.jacket = jacket_c;
                        c.pant = pant_c;
                        c.shirt = 0;

                        result1.Add(c);
                    }
                }
            }

            int shirt_c = 0,
                shirt_start = 0,
                shirt_done = 0;

            for (int i = 0; i < result1.Count; i++)
            {
                int jacket_m = result1[i].jacket,
                    pant_m = result1[i].pant;

                int shirt_m = ++shirt_c;


                shirt_done++;
                shirt_m %= shirts;
                if (shirt_m == 0)
                {
                    shirt_m = shirts;
                }

                if ((jackets * pants) % shirts == 0)
                {

                    if (shirt_done == shirts)
                    {
                        shirt_start++;
                        shirt_c = shirt_start;
                        shirt_done = 0;
                    }
                }
                
                Debug.WriteLine("We try {0} {1} {2}", jacket_m, pant_m, shirt_m);

                var combsSoFar1 = result2.Where(c => (shirt_m == c.shirt) && (pant_m == c.pant)).Count();
                var combsSoFar2 = result2.Where(c => (jacket_m == c.jacket) && (pant_m == c.pant)).Count();
                var combsSoFar3 = result2.Where(c => (shirt_m == c.shirt) && (jacket_m == c.jacket)).Count();

                if (combsSoFar1 < max2combo && combsSoFar2 < max2combo && combsSoFar3 < max2combo)
                {
                    var c = new Combination();
                    c.jacket = jacket_m;
                    c.pant = pant_m;
                    c.shirt = shirt_m;

                    result2.Add(c);
                }
            }

            StringBuilder str = new StringBuilder();
            for (int i = 0; i < result2.Count; i++)
            {
                str.AppendFormat("\r\n{0} {1} {2}", result2[i].jacket, result2[i].pant, result2[i].shirt);
            }

            return result2.Count + str.ToString();
        }

        struct Combination
        {
            public int jacket,
                pant,
                shirt;
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
