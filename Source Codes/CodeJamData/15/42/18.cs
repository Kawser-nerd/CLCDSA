

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
    using System;
    using System.Linq;

    public class ProblemB : IProblem
    {
        private string IMPOSSIBLE = "IMPOSSIBLE";

        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();
            double V = double.Parse(input.GetString());
            double X = double.Parse(input.GetString());

            double R0 = double.Parse(input.GetString());
            double C0 = double.Parse(input.GetString());

            if( N == 1)
            {
                if (C0 != X)
                    return IMPOSSIBLE;
                else
                {
                    return (V/R0).ToString();
                }

            }



            double R1 = double.Parse(input.GetString());
            double C1 = double.Parse(input.GetString());

            if (C0 < X && C1 < X)
                return IMPOSSIBLE;
            if (C0 > X && C1 > X)
                return IMPOSSIBLE;

            if (X == C0 || X == C1)
            {
                double r = 0;
                if (X == C0) r += R0;
                if (X == C1) r += R1;

                return (V/r).ToString();
            }

            var v0 = V*(X - C1)/(C0 - C1);
            var v1 = V - v0;

            var t0 = v0/R0;
            var t1 = v1/R1;

            var res = Math.Max(t0, t1);

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