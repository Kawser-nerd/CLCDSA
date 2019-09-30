

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemB(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿


namespace Contest
{
    using System.Linq;

    public class ProblemB : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int K = input.GetInt();
            int L = input.GetInt();
            int S = input.GetInt();

            string alph = input.GetString();
            string word = input.GetString();

            // not in alphabet
            for (int i = 0; i < L; i++)
            {
                var c = word[i];
                if(!alph.Contains(c.ToString()))
                {
                    return "0.0";
                }
            }

            // all same
            bool same = true;
            var a = word[0];
            for (int i = 0; i < L; i++)
            {
                if (word[i] != a)
                    same = false;
            }
            for (int i = 0; i < K; i++)
            {
                if (alph[i] != a)
                    same = false;
            }

            if (same)
                return "0.0";

            int overlap = 0;
            for (int i = 1; i < L; i++)
            {
                var st = word.Substring(0, i);
                var e = word.Substring(word.Length - i, i);

                if (st == e)
                    overlap = i;
            }

            int count = 0;
            int ii = 0;
            while(true)
            {
                if( ii + L <= S)
                {
                    count++;
                    ii = ii + L - overlap;
                    continue;
                }
                break;
            }

            double p = 1;
            for (int i = 0; i < L; i++)
            {
                var aa = word[i];
                double cc = alph.Count(x => x == aa);
                p *= cc/K;
            }

            var res = count - p*(S - L + 1);


            return res.ToString();
        }
    }
}﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}