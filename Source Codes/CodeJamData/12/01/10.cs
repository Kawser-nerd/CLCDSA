using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleJam
{  
    public class Mapping
    {
        readonly Dictionary<char, char> _mapping = new Dictionary<char, char>(); 

        public Mapping()
        {
            Register("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            Register("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            Register("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            Register("qz", "zq");
        }

        public void Register(string googlese, string origin)
        {
            Debug.Assert(googlese.Length == origin.Length);
            for (int i = 0; i < googlese.Length; i++)
                AddMapping(googlese[i], origin[i]);
        }

        private void AddMapping(char c, char corig)
        {
            if (_mapping.ContainsKey(c))
                Debug.Assert(corig == _mapping[c]);
            else
            {
                _mapping.Add(c, corig);
            }
        }

        public void PrintUnmapped()
        {
            var unmapped = Enumerable.Range('a', 'z' - 'a' + 1).Select(c => (char)c).Where(c => !_mapping.ContainsKey(c));
            var unmappedValues = Enumerable.Range('a', 'z' - 'a' + 1).Select(c => (char)c).Where(c => !_mapping.ContainsValue(c));
        }

        public string Map(string googlese)
        {
            var sb = new StringBuilder(googlese.Length);
            foreach (var g in googlese)
            {
                sb.Append(_mapping[g]);
            }
            return sb.ToString();
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            var m = new Mapping();

            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    var line = tr.ReadLine();
                    tw.WriteLine(string.Format("Case #{0}: {1}", i+1, m.Map(line)));
                }
            }
        }
    }
}
