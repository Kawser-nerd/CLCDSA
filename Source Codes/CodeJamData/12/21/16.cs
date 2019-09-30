using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class MinimumAudienceVoteCalculator
    {
        static void Main(string[] args)
        {
            new MinimumAudienceVoteCalculator().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("A-large.in"))
            using (StreamWriter sout = new StreamWriter("A-large.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    String ans ="";
                    int contestant = sc.Next<int>();
                    var judgeScores = sc.NextList<int>();
                    for (int i = 0; i < contestant; i++)
                    {
                        ans += " " + CalculateMinimumVote(i, judgeScores);
                    }
                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private string CalculateMinimumVote(int candidate, List<int> judgeScores)
        {
            double topLimit = 100;
            double bottomLimit = 0;
            double candidateScore = (topLimit + bottomLimit) * 0.5;
            while (Math.Abs(topLimit - bottomLimit) > 0.000001)
            {
                //Console.WriteLine(topLimit + " " + bottomLimit);
                if (CalculateSafety(candidateScore, candidate, judgeScores) < 0) bottomLimit = candidateScore;
                else topLimit = candidateScore;
                candidateScore = (topLimit + bottomLimit) * 0.5;
            }
            return candidateScore.ToString("0.000000");
        }

        private int CalculateSafety(double candidateScore, int candidate, List<int> judgeScores)
        {
            bool isSafe = IsSafe(candidateScore, candidate, judgeScores);
            //bool isMinimum = !IsSafe(candidateScore - 0.000005, candidate, judgeScores);
            if (!isSafe) return -1;
            //if (!isMinimum) return 1;
            return 1;
        }

        private bool IsSafe(double candidateScore, int candidate, List<int> judgeScores)
        {
            double total = judgeScores.Sum();
            var scores = judgeScores.Select(i => (double)i * 100.0 / total).ToList();
            var myScore = scores.ElementAt(candidate)+candidateScore;
            scores.RemoveAt(candidate);
            var sortedScores = scores.OrderBy(x => x);

            double remaining = 100.0 - candidateScore;
            foreach (double score in sortedScores)
            {
                if (myScore > score)
                {
                    remaining -= (myScore - score);
                    if (remaining < 0) return true;
                }
                else return false;

            }
            return false;

            
        }

    }

    public static class Extensions
    {
        public static string Next(this StreamReader sr)
        {
            if (sr.EndOfStream) return null;
            StringBuilder sb = new StringBuilder();
            char ch;
            while (!Char.IsWhiteSpace(ch = (char)sr.Read()))
            {
                sb.Append(ch);
            }
            if (sb.Length == 0) return sr.Next();
            return sb.ToString();
        }

        public static T Next<T>(this StreamReader sr) where T : IConvertible
        {
            string s = sr.Next();
            if (s == null) throw new EndOfStreamException();
            return (T)Convert.ChangeType(s, typeof(T));
        }

        public static string[] nextStrings(this StreamReader sr)
        {
            return sr.ReadLine().Split();
        }

        public static List<T> NextList<T>(this StreamReader sr) where T : IConvertible
        {
            string[] st = sr.ReadLine().Split();
            List<T> ret = new List<T>();
            foreach (string s in st)
                ret.Add((T)Convert.ChangeType(s, typeof(T)));
            return ret;
        }
    }
}
