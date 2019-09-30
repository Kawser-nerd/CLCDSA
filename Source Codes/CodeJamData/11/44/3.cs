using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace AIWar
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = String.Empty;
            var outFile = String.Empty;

            for (var i = 0; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "-i":
                        inFile = args[++i];
                        break;
                    case "-o":
                        outFile = args[++i];
                        break;
                }
            }

            if (!String.IsNullOrEmpty(inFile) && !String.IsNullOrEmpty(outFile))
            {
                using (var reader = new StreamReader(inFile))
                using (var writer = new StreamWriter(outFile))
                {
                    var p = new Program();
                    p.Run(reader, writer);
                }
            }
        }

        private void Run(TextReader reader, TextWriter writer)
        {
            var stopwatch = System.Diagnostics.Stopwatch.StartNew();

            var caseCount = int.Parse(reader.ReadLine());
            for (var i = 1; i <= caseCount; i++)
            {
                var answer = RunCase(reader);
                writer.WriteLine("Case #{0}: {1} {2}", i, answer[0], answer[1]);
            }

            stopwatch.Stop();
            Console.WriteLine("{0:#,###}ms", stopwatch.ElapsedMilliseconds);
        }

        private int[] distanceTo1;
        private bool[][] connectoins;
        private int P;
        private int[] RunCase(TextReader reader)
        {
            var values = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            P = values[0];

            connectoins = new bool[P][];
            distanceTo1 = new int[P];
            for (var i = 0; i < P; i++)
            {
                connectoins[i] = new bool[P];
                distanceTo1[i] = -1;
            }

            foreach (var tuple in reader.ReadLine().Split(' '))
            {
                var planets = tuple.Split(',').Select(s => int.Parse(s)).ToArray();
                connectoins[planets[0]][planets[1]] = true;
                connectoins[planets[1]][planets[0]] = true;
            }

            distanceTo1[1] = 0;
            BreathFirstSearch();
            //distanceTo1[1] = 0;
            //BreathFirstSearch(1, 0);

            var paths = CollectPaths(0, distanceTo1[0]);

            int max = int.MinValue;
            foreach (var path in paths)
            {
                var threaten = new HashSet<int>();
                foreach (var p in path)
                {
                    for (var i = 0; i < P; i++)
                    {
                        if (connectoins[p][i])
                            threaten.Add(i);
                    }
                }
                var score = threaten.Except(path).Count();
                if (score > max) max = score;
            }

            return new[] { distanceTo1[0] - 1, max };
        }

        private void BreathFirstSearch()
        {
            var distance = 0;
            while (distanceTo1[0] == -1)
            {
                var newDistance = distance + 1;
                for (var p = 0; p < P; p++)
                {
                    if (distanceTo1[p] == distance)
                    {
                        for (var i = 0; i < P; i++)
                        {
                            if (connectoins[p][i] && distanceTo1[i] == -1)
                            {
                                distanceTo1[i] = newDistance;
                                if (i == 0) return;
                            }
                        }
                    }
                }
                distance = newDistance;
            }
        }

        private List<ICollection<int>> CollectPaths(int p, int distance)
        {
            if (p == 1)
            {
                var path = new HashSet<int>();
                return new List<ICollection<int>>(new[] { path });
            }

            var paths = new List<ICollection<int>>();
            for (var i = 0; i < P; i++)
            {
                if (connectoins[i][p] && distanceTo1[i] == distance - 1)
                {
                    var temp = CollectPaths(i, distance - 1);
                    foreach (var path in temp)
                    {
                        path.Add(p);
                    }
                    paths.AddRange(temp);
                }
            }
            return paths;
        }

        private void BreathFirstSearch(int p, int distance)
        {
            if (distanceTo1[0] != -1)
                return;

            List<int> toVisit = new List<int>();
            var newDistance = distance + 1;

            for (var i = 0; i < P; i++)
            {
                if (distanceTo1[i] == -1 && connectoins[i][p])
                {
                    distanceTo1[i] = newDistance;
                    toVisit.Add(i);
                }
            }
            foreach (var i in toVisit)
            {
                BreathFirstSearch(i, newDistance);
            }
        }
    }
}
