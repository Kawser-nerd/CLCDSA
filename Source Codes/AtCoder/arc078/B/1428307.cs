using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace ConsoleApplication1.CodeForces
{
    class _4032
    {
        private static int Next()
        {
            int c;
            int res = 0;
            do
            {
                c = reader.Read();
                if (c == -1)
                    return res;
            } while (c < '0' || c > '9');
            res = c - '0';
            while (true)
            {
                c = reader.Read();
                if (c < '0' || c > '9')
                    return res;
                res *= 10;
                res += c - '0';
            }
        }
        private static readonly StreamReader reader = new StreamReader(Console.OpenStandardInput(1024 * 10), Encoding.ASCII, false, 1024 * 10);
        private static readonly StreamWriter writer = new StreamWriter(Console.OpenStandardOutput(1024 * 10), Encoding.ASCII, 1024 * 10);

        class Node
        {
            public int Current { get; set; }
        }
        public static string ReverseString(string s)
        {
            char[] arr = s.ToCharArray();
            Array.Reverse(arr);
            return new string(arr);
        }
        static void Main(String[] args)
        {
            var n = int.Parse(Console.ReadLine().TrimEnd());
            var edges = new List<int>[n];
            for (var i = 0; i < n; i++)
            {
                edges[i] = new List<int>();
            }
            for (var i = 0; i < n - 1; i++)
            {
                var data = Console.ReadLine().TrimEnd().Split(' ').Select(a => int.Parse(a) - 1).ToList();
                edges[data[0]].Add(data[1]);
                edges[data[1]].Add(data[0]);
            }

            var que = new Queue<Node>();
            que.Enqueue(new Node()
            {
                Current = 0
            });

            var visited = new bool[n];
            visited[0] = true;
            var prev = new int[n];
            prev[0] = 0;
            
            var path = new List<int>();

            while (que.Count > 0)
            {
                var cur = que.Dequeue();
                if (cur.Current == n - 1)
                {
                    var prevInd = cur.Current;
                    while (prev[prevInd] != 0)
                    {
                        path.Add(prev[prevInd]);
                        prevInd = prev[prevInd];
                    }
                    break;
                }
                for (var i = 0; i < edges[cur.Current].Count; i++)
                {
                    var ind = edges[cur.Current][i];

                    if (!visited[ind])
                    {
                        visited[ind] = true;
                        prev[ind] = cur.Current;
                        que.Enqueue(new Node()
                        {
                            Current = ind
                        });
                    }
                }
            }

            visited = new bool[n];
            var queu1 = new Queue<int>();
            var queu2 = new Queue<int>();
            queu1.Enqueue(0);
            queu2.Enqueue(n - 1);
            visited[0] = true;
            visited[n - 1] = true;
            if (path.Count > 0)
            {
                var l = path.Count - 1;
                var s = 0;
                while (s < l)
                {
                    queu1.Enqueue(path[l]);
                    queu2.Enqueue(path[s]);
                    visited[path[l]] = true;
                    visited[path[s]] = true;
                    s++; l--;
                }
                if (path.Count % 2 == 1)
                {
                    queu1.Enqueue(path[path.Count/ 2]);
                    visited[path[path.Count / 2]] = true;
                }
            }
            while(queu1.Count > 0 && queu2.Count > 0)
            {
                var cur1 = queu1.Dequeue();
                for (var i = 0; i < edges[cur1].Count; i++)
                {
                    var ind = edges[cur1][i];

                    if (!visited[ind])
                    {
                        visited[ind] = true;
                        queu1.Enqueue(ind);
                    }
                }

                var cur2 = queu2.Dequeue();
                for (var i = 0; i < edges[cur2].Count; i++)
                {
                    var ind = edges[cur2][i];

                    if (!visited[ind])
                    {
                        visited[ind] = true;
                        queu2.Enqueue(ind);
                    }
                }
            }

            if (queu1.Count == 0)
            {
                Console.WriteLine("Snuke");
                
            }
            else
            {
                Console.WriteLine("Fennec");
            }
        }
    }
}