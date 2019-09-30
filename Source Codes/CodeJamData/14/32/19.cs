

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
    using System.Collections.Generic;
    using System.Text;

    public class ProblemB : IProblem
    {
        private int N;
        private int count;

        public string SolveOneCase(InputParser input)
        {
            N = input.GetInt();
            count = 0;

            var cars = input.GetStringArray();
            Permute(new bool[N], new List<int>(), cars);


            return count.ToString();
        }

        public void Permute(bool[] els, List<int> set, string[] cars)
        {
            if( set.Count == N)
            {
                var sb = new StringBuilder();
                for (int i = 0; i < set.Count; i++)
                {
                    sb.Append(cars[set[i]]);
                }

                var train = sb.ToString();
                if (check(train))
                    count++;
                return;
            }

            for (int i = 0; i < els.Length; i++)
            {
                if( els[i] == true)
                    continue;

                els[i] = true;
                set.Add(i);
                Permute(els, set, cars);
                set.Remove(i);
                els[i] = false;

            }


        }

        private bool check(string train)
        {
            var dict = new HashSet<char>();

            var let = train[0];
            dict.Add(let);

            for (int i = 0; i < train.Length; i++)
            {
                if( train[i] == let)
                    continue;

                let = train[i];
                if (dict.Contains(let))
                    return false;

                dict.Add(let);
            }

            return true;
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