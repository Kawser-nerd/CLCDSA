/*
 * C# in .NET Framework 3.5
 * Usage:
 * executable -i input_file -o output_file
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace HouseOfKittens
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
                writer.WriteLine("Case #{0}: {1}", i, answer.Max);
                writer.WriteLine(String.Join(" ", answer.Flavors.Select(x => x.ToString()).ToArray()));
            }


            stopwatch.Stop();
            Console.WriteLine("{0:#,###}ms", stopwatch.ElapsedMilliseconds);
        }

        private Result RunCase(TextReader reader)
        {
            var values = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var vertexCount = values[0];
            var wallCount = values[1];

            var end1 = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var end2 = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            var vertexes = new Vertex[vertexCount + 1];
            var rooms = new List<ICollection<Vertex>>();
            var wallDict = new Dictionary<int, IList<int>>();
            var roomDict = new Dictionary<int, IList<ICollection<Vertex>>>();
            var connectedV = new HashSet<Vertex>();

            var firstRoom = new HashSet<Vertex>();
            rooms.Add(firstRoom);
            for (var i = 1; i <= vertexCount; i++)
            {
                var v = new Vertex { Name = i };
                vertexes[i] = v;
                firstRoom.Add(v);
            }

            for (var i = 0; i < wallCount; i++)
            {
                var a = end1[i];
                var b = end2[i];
                var va = vertexes[a];
                var vb = vertexes[b];

                BuildWallDictionary(wallDict, a, b);
                connectedV.Add(va);
                connectedV.Add(vb);

                foreach (var r in rooms)
                {
                    if (r.Contains(va) && r.Contains(vb))
                    {
                        var r2 = new HashSet<Vertex>();
                        rooms.Add(r2);
                        r2.Add(va);
                        r2.Add(vb);
                        for (var j = a + 1; j < b; j++)
                        {
                            var vj = vertexes[j];
                            if (r.Remove(vj))
                                r2.Add(vj);
                        }
                        break;
                    }
                }
            }

            var minRoomSize = int.MaxValue;
            ICollection<Vertex> minRoom = null;
            foreach (var r in rooms)
            {
                var size = r.Count;
                if (size < minRoomSize)
                {
                    minRoomSize = size;
                    minRoom = r;
                }

                BuildRoomDict(roomDict, r);
            }

            var nextFlavor = 1;
            foreach (var v in minRoom)
            {
                v.Flavor = nextFlavor++;
            }

            var allFlavors = Enumerable.Range(1, minRoomSize);
            while (true)
            {
                var next = rooms.Select(r => new { V = r, Missing = minRoomSize - r.Where(v => v.Flavor != 0).Select(v => v.Flavor).Distinct().Count() })
                    .Where(x => x.Missing > 0)
                    .OrderBy(x => x.Missing)
                    .FirstOrDefault();
                if (next == null || next.Missing == 0) break;
                var myFlavors = allFlavors.Except(next.V.Select(v => v.Flavor)).ToArray();
                var myVertex = next.V.Where(v => v.Flavor == 0)
                    .Select(v => new { V = v, Prefer = connectedV.Contains(v) })
                    .OrderBy(x => x.Prefer ? 0 : 1)
                    .Select(x => x.V)
                    .ToArray();

                var c = Math.Min(myFlavors.Length, myVertex.Length);
                for (var i = 0; i < c; i++)
                {
                    myVertex[i].Flavor = myFlavors[i];
                }
            }

            //var assignFlavors = Enumerable.Range(1, minRoomSize).ToArray();
            //var nextFlavor = 0;
            //foreach (var vertex in vertexes.Skip(1))
            //{
            //    if (vertex.Flavor == 0)
            //    {
            //        vertex.Flavor = assignFlavors[nextFlavor];
            //        nextFlavor = (nextFlavor + 1) % minRoomSize;

            //        IList<ICollection<Vertex>> adjRooms = null;
            //        if (roomDict.TryGetValue(vertex.Name, out adjRooms))
            //        {
            //            AssignAdjRooms(adjRooms, vertex, assignFlavors, nextFlavor);
            //        }
            //    }
            //}

            //foreach (var r in rooms)
            //{
            //    var array = r.ToArray();
            //    var flavors = new HashSet<int>(array.Select(v => v.Flavor).Where(f => f != 0));
            //    for (var f = 1; f <= minRoomSize; f++)
            //    {
            //        if (flavors.Contains(f)) continue;
            //        var vertex = array.First(v => v.Flavor == 0);
            //        vertex.Flavor = f;
            //        flavors.Add(f);
            //    }
            //}

            vertexes = vertexes.Skip(1).ToArray();

            var result = new Result
            {
                Max = minRoomSize,
                Flavors = vertexes.Select(v => v.Flavor == 0 ? minRoomSize : v.Flavor).ToArray()
            };
            return result;
        }

        private void AssignAdjRooms(IList<ICollection<Vertex>> adjRooms, Vertex vertex, int[] assignFlavors, int nextFlavor)
        {

        }

        private void BuildRoomDict(IDictionary<int, IList<ICollection<Vertex>>> roomDict, ICollection<Vertex> room)
        {
            foreach (var v in room)
            {
                IList<ICollection<Vertex>> list = null;
                if (!roomDict.TryGetValue(v.Name, out list))
                {
                    list = new List<ICollection<Vertex>>();
                    roomDict.Add(v.Name, list);
                }
                list.Add(room);
            }
        }

        private void BuildWallDictionary(IDictionary<int, IList<int>> walls, int a, int b)
        {
            IList<int> list = null;
            if (!walls.TryGetValue(a, out list))
            {
                list = new List<int>();
                walls.Add(a, list);
            }
            list.Add(b);
            if (!walls.TryGetValue(b, out list))
            {
                list = new List<int>();
                walls.Add(b, list);
            }
            list.Add(a);
        }
    }

    class Result
    {
        public int Max { get; set; }
        public int[] Flavors { get; set; }
    }

    class Vertex
    {
        public int Name { get; set; }
        public int Flavor { get; set; }

        public override string ToString()
        {
            return String.Format("{0}-{1}", Name, Flavor);
        }
    }
}
