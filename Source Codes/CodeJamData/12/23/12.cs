using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class EqualSumSubsetFinder
    {
        static void Main(string[] args)
        {
            new EqualSumSubsetFinder().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("C-small-attempt0.in"))
            using (StreamWriter sout = new StreamWriter("C-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    string ans = "";
                    sc.Next<int>();
                    IList<int> set = (sc.NextList<int>());
                    ans = FormatAsAnswer(GetEqualSubsets(set));
                    sout.WriteLine("Case #" + (zz) + ":\n" + ans);
                }
            }
        }

        private string FormatAsAnswer(List<String> list)
        {
            return list.First().Trim() + "\n" + list.Last().Trim();
        }

        private List<String> GetEqualSubsets(IList<int> set)
        {
            Dictionary<int, int> hash = new Dictionary<int,int>();
            List<string> equalSubsets = new List<string>();
            for (int i = 0; i < (1 << set.Count); i++)
            {
                
                int sum = 0;
                for (int j = 0; j < set.Count; j++)
                {
                    if ((i & (1<<j)) > 0) sum += set.ElementAt(j);
                }
                if (hash.ContainsKey(sum))
                {

                    equalSubsets.Add(GetSet(hash[sum], set));
                    equalSubsets.Add(GetSet(i, set));
                    return equalSubsets;
                }
                else
                {
                    hash.Add(sum, i);
                }
                //Console.WriteLine(i +" " + sum);
            }
            return equalSubsets;
        }

        private string GetSet(int i, IList<int> set)
        {
            string returnString = "";
            for (int j = 0; j < set.Count; j++)
            {
                if ((i & (1 << j)) > 0) returnString += " " + set.ElementAt(j);
            }
            return returnString;
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
