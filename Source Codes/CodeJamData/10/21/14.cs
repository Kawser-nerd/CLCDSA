using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    class Node
    {
        public Dictionary<string, Node> comp = new Dictionary<string, Node>();

        public int add(string[] str, int next)
        {
            if (next == str.Length)
                return 0;

            if (comp.ContainsKey(str[next]))
                return comp[str[next]].add(str, next + 1);
            else
            {
                comp.Add(str[next], new Node());
                return comp[str[next]].add(str, next + 1) + 1;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            FileStream fin = File.OpenRead(@"C:\input.txt");
            FileStream fout = File.OpenWrite(@"C:\output.txt");

            TextReader r = new StreamReader(fin);
            TextWriter w = new StreamWriter(fout);

            Node root = new Node();

            int t = int.Parse(r.ReadLine().Trim());

            for (int i = 1; i <= t; ++i)
            {
                string line = r.ReadLine();
                string[] comp = line.Split();
                int n = int.Parse(comp[0]);
                int m = int.Parse(comp[1]);
                root.comp.Clear();

                while ((n--) > 0)
                {
                    line = r.ReadLine();
                    root.add(line.Split(new char[] { '/' }, StringSplitOptions.RemoveEmptyEntries), 0);
                }

                int cnt = 0;

                while ((m--) > 0)
                {
                    line = r.ReadLine();
                    cnt += root.add(line.Split(new char[] { '/' }, StringSplitOptions.RemoveEmptyEntries), 0);
                }

                w.WriteLine("Case #{0}: {1}", i, cnt);
                w.Flush();
            }

            w.Close();
        }
    }
}
