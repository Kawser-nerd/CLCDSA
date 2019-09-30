using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:/CodeJam/1a/Problem3/C-small-attempt0 (1).in"))
            {
                using (var writer = new StreamWriter("C:/CodeJam/1a/Problem3/output.txt"))
                {
                    var numTC = int.Parse(reader.ReadLine());
                    for (var tc = 1; tc <= numTC; tc++)
                    {
                        Console.Write("Case #{0}: ", tc);
                        writer.Write("Case #{0}: ", tc);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();

        }

        static List<Tuple<List<int>, HashSet<int>>> forests;

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var N = int.Parse(reader.ReadLine());
            var Kids = reader.ReadLine().Split(' ').Select(int.Parse).Select(a => a - 1).ToArray();
            forests = new List<Tuple<List<int>, HashSet<int>>>();
            var bestCyclical = 0;
            for(int i = 0; i < N; i++)
            {
                var kid = i;
                var visited = new HashSet<int>();
                var visitedList = new List<int>();
                while (!visited.Contains(kid))
                {
                    visited.Add(kid);
                    visitedList.Add(kid);
                    kid = Kids[kid];
                }
                if (visitedList.Count > 2 && visitedList[0] == Kids[visitedList[visitedList.Count - 1]])
                {
                    bestCyclical = Math.Max(bestCyclical, visitedList.Count);
                }
                else if(Kids[visitedList[visitedList.Count - 1]] == visitedList[visitedList.Count - 2])
                {
                    forests.Add(new Tuple<List<int>, HashSet<int>>(visitedList, visited));
                }
            }
            Console.WriteLine(Math.Max(bestCyclical, Max(new List<Tuple<List<int>, HashSet<int>>>(), 0)));
            writer.WriteLine(Math.Max(bestCyclical, Max(new List<Tuple<List<int>, HashSet<int>>>(), 0)));
        }


        static int Max(List<Tuple<List<int>, HashSet<int>>> included, int i)
        {
            if(i == forests.Count)
            {
                HashSet<int> visited = new HashSet<int>();
                foreach(var v in included)
                {
                    visited.UnionWith(v.Item2);
                }
                return visited.Count;
            }
            var shared = new HashSet<int>();
            foreach(var v in included)
            {
                shared.UnionWith(v.Item2);
            }
            shared.IntersectWith(forests[i].Item2);
            var sharedArr = shared.ToArray();
            if(shared.Count > 2 || shared.Count == 1)
            {
                return Max(included, i + 1);
            }
            else
            {
                int res = -1;
                bool canInclude = false;
                if(shared.Count == 2)
                {
                    if(included.Count(a => a.Item2.Contains(sharedArr[0]) && a.Item2.Contains(sharedArr[1])) == 1)
                    {
                        var other = included.Where(a => a.Item2.Contains(sharedArr[0]) && a.Item2.Contains(sharedArr[1])).First();
                        if(other.Item1[other.Item1.Count - 1] == forests[i].Item1[forests[i].Item1.Count - 2] &&
                            other.Item1[other.Item1.Count - 2] == forests[i].Item1[forests[i].Item1.Count - 1])
                        {
                            canInclude = true;
                        }
                    }
                }
                else
                {
                    canInclude = true;
                }
                if (canInclude)
                {
                    included.Add(forests[i]);
                    res = Max(included, i + 1);
                    included.RemoveAt(included.Count - 1);
                }
                res = Math.Max(res, Max(included, i + 1));
                return res;
            }
        }
    }
}
