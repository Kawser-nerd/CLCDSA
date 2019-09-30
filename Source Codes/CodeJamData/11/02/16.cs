using System;
using System.Linq;
using System.Collections.Generic;
using CodeJam;

namespace Problems
{
    public class Magicka
    {
        class Transmute
        {
            public char Element1;
            public char Element2;
            public char Result;

            public bool IsApplicable(char last, char current) {return (Element1 == last && Element2 == current) || (Element2 == last && Element1 == current);}
        }

        class OpposingPair
        {
            public char Element1;
            public char Element2;

            public bool IsApplicable(char last, char current) { return (Element1 == last && Element2 == current) || (Element2 == last && Element1 == current); }
        }

        public static void Main(string[] args)
        {
            ProblemParser.ParseProblem(@"D:\Chrome\Downloads\B-large.in");
            for (var problem = 0; problem < ProblemParser.Cases; problem++) 
            {
                var input = ProblemParser.GetNextLine().Split(' ');
                var offset = 0;
                var c = Int32.Parse(input[offset++]);
                var transmutes = new List<Transmute>();
                for (int i = 0; i < c; i++, offset++) transmutes.Add(new Transmute { Element1 = input[offset][0], Element2 = input[offset][1], Result = input[offset][2] });

                var d = Int32.Parse(input[offset++]);
                var opposingPairs = new List<OpposingPair>();
                for (int i = 0; i < d; i++, offset++) opposingPairs.Add(new OpposingPair { Element1 = input[offset][0], Element2 = input[offset][1] });

                var toTransmute = input[offset+1];
                ProblemParser.WriteSolution("[" + string.Join(", ", ApplyTransmutation(toTransmute, transmutes, opposingPairs).ToCharArray()) + "]");
            }
        }

        private static string ApplyTransmutation(string input, List<Transmute> transmutes, List<OpposingPair> opposingPairs)
        {
            var left = new List<char>();
            for(int i = 0; i < input.Length; i++)
            {
                var current = input[i];
                if(left.Count != 0)
                {
                    var last = left.Last();
                    var transmute = transmutes.Find(t => t.IsApplicable(last, current));
                    if(transmute != null)
                    {
                        left.RemoveAt(left.Count - 1);
                        return ApplyTransmutation(new string(left.ToArray()) + transmute.Result + input.Substring(i + 1), transmutes, opposingPairs);
                    }

                    if (left.Select(previous => opposingPairs.Find(o => o.IsApplicable(previous, current))).Any(opposingPair => opposingPair != null))
                    {
                        left.Clear();
                        return ApplyTransmutation(new string(left.ToArray()) + input.Substring(i + 1), transmutes, opposingPairs);
                    }
                }
                left.Add(current);
            }
            return new string(left.ToArray());
        }
    }
}
