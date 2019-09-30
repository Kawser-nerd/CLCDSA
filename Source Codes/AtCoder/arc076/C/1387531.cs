using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC076
{
    class Connected
    {
        public static void Main()
        {
            var yes = "YES"; var no = "NO";
            var rcn = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var r = rcn[0]; var c = rcn[1]; var n = rcn[2];
            var square = new Square { R = r, C = c };
            var points = (new int[n]).Select(_ => ReadLine().Split(' ').Select(__ => int.Parse(__)).ToArray()).Select((_, i) => new Line(i, _[0], _[1], _[2], _[3])).Where(_ => square.IsSeparatedByLine(_)).SelectMany(_ => new[] { _.A, _.B }).ToArray();
            var upper = points.Where(_ => square.OnUpperLine(_));
            var lower = points.Where(_ => square.OnLowerLine(_));
            var right = points.Where(_ => square.OnRightLine(_));
            var left = points.Where(_ => square.OnLeftLine(_));
            var stack = new Stack<int>();
            foreach (var edge in new [] { upper.OrderBy(_ => _.X), right.OrderByDescending(_ => _.Y), lower.OrderByDescending(_ => _.X), left.OrderBy(_ => _.Y) }) {
                foreach(var point in edge.Select(_ => _.Id)) {
                    if (stack.Count() != 0 && stack.Peek() == point) stack.Pop();
                    else stack.Push(point);
                }
            }
            if (stack.Count == 0) WriteLine(yes);
            else WriteLine(no);
        }
        public struct Point
        {
            public int Id, X, Y;
        }
        struct Square
        {
            public int R, C;
            public bool IsSeparatedByLine(Line line)
            {
                return (line.A.X == 0 || line.A.X == R || line.A.Y == 0 || line.A.Y == C) && (line.B.X == 0 || line.B.X == R || line.B.Y == 0 || line.B.Y == C);
            }
            public bool OnUpperLine(Point point)
            {
                return point.Y == C && point.X != 0;
            }
            public bool OnLowerLine(Point point)
            {
                return point.Y == 0 && point.X != R;
            }
            public bool OnRightLine(Point point)
            {
                return point.X == R && point.Y != C;
            }
            public bool OnLeftLine(Point point)
            {
                return point.X == 0 && point.Y != 0;
            }
        }
        struct Line
        {
            public Point A, B;
            public Line(int id, int x1, int y1, int x2, int y2)
            {
                A = new Point { Id = id, X = x1, Y = y1 };
                B = new Point { Id = id, X = x2, Y = y2 };
            }

        }
    }
}