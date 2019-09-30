

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
    using System.Linq;

    public class ProblemB : IProblem
    {
        private List<List<int>> E;
        private List<Dictionary<int, int>> trees;
        private List<Dictionary<int, int>> deletes;

        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();

            E = new List<List<int>>();
            for (int i = 0; i < N+1; i++)
            {
                E.Add(new List<int>());
            }

            for (int i = 0; i < N-1; i++)
            {
                var a = input.GetInt();
                var b = input.GetInt();

                E[a].Add(b);
                E[b].Add(a);
            }

            int best = int.MaxValue;
            int node = -1;

            deletes = new List<Dictionary<int, int>>();
            trees = new List<Dictionary<int, int>>();

            for (int i = 0; i < N+1; i++)
            {
                deletes.Add(new Dictionary<int, int>());
                trees.Add(new Dictionary<int, int>());
            }

            for (int i = 1; i <= N; i++)
            {
                int b = tree(-1, i);

                if( b < best)
                {
                    best = b;
                    node = i;
                }
            }

            //Console.WriteLine(node);
            return best.ToString();
        }

        private int tree(int p, int node)
        {
            if( trees[node].ContainsKey(p))
                return trees[node][p];

            var v = treeInt(p, node);
            trees[node].Add(p, v);
            return v;
        }

        private int treeInt(int p, int node)
        {
            var childs = E[node].Where(x => x != p).ToList();
            var cc = childs.Count;

            if (cc == 0)
                return 0;

            if (cc == 1)
                return delete(node, childs.Single());

            if (cc == 2)
                return tree(node, childs[0]) + tree(node, childs[1]);

            int[] tt = new int[cc];
            int[] dd = new int[cc];

            for (int i = 0; i < cc; i++)
            {
                tt[i] = tree(node, childs[i]);
                dd[i] = delete(node, childs[i]);
            }

            int best = int.MaxValue;
            var del = dd.Sum();

            for (int i = 0; i < cc; i++)
            {
                for (int j = 0; j < cc; j++)
                {
                    if( i== j)
                        continue;

                    var val = del - dd[i] - dd[j] + tt[i] + tt[j];

                    if (val < best)
                        best = val;
                }
            }

            return best;
        }

        private int delete(int p, int node)
        {
            if (deletes[node].ContainsKey(p))
                return deletes[node][p];

            var v = deleteInt(p, node);
            deletes[node].Add(p, v);
            return v;
        }

        private int deleteInt(int p, int node)
        {
            int val = 1;

            for (int i = 0; i < E[node].Count; i++)
            {
                int nn = E[node][i];
                if( nn == p)
                    continue;

                val += delete(node, nn);
            }

            return val;
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