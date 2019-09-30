

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemC(), Console.In, Console.Out);
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
    using System.Collections.Generic;
    using System.Linq;

    public class ProblemC : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int C = input.GetInt();
            int D = input.GetInt();
            int V = input.GetInt();

            var Ds = input.GetIntArray();

            var hs = new HashSet<int>();
            hs.Add(0);

            for (int i = 0; i < D; i++)
            {
                var list = hs.ToList();

                var dd = Ds[i];
                for (int j = 0; j < list.Count; j++)
                {
                    int item = list[j] + dd;
                    if (item > V)
                        continue;
                    hs.Add(item);
                }
            }
           

            int count = 0;

            while (true)
            {
                var miss = new List<int>();

                for (int i = 0; i <= V; i++)
                {
                    if (!hs.Contains(i))
                        miss.Add(i);
                }

                if (miss.Count == 0)
                    break;
                miss.Sort();

                var list = hs.ToList();
                var dd = miss[0];
                for (int j = 0; j < list.Count; j++)
                {
                    int item = list[j] + dd;
                    if (item > V)
                        continue;
                    hs.Add(item);
                }
                count++;

            }



            return count.ToString();
        }
    }
}
﻿

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