using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC076
{
    class Built
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var points = new Point[n];
            for (int x, y, i = 0; i < points.Length; ++i) {
                Read(ReadLine().Trim(), out x, out y);
                points[i] = new Point(i, x, y);
            }
            var dist = new Distance[n * 2 - 2];
            points = points.OrderBy(_ => _.X).ToArray();
            for (var i = 1; i < points.Length; ++i) {
                dist[i - 1] = new Distance(points[i - 1].Id, points[i].Id, points[i].X - points[i - 1].X);
            }
            points = points.OrderBy(_ => _.Y).ToArray();
            for (var i = 1; i < points.Length; ++i) {
                dist[i + points.Length - 2] = new Distance(points[i - 1].Id, points[i].Id, points[i].Y - points[i - 1].Y);
            }
            dist = dist.OrderBy(_ => _.Dist).ToArray();
            var uft = new UnionFindTree[n];
            for (var i = 0; i < uft.Length; ++i) {
                uft[i] = new UnionFindTree();
            }
            long res = 0;
            foreach(var d in dist) {
                if (!uft[d.From].IsSameUnion(uft[d.To])) {
                    res += d.Dist;
                    uft[d.From].MergeUnion(uft[d.To]);
                }
            }
            WriteLine(res);
        }
        class UnionFindTree
        {
            UnionFindTree _parent = null;
            UnionFindTree Parent
            {
                get
                {
                    return (_parent == null) ? this : _parent = _parent.Parent;
                }
                set
                {
                    Parent._parent = value.Parent;
                }
            }
            public void MergeUnion(UnionFindTree other)
            {
                Parent = other.Parent;
            }
            public bool IsSameUnion(UnionFindTree other)
            {
                return Parent == other.Parent;
            }
        }
        static void Read(string str, out int x, out int y)
        {
            var s = str.Split(' ').Select(_ => int.Parse(_)).ToArray();
            x = s[0]; y = s[1];
        }
        struct Point
        {
            public Point(int id, int x, int y)
            {
                Id = id; X = x; Y = y;
            }
            public int X { get; private set; }
            public int Y { get; private set; }
            public int Id { get; private set; }
        }
        struct Distance
        {
            public int From
            {
                get; private set;
            }
            public int To
            {
                get; private set;
            }
            public int Dist
            {
                get; private set;
            }
            public Distance(int f, int t, int dist)
            {
                From = f; To = t; Dist = dist;
            }
        }
    }
}