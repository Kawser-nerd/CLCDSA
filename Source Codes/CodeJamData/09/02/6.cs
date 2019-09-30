using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        private static int[,] marks = new int[0, 0];

        public static void Main(string[] args)
        {
            string filePath = @"C:\B-large.in";

            using (StreamReader reader = new StreamReader(filePath))
            {
                int T = int.Parse(reader.ReadLine());
                for (int i = 1; i <= T; i++)
                {
                    var numbers = reader.ReadLine().Split(' ');
                    int H = int.Parse(numbers[0]);
                    int W = int.Parse(numbers[1]);

                    var altitudes = new int[H, W];
                    for (int y = 0; y < H; y++)
                    {
                        var line = reader.ReadLine().Split(' ');
                        for (int x = 0; x < W; x++)
                            altitudes[y, x] = int.Parse(line[x]);
                    }

                    SolveCase(altitudes, i);
                }
            }
        }

        public static void SolveCase(int[,] altitudes, int caseNumber)
        {
            marks = new int[altitudes.GetLength(0), altitudes.GetLength(1)];
            MarkBasins(altitudes, FindSinks(altitudes));
            var results = Alphabetize();

            using (StreamWriter writer = new StreamWriter(@"C:\result.txt", true))
            {
                writer.WriteLine(string.Format("Case #{0}:", caseNumber));
                for (int y = 0; y < results.GetLength(0); y++)
                {
                    for (int x = 0; x < results.GetLength(1); x++)
                        writer.Write(new[] { results[y, x], ' ' });

                    writer.WriteLine();
                }
            }
        }

        public static char[,] Alphabetize()
        {
            char alpha = 'a';
            char[] alphamap = new char[26];
            char[,] results = new char[marks.GetLength(0), marks.GetLength(1)];

            for (int y = 0; y < marks.GetLength(0); y++)
                for (int x = 0; x < marks.GetLength(1); x++)
                    if (alphamap[marks[y, x] - 1] == 0)
                        alphamap[marks[y, x] - 1] = alpha++;

            for (int y = 0; y < marks.GetLength(0); y++)
                for (int x = 0; x < marks.GetLength(1); x++)
                    results[y, x] = alphamap[marks[y, x] - 1];

            return results;
        }

        public static void Explore(Point thisCell, int[,] altitudes, int basinNumber)
        {
            int x = thisCell.X, y = thisCell.Y;
            marks[y, x] = basinNumber;
            int alt = altitudes[y, x];

            Point? north = (y <= 0) ? (Point?)null : new Point(x, y - 1);
            Point? west = (x <= 0) ? (Point?)null : new Point(x - 1, y);
            Point? south = (y >= altitudes.GetLength(0) - 1) ? (Point?)null : new Point(x, y + 1);
            Point? east = (x >= altitudes.GetLength(1) - 1) ? (Point?)null : new Point(x + 1, y);

            int nAlt = (north.HasValue) ? altitudes[north.Value.Y, north.Value.X] : int.MinValue;
            int wAlt = (west.HasValue) ? altitudes[west.Value.Y, west.Value.X] : int.MinValue;
            int sAlt = (south.HasValue) ? altitudes[south.Value.Y, south.Value.X] : int.MinValue;
            int eAlt = (east.HasValue) ? altitudes[east.Value.Y, east.Value.X] : int.MinValue;

            if (nAlt > alt && GoesTo(north.Value, altitudes) == thisCell)
                Explore(north.Value, altitudes, basinNumber);
            if (wAlt > alt && GoesTo(west.Value, altitudes) == thisCell)
                Explore(west.Value, altitudes, basinNumber);
            if (eAlt > alt && GoesTo(east.Value, altitudes) == thisCell)
                Explore(east.Value, altitudes, basinNumber);
            if (sAlt > alt && GoesTo(south.Value, altitudes) == thisCell)
                Explore(south.Value, altitudes, basinNumber);
        }

        public static IEnumerable<Point> FindSinks(int[,] altitudes)
        {
            for (int x = 0; x < altitudes.GetLength(1); x++)
                for (int y = 0; y < altitudes.GetLength(0); y++)
                {
                    var p = new Point(x, y);
                    if(GoesTo(p, altitudes) == null) yield return p;
                }
        }

        public static Point? GoesTo(Point thisCell, int[,] altitudes)
        {
            int x = thisCell.X, y = thisCell.Y;
            int alt = altitudes[y, x];

            Point? north = (y <= 0) ? (Point?)null : new Point(x, y - 1);
            Point? west = (x <= 0) ? (Point?)null : new Point(x - 1, y);
            Point? south = (y >= altitudes.GetLength(0) - 1) ? (Point?)null : new Point(x, y + 1);
            Point? east = (x >= altitudes.GetLength(1) - 1) ? (Point?)null : new Point(x + 1, y);

            int nAlt = (north.HasValue) ? altitudes[north.Value.Y, north.Value.X] : int.MaxValue;
            int wAlt = (west.HasValue) ? altitudes[west.Value.Y, west.Value.X] : int.MaxValue;
            int sAlt = (south.HasValue) ? altitudes[south.Value.Y, south.Value.X] : int.MaxValue;
            int eAlt = (east.HasValue) ? altitudes[east.Value.Y, east.Value.X] : int.MaxValue;

            { // find sink
                int smallest = (int)Math.Min(Math.Min(Math.Min(nAlt, wAlt), sAlt), eAlt);
                if (smallest < alt)
                {
                    if (nAlt == smallest)
                        return north.Value;
                    else if (wAlt == smallest)
                        return west.Value;
                    else if (eAlt == smallest)
                        return east.Value;
                    else if (sAlt == smallest)
                        return south.Value;
                }
                
                return null;
            }
        }

        public static void MarkBasins(int[,] altitudes, IEnumerable<Point> sinks)
        {
            int i = 1;
            foreach (var point in sinks)
                Explore(point, altitudes, i++);
        }
    }
}
