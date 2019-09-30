using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class GoodLuck
    {
        private Dictionary<string, int> _score;
        private int _numbers;
        private int _max;
        private List<int> _products;
        private Dictionary<string, int> _times;
        private int _productCount;
        private HashSet<int> _pSoFar;

        static void Main(string[] args)
        {
            new GoodLuck().Solve();
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

                    int cases = sc.Next<int>();
                    _numbers = sc.Next<int>();
                    _max = sc.Next<int>();

                    
                    _productCount = sc.Next<int>();
                    for(int i =0; i< cases; i++)
                    {
                        _products = sc.NextList<int>();
                        _score = new Dictionary<string, int>();
                        _times = new Dictionary<string, int>();
                        Recurse("");
                        int max = _times.Keys.Max(c => _times[c] * _score[c]);
                        string candidate = _times.Keys.First(c => _times[c] * _score[c] == max);
                        ans += Environment.NewLine + candidate;
                    }
                    
                    

                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private void Recurse(string st)
        {
            
            if (st.Length == _numbers){
                Evaluate(st);
                return;
            }
            for(int i=2; i<=_max; i++)
            {
                char c = (char) ('0' + i);
                Recurse(st +c);
            }
        }

        private void Evaluate(string st)
        {
            string signature = Sign(st);
            if (_times.ContainsKey(signature)) _times[signature]++;
            else
            {
                _score[signature] = Score(signature);
                _times[signature] = 1;
            }
        }

        private int Score(string signature)
        {
            int[] integers = signature.Select(c => (int)(c - '0')).ToArray();
            _pSoFar = new HashSet<int>();
            Recurse2(integers, 1, 0);
            if (_products.All(p => _pSoFar.Contains(p))) return 1;
            else return 0;

        }

        private void Recurse2(int[] integers, int p, int c)
        {
            if (c == integers.Length) _pSoFar.Add(p);
            else
            {
                Recurse2(integers, p, c+1);
                Recurse2(integers, p* integers[c], c+1);
            }
        }

        private string Sign(string st)
        {
            return new string(st.OrderBy(c => c).ToArray());
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
