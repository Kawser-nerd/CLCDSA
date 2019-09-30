

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemA(), Console.In, Console.Out);
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
    using System.Collections.Generic;
    using System.Linq;

    public class ProblemA : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();
            int L = input.GetInt();

            var outlets = input.GetStringArray();
            List<int> outs = new List<int>();

            var devices = input.GetStringArray();
            List<int> devs = new List<int>();

            for (int i = 0; i < N; i++)
            {
                outs.Add(Convert.ToInt32(outlets[i], 2));
                devs.Add(Convert.ToInt32(devices[i], 2));
            }

            int max = 2 << L+1;

            int best = int.MaxValue;

            for (int i = 0; i <= max; i++)
            {
                int i1 = i;
                var copy = outs.Select(x => x ^ i1).ToList();

                var ex = copy.Except(devs);

                if( ex.Count() == 0)
                {
                    var b = count_bits(i);
                    if (b < best)
                        best = b;
                }
            }

            if (best == int.MaxValue)
                return "NOT POSSIBLE";
            return best.ToString();
        }

        private int count_bits(long n)
        {
            int c; // c accumulates the total bits set in v
            for (c = 0; n>0; c++)
                n &= n - 1; // clear the least significant bit set
            return c;
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