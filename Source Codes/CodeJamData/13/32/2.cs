

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
    using System.Text;

    public class ProblemB : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int X = input.GetInt();
            int Y = input.GetInt();

           
            int sum = Math.Abs(X) + Math.Abs(Y);

            int n = 1;
            int nsum = 0;
            while( true)
            {
                nsum += n;

                if (nsum % 2 == sum % 2)
                    if (nsum >= sum)
                        break;

                n++;
            }

            StringBuilder sb = new StringBuilder();

            for (int i = n; i > 0; i--)
            {
                if( Math.Abs(X) >= Math.Abs(Y))
                {
                    if( X < 0)
                    {
                        sb.Append('W');
                        X += i;
                    }
                    else
                    {
                        sb.Append('E');
                        X -= i;
                    }
                }
                else
                {
                    if ( Y < 0)
                    {
                        sb.Append('S');
                        Y += i;
                    }
                    else
                    {
                        sb.Append('N');
                        Y -= i;
                    }
                }

                //Console.WriteLine((String.Format("X={0} Y={1}", X, Y)));
            }

            if( X != 0 && Y !=0 )
                throw new Exception(String.Format("X={0} Y={1}", X, Y));

            var s = sb.ToString();
            var car = s.ToCharArray();
            Array.Reverse(car);

            return new string(car);
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