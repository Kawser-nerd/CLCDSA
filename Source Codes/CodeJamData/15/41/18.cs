

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
    public class ProblemA : IProblem
    {
        private string IMP = "IMPOSSIBLE";
        private int R;
        private int C;
        private string[] str;
        private int count;
        public string SolveOneCase(InputParser input)
        {
            R = input.GetInt();
            C = input.GetInt();

            str = new string[R];
            for (int i = 0; i < R; i++)
            {
                str[i] = input.GetString();
            }
            count = 0;

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    var c = str[i][j];
                    bool t = navigate(i, j, true, c);
                    if( !t)
                    {
                        if( c!= '<')
                        {
                            var x = navigate(i, j, true, '<');
                            if(x)
                            {
                                count++;
                                continue;
                            }
                        }
                        if (c != '^')
                        {
                            var x = navigate(i, j, true, '^');
                            if (x)
                            {
                                count++;
                                continue;
                            }
                        }
                        if (c != '>')
                        {
                            var x = navigate(i, j, true, '>');
                            if (x)
                            {
                                count++;
                                continue;
                            }
                        }
                        if (c != 'v')
                        {
                            var x = navigate(i, j, true, 'v');
                            if (x)
                            {
                                count++;
                                continue;
                            }
                        }
                        return IMP;
                    }



                }
            }


            return count.ToString();
        }

        bool navigate(int i, int j, bool first, char c)
        {
            if (c == '.')
                return true;

            if (i < 0 || i >= R)
                return false;
            if (j < 0 || j >= C)
                return false;

            if( !first )
            {
                if (str[i][j] != '.')
                    return true;
            }

            switch (c)
            {
                case '<':
                    j -= 1;
                    break;
                case '^':
                    i -= 1;
                    break;
                case '>':
                    j += 1;
                    break;
                case 'v':
                    i += 1;
                    break;
            }


            return navigate(i, j, false, c);
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