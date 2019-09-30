using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "FullBinaryTree";
        static string _dataSize = "L";   // T, S or L q

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".in");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + ".out"))
            {
                Action<string> dualWriter = line =>
                {
                    Console.WriteLine(line);
                    outFile.WriteLine(line);
                };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
        }



        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                // parse data here
                int ct = int.Parse(lines[at++]);

                List<List<int>> data = new List<List<int>>();

                for (int i = 0; i < ct - 1; i++)
                {
                    data.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToList());
                }

                string answer = solve1(ct, data);
                writeLine(string.Format("Case #{0}: {1}", q + 1, answer));
            }
        }

        static string solve1(int n, List<List<int>> data)
        {
            List<List<int>> graph = Enumerable.Repeat(1, n).Select(x => new List<int>()).ToList();

            foreach (var set in data)
            {
                graph[set[0] - 1].Add(set[1] - 1);
                graph[set[1] - 1].Add(set[0] - 1);
            }

            int min = int.MaxValue;

            for (int i = 0; i < n; i++)
            {
                var anal = count(i, -1, graph);
                if (anal.IsBinary)
                {
                    min = 0;
                    break;
                }
                else
                {
                    min = Math.Min(min, anal.ToFix);
                }
            }

            return min.ToString();
        }

        class Anal
        {
            public bool IsBinary { get; set; }
            public int Total { get; set; }
            public int ToFix { get; set; }
        }

        static Anal count(int at, int from, List<List<int>> graph)
        {
            var anal = new Anal();

            List<int> to = graph[at].Where(a => a != from).ToList();

            if (to.Count == 0)
            {
                anal.IsBinary = true;
                anal.Total = 1;
                anal.ToFix = 0;
            }
            else if (to.Count == 1)
            {
                var temp = count(to[0], at, graph);

                anal.IsBinary = false;
                anal.ToFix = temp.Total;
                anal.Total = 1 + temp.Total;
            }
            else if (to.Count == 2)
            {
                var temp1 = count(to[0], at, graph);
                var temp2 = count(to[1], at, graph);

                anal.IsBinary = temp1.IsBinary && temp2.IsBinary;
                anal.Total = 1 + temp1.Total + temp2.Total;
                anal.ToFix = temp1.ToFix + temp2.ToFix;
            }
            else
            {
                var temps = to.Select(t => count(t, at, graph)).ToList();
                temps.Sort((t1, t2) =>
                {
                    var d1 = t1.Total - t1.ToFix;
                    var d2 = t2.Total - t2.ToFix;

                    if (d1 < d2) return 1;
                    if (d1 == d2) return 0;
                    else return -1;
                });

                anal.IsBinary = false;
                anal.Total = 1 + temps.Aggregate(0, (acum, t) => acum + t.Total);
                anal.ToFix = temps[0].ToFix + temps[1].ToFix + temps.Skip(2).Aggregate(0, (acum, t) => acum + t.Total);
            }
            
            return anal;

        }
    }
}


// lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => double.Parse(s)).ToList();