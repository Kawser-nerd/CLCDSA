

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
        public string SolveOneCase(InputParser input)
        {
            var str = input.ReadLine();
            var split = str.Split(new char[]{'/'});

            var p = long.Parse(split[0]);
            var q = long.Parse(split[1]);

            var gcd = GCD_Calc.GCD(p, q);

            var p1 = p/gcd;
            var q1 = q/gcd;

            if (q1 % 2 != 0)
                return "impossible";

            var qt = q1;
            while(qt > 1)
            {
                if (qt % 2 != 0)
                    return "impossible";
                qt /= 2;
            }




            int c = 0;
            while (q1 > p1)
            {
                q1 = q1/2;

                c++;
            }
//            if (p1 != 1)
//                return "impossible";

//            if (firstP != -1)
//                return firstP.ToString();

            return c.ToString();
        }
    }

    public static class GCD_Calc
    {
        public static long GCD(long a, long b)
        {
            while (b != 0)
            {
                long t = b;
                b = a % b;
                a = t;
            }

            return a;
        }

//        public static int LCM(int a, int b)
//        {
//            return a / GCD(a, b) * b;
//        }
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