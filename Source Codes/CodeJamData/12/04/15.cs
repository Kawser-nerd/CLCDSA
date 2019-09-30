using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Mirrors
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= testCases; i++)
                new Program().Solve(i);
        }

        bool[,] Map;
        int Width;
        int Height;
        int Left, Top, Right, Bottom;
        double MaxDistance;
        Vector2 Me;
        const double Eps = 0.00001;
        const int NumSamples = 5000000;

        void Solve(int testCase)
        {
            var inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            Width = inputs[1];
            Height = inputs[0];
            MaxDistance = inputs[2];

            Map = new bool[Width, Height];
            for (int y = 0; y < Height; y++)
            {
                var cell = Console.ReadLine().ToArray();
                for (int x = 0; x < Width; x++)
                    Map[x, y] = cell[x] == '#';
                if (Array.IndexOf(cell, 'X') >= 0)
                    Me = new Vector2(Array.IndexOf(cell, 'X') + 0.5, y + 0.5);
            }

            Left = Top = 1;
            Right = Width - 1;
            Bottom = Height - 1;

            var hits =
                Enumerable.Range(0, NumSamples)
                .AsParallel()
                .Select(i => new { Index = i, RayHit = TraceRay(i) })
                .Where(p => p.RayHit)
                .OrderBy(p => p.Index)
                .ToList();

            var beginIsEnd = hits.Count > 1 && hits.First().Index == 0 && hits.Last().Index == NumSamples - 1;

            var actualHits = hits
                .Split((a, b) => Math.Abs(a.Index - b.Index) > 1)
                .Select(g => g.First())
                .ToList();

            Console.WriteLine("Case #{0}: {1}", testCase, actualHits.Count - (beginIsEnd ? 1 : 0));
        }

        bool TraceRay(int sampleIndex)
        {
            var d = MaxDistance;
            var p = Me;
            var angle = Math.PI * 2.0 * sampleIndex / (double)NumSamples;
            var dir = new Vector2(Math.Cos(angle), Math.Sin(angle));
            var first = true;

            while (d > 0)
            {
                var s = GetNextSegment(p, dir, d);
                p = s.To;
                dir = s.NewDir;
                d -= s.Length;
                if (s.HasHitMe && !first)
                    return true;
                first = false;
            }

            return false;
        }

        Segment GetNextSegment(Vector2 pos, Vector2 dir, double d)
        {
            var result = new Segment { From = pos, Dir = dir};

            double tx, ty;
            if (dir.X >= 0 && dir.Y >= 0)
            {
                tx = (Right - pos.X) / dir.X;
                ty = (Bottom - pos.Y) / dir.Y;
            }
            else if (dir.X < 0 && dir.Y >= 0)
            {
                tx = (pos.X - Left) / -dir.X;
                ty = (Bottom - pos.Y) / dir.Y;
            }
            else if (dir.X < 0 && dir.Y < 0)
            {
                tx = (pos.X - Left) / -dir.X;
                ty = (pos.Y - Top) / -dir.Y;
            }
            else
            {
                tx = (Right - pos.X) / dir.X;
                ty = (pos.Y - Top) / -dir.Y;
            }

            var t = Math.Min(ty, tx);
            result.To = pos + dir * t;

            if (RoughlyEquals(ty, tx))
                result.NewDir = dir * -1; // Corner
            else if (tx < ty)
                result.NewDir = new Vector2(-dir.X, dir.Y);
            else
                result.NewDir = new Vector2(dir.X, -dir.Y);

            if (LineToPointDistance(pos, dir, Me) < 0.005)
                if ((Me - pos).Length <= d)
                    result.HasHitMe = true;

            return result;
        }

        double LineToPointDistance(Vector2 from, Vector2 dir, Vector2 point)
        {
            return ((from - point) - (dir * (from - point).Dot(dir))).Length;
        }

        bool RoughlyEquals(double a, double b)
        {
            return Math.Abs(a - b) < Eps;
        }
    }

    class Segment
    {
        public Vector2 From;
        public Vector2 Dir;

        public Vector2 To;
        public Vector2 NewDir;
        public double Length { get { return (To - From).Length; } }

        public bool HasHitMe;
    }

    struct Vector2
    {
        public double X;
        public double Y;

        public Vector2(double x, double y)
        {
            X = x;
            Y = y;
        }

        public static Vector2 operator +(Vector2 a, Vector2 b)
        {
            return new Vector2 { X = a.X + b.X, Y = a.Y + b.Y };
        }

        public static Vector2 operator -(Vector2 a, Vector2 b)
        {
            return new Vector2 { X = a.X - b.X, Y = a.Y - b.Y };
        }

        public static Vector2 operator *(Vector2 v, double f)
        {
            return new Vector2 { X = v.X * f, Y = v.Y * f };
        }

        public double Length
        {
            get { return Math.Sqrt(X * X + Y * Y); }
        }

        public double Dot(Vector2 v)
        {
            return X * v.X + Y * v.Y;
        }
    }

    public static class EnumerableExtensions
    {
        public static IEnumerable<List<T>> Split<T>(this IEnumerable<T> enumerable, Func<T, T, bool> splitFunc)
        {
            var current = new List<T>();
            foreach (var item in enumerable)
            {
                if (current.Count > 0 && splitFunc(current.Last(), item))
                {
                    yield return current;
                    current = new List<T>();
                }
                current.Add(item);
            }
            if (current.Count > 0)
                yield return current;
        }
    }
}
