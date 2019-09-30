namespace ConsoleApplication1
{
    using System.Collections;
    using System.Collections.Generic;
    using System.IO;

    class IO
    {
        StreamReader sr; StreamWriter sw; IEnumerator e = new string[0].GetEnumerator();
        public IO(string name) { sr = File.OpenText(name + ".in"); sw = File.CreateText(name + ".out"); sw.AutoFlush = true; }
        public void Write(string s) { sw.Write(s); }
        public void WriteLine(string s) { sw.WriteLine(s); }
        public string ReadLine() { return sr.ReadLine(); }
        public string GetNext() { if (!e.MoveNext()) (e = this.ReadLine().Split(new char[] { ' ' }).GetEnumerator()).MoveNext(); return (string)e.Current; }
    }

    class Node
    {
        public double w;
        public string feat;
        public Node l, r;
    }

    class Program
    {
        static int p = 0;

        static Node ReadNode(string[] tokens)
        {
            p++;
            Node node = new Node();
            node.w = double.Parse(tokens[p++]);

            if (tokens[p] != ")")
            {
                node.feat = tokens[p++];
                node.l = ReadNode(tokens);
                node.r = ReadNode(tokens);
            }
            p++;

            return node;
        }

        static void Main(string[] args)
        {
            IO io = new IO("A-large");

            int T = int.Parse(io.GetNext());

            for (int t = 1; t <= T; t++)
            {
                int L = int.Parse(io.GetNext());
                string s = "";

                for (int l = 0; l < L; l++)
                    s += io.ReadLine();
                s = s.Replace("(", " ( ");
                s = s.Replace(")", " ) ");
                string[] tokens = s.Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);

                p = 0;
                Node root = ReadNode(tokens);

                io.WriteLine("Case #" + t + ":");

                int A = int.Parse(io.GetNext());

                for (int a = 0; a < A; a++)
                {
                    io.GetNext();
                    int n = int.Parse(io.GetNext());
                    HashSet<string> set = new HashSet<string>();

                    for (int i = 0; i < n; i++)
                        set.Add(io.GetNext());

                    double P = 1.0;
                    Node node = root;

                    while (true)
                    {
                        P *= node.w;
                        if (string.IsNullOrEmpty(node.feat)) break;
                        node = set.Contains(node.feat) ? node.l : node.r;
                    }

                    io.WriteLine(string.Format("{0:F7}", P));
                }
            }
        }
    }
}
