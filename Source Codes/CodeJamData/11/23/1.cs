using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Vertix
    {
        public int Id { get; set; }
        public int ColorId { get; set; }
        public int ConvexCount(IEnumerable<Convex> c)
        {
            return c.Where(x => x.Vertices.Contains(Id)).Count();
        }
    }
    class Color
    {
        public int Id { get; set; }
        public int ConvexCount(IEnumerable<Convex> c)
        {
            return c.Where(x => x.Colors.Contains(Id)).Count();
        }
    }
    class Convex
    {
        public Convex()
        {
            Vertices = new HashSet<int>();
            Colors = new HashSet<int>();
        }
        public HashSet<int> Vertices { get; private set; }
        public HashSet<int> Colors { get; private set; }

        public bool HasLine(int start, int end)
        {
            return Vertices.Contains(start) && Vertices.Contains(end);
        }

        public bool HasVertix(int v)
        {
            return Vertices.Contains(v);
        }

        public Convex[] Split(int start, int end)
        {
            Convex one = new Convex();
            Convex two = new Convex();

            foreach (int a in Vertices)
            {
                if (a > start && a < end)
                {
                    one.Vertices.Add(a);
                }
                else if (a < start || a > end)
                {
                    two.Vertices.Add(a);
                }
                else
                {
                    one.Vertices.Add(a);
                    two.Vertices.Add(a);
                }
            }
            return new Convex[] { one, two };
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            StringBuilder b = new StringBuilder();
            int n = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < n; i++)
            {
                b.AppendFormat("Case #{0}: ", i+1);
                string[] values = lines[index++].Split(' ');
                int vertextNumber = int.Parse(values[0]);
                int wallNumber = int.Parse(values[1]);
                string[] startList = lines[index++].Split(' ');
                string[] endList = lines[index++].Split(' ');
                List<Convex> convexes = new List<Convex>();
                Convex c = new Convex();
                for (int j = 1; j <= vertextNumber; j++)
                {
                    c.Vertices.Add(j);
                }
                convexes.Add(c);
                for (int j = 0; j < wallNumber; j++)
                {
                    int start = int.Parse(startList[j]);
                    int end = int.Parse(endList[j]);
                    List<Convex> newList = new List<Convex>();
                    foreach (Convex conv in convexes)
                    {
                        if (conv.HasLine(start, end))
                        {
                            newList.AddRange(conv.Split(start, end));
                        }
                        else
                        {
                            newList.Add(conv);
                        }
                    }
                    convexes = newList;
                }
                int maxNumber = convexes.Min(x => x.Vertices.Count);
                List<Vertix> verticies = new List<Vertix>();
                for (int j = 0; j < vertextNumber; j++)
                {
                    verticies.Add(new Vertix() { Id = j + 1, ColorId = 0 });
                }
                List<Color> colors = new List<Color>();
                for (int j = 0; j < maxNumber; j++)
                {
                    colors.Add(new Color() { Id = j + 1 });
                }
                var orderdV = verticies.Select(x => x).OrderBy(x => x.ConvexCount(convexes)).Reverse();
                foreach (Vertix v in orderdV)
                {
                    var conv = convexes.Where(x => x.HasVertix(v.Id));
                    var candidateColors = new List<int>();
                    foreach(Color color in colors)
                    {
                        candidateColors.Add(conv.Where(x => x.Colors.Contains(color.Id)).Count());
                    }
                    var minColor = candidateColors.IndexOf( candidateColors.Min()) +1;
                    Color color2 = colors.Where(x => x.Id == minColor).First();
                    
                    foreach (Convex cx in conv)
                    {
                        cx.Colors.Add(color2.Id);
                    }
                    v.ColorId = color2.Id;
                }
                b.AppendLine(maxNumber.ToString());
                foreach (Vertix v in verticies)
                {
                    b.Append(v.ColorId);
                    b.Append(" ");
                }
                b.AppendLine();

            }
            File.WriteAllText(args[0] + ".out", b.ToString());
        }
    }
}
