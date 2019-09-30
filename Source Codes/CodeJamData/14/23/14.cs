using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace The_Bored_Traveling_Salesman
{
    internal class Program
    {
        private static void Main(string[] args)
        {
           //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt0.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int N = int.Parse(ss[0]);
            int M = int.Parse(ss[1]);

            var ports = new List<port>();
            for (int i = 0; i < N; i++)
            {
                ports.Add(new port(i + 1, reader.ReadLine()));
            }
            for (int i = 0; i < M; i++)
            {
                ss = reader.ReadLine().Split(' ');
                int from = int.Parse(ss[0]);
                int to = int.Parse(ss[1]);

                ports[from - 1].to.Add(ports[to - 1]);
                ports[to - 1].to.Add(ports[from - 1]);
            }
            for (int i = 0; i < N; i++)
            {
                ports[i].to.Sort(new port(1, ""));
            }

            ports.Sort(new port(1, ""));
            for (int i = 0; i < ports.Count; i++)
            {
                ports[i].index = i + 1;
            }

            var visit = new List<port>();
            visit.Add(ports[0]);

            List<List<port>> v = find(visit);

            var sss = new List<string>();
            foreach (var list in v)
            {
                if (list.Count == ports.Count)
                {
                    var b = new StringBuilder();
                    foreach (port port in list)
                    {
                        b.Append(port.index);
                    }
                    sss.Add(b.ToString());
                }
            }

            var time = new StringBuilder();
            sss.Sort();
            foreach (string str in sss)
            {
                if (str.Length == ports.Count)
                {
                    for (int i = 0; i < str.Length; i++)
                    {
                        foreach (port port in ports)
                        {
                            if (port.index.ToString()[0] == str[i])
                            {
                                time.Append(port.name);
                                break;
                            }
                        }
                    }
                    break;
                }
            }

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }

        private static List<List<port>> find(List<port> visit)
        {
            port p = visit[visit.Count - 1];
            var visits = new List<List<port>>();
            visits.Add(visit);

            foreach (port port in p.to)
            {
                var toadd = new List<List<port>>();
                foreach (var visit1 in visits)
                {
                    if (!visit1.Contains(port))
                    {
                        List<port> vv = new List<port>(visit1);
                        vv.Add(port);
                        List<List<port>> v = find(vv);
                        foreach (List<port> ports in v)
                        {
                            toadd.Add(new List<port>(ports));
                        }
                        
                    }
                }

                visits.AddRange(toadd);
            }
            return visits;
        }

        #region Nested type: port

        private class port : IComparer<port>
        {
            public readonly string name;
            public readonly List<port> to;
            public int index;

            public port(int index, string name)
            {
                this.index = index;
                this.name = name;
                to = new List<port>();
            }

            #region IComparer<port> Members

            public int Compare(port x, port y)
            {
                return x.name.CompareTo(y.name);
            }

            #endregion
        }

        #endregion
    }
}