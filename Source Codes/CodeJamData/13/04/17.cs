using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class Treasure
    {
        private Chest[] _chests;
        private HashSet<string> _visited;

        static void Main(string[] args)
        {
            new Treasure().Solve();
        }

        void Solve()
        {
            using (var sc = new StreamReader("D-small-attempt0.in"))
            using (var sout = new StreamWriter("D-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    string ans = "";

                    int nk = sc.Next<int>();
                    int no = sc.Next<int>();
                    //sc.ReadLine();
                    var ownKey = sc.NextList<int>();
                    _chests = new Chest[no];
                    _visited = new HashSet<string>();

                    for (int i = 0; i < no; i++)
                    {
                        _chests[i] = new Chest(sc.Next<int>(), sc.NextList<int>());
                    }

                    var keys = _chests.SelectMany(c => c.Keys.Keys)
                        .Concat(_chests.Select(c => c.Required))
                        .Concat(ownKey)
                        .Distinct().ToDictionary(i => i, i => 0);
                    foreach (var key in ownKey)
                    {
                        keys[key]++;
                    }

                    var ret = Recurse("", keys);
                    Console.WriteLine(_visited.Count);
                    if (ret == null) ans = "IMPOSSIBLE";
                    else ans = Print(ret);
                    Debug.Assert(ret == null || ret.Length == _chests.Length);
                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private string Print(string ret)
        {
            return string.Join(" ", ret.Select(c => c - 'a' +1));
        }

        private string Recurse(string opened, Dictionary<int, int> keys)
        {
            string signature = Sign(opened);
            if (_visited.Contains(signature)) return null;
            //Console.WriteLine(signature);
            _visited.Add(signature);
            if (opened.Length == _chests.Length) return opened;
            for(int i=0; i<_chests.Length; i++)
            {
                if (opened.Contains(C(i)) || keys[_chests[i].Required] == 0) continue;
                keys[_chests[i].Required]--;
                foreach (var newKey in _chests[i].Keys.Keys)
                    keys[newKey] += _chests[i].Keys[newKey];
                var rec = Recurse(opened + C(i), keys);
                if(rec!= null) return rec;
                keys[_chests[i].Required]++;
                foreach (var newKey in _chests[i].Keys.Keys)
                    keys[newKey] -= _chests[i].Keys[newKey];
            }
            return null;
        }

        private string Sign(string opened)
        {
            return new string(opened.OrderBy(c => c).ToArray());
        }

        private char C(int i)
        {
            return (char)('a' + i);
        }
    }

    internal class Chest
    {
        public int Required { get; set; }
        public Dictionary<int, int> Keys { get; set; }

        public Chest(int required, List<int> keys)
        {
            Required = required;
            var skip = keys.Skip(1).ToArray();
            Keys = skip.Distinct().ToDictionary(i => i, i => skip.Count(j => i == j));

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
