using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class YourEnergy
    {
        private int _r;
        private List<int> _list;
        private Dictionary<string, int> _dict;
        private int _max;

        static void Main(string[] args)
        {
            new YourEnergy().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("B-small-attempt0.in"))
            using (StreamWriter sout = new StreamWriter("B-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    int ans = 0;
                    int e = sc.Next<int>();
                    _max = e;
                    _r = sc.Next<int>();
                    int n = sc.Next<int>();
                    //sc.ReadLine();
                    _list = sc.NextList<int>();
                    _dict = new Dictionary<string, int>();

                    ans = Recurse(e, 0);
                    
                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private int Recurse(int e, int pos)
        {
            if(pos == _list.Count) return 0;
            string signature = Sign(e, pos);
            if (!_dict.ContainsKey(signature))
            {
                int max = 0;
                for(int i=0; i<=e; i++)
                {
                    int trie = i*_list[pos];
                    int eA = Math.Min(_max, e - i + _r);
                    int ans = trie + Recurse(eA, pos + 1);
                    max = Math.Max(max, ans);
                }
                _dict[signature] = max;
            }
            return _dict[signature];


        }

        private string Sign(int i, int pos)
        {
            char c1 = (char)('0' + i);
            char c2 = (char)('0' + pos);
            return new string(new[] {c1, c2});
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
