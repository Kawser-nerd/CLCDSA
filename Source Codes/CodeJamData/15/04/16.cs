using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    class D
    {
        static void Main(string[] args)
        {
            var input = @"C:\Users\kaspir\Downloads\D-large.in";

            File.WriteAllLines(Path.ChangeExtension(input, "out"), Solver.Solve(File.ReadAllLines(input)));

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);

                reader.Next();

                for (var i = 0; ; i++)
                {
                    var l = reader.NextOrNull();

                    if (l == null)
                        break;

                    var parts = l.Split(' ').Select(int.Parse).ToList();
                    var x = parts[0];
                    var r = parts[1];
                    var c = parts[2];
                    var message = string.Format("Case #{0}: {1}", i + 1, RichardCanWin(x, r, c) ? "RICHARD" : "GABRIEL");
                    Console.WriteLine(message);
                    yield return message;
                }
            }

            public static bool RichardCanWin(int X, int R, int C)
            {
                if (R < C)
                    return RichardCanWin(X, C, R);

                var obviousAnswer = IsRichardObviousWinner(X, R, C);

                if (obviousAnswer != null)
                    return obviousAnswer.Value;

                var figures = GenerateFigures(X).ToList();

                var richardWinningFigures = new List<Figure>();
                var gabrielWinningFigures = new List<Figure>();

                foreach (var f in figures)
                {
                    var gabrielCanWin = false;

                    for (var r = 0; r < R - f.MaxR; r++)
                        for (var c = 0; c < C - f.MaxC; c++)
                        {
                            var field = new Field(R, C);

                            foreach (var p in f.Points)
                                field[p.Offset(r, c)] = '*';

                            var colorCounts = new Dictionary<char, int>();

                            for (var color = 'a'; ; color++)
                            {
                                var firstEmpty = field.Points.FirstOrDefault(p => field.IsEmpty(p));

                                if (firstEmpty == null)
                                    break;

                                var stack = new Stack<Point>(new[] { firstEmpty });
                                colorCounts[color] = 0;

                                while (stack.Any())
                                {
                                    var p = stack.Pop();

                                    if (!field.HasPoint(p) || !field.IsEmpty(p))
                                        continue;

                                    field[p] = color;
                                    colorCounts[color]++;

                                    stack.Push(new Point(p.R - 1, p.C));
                                    stack.Push(new Point(p.R + 1, p.C));
                                    stack.Push(new Point(p.R, p.C - 1));
                                    stack.Push(new Point(p.R, p.C + 1));
                                }
                            }

                            if (colorCounts.Values.All(v => v % X == 0))
                                gabrielCanWin = true;
                        }

                    if (!gabrielCanWin)
                        richardWinningFigures.Add(f);
                    else
                        gabrielWinningFigures.Add(f);
                }

                var uniqueRichardWinningFigures = richardWinningFigures.Except(gabrielWinningFigures.SelectMany(GetTransformations)).ToList();

                return uniqueRichardWinningFigures.Any();
            }

            static IEnumerable<Figure> GetTransformations(Figure f)
            {
                var current = f;

                for (var i = 0; i < 4; i++)
                {
                    yield return current;
                    yield return current.Mirrorred();
                    current = f.Rotated();
                }
            }

            public class Field
            {
                readonly char[][] _field;
                public int rowCount { get { return _field.Length; } }
                public int columnCount { get { return _field[0].Length; } }

                public Field(int rowCount, int columnCount)
                {
                    _field = new char[rowCount][];

                    for (var r = 0; r < rowCount; r++)
                        _field[r] = new char[columnCount];

                    for (var r = 0; r < rowCount; r++)
                        for (var c = 0; c < columnCount; c++)
                            _field[r][c] = ' ';
                }

                public override string ToString()
                {
                    return string.Join(Environment.NewLine, _field.Select(l => new string(l)));
                }

                public IEnumerable<Point> Points
                {
                    get
                    {
                        for (var r = 0; r < rowCount; r++)
                            for (var c = 0; c < columnCount; c++)
                                yield return new Point(r, c);
                    }
                }

                public char this[Point point]
                {
                    get { return _field[point.R][point.C]; }
                    set { _field[point.R][point.C] = value; }
                }

                public bool IsEmpty(Point p)
                {
                    return this[p] == ' ';
                }

                public bool HasPoint(Point point)
                {
                    return point.R >= 0 && point.C >= 0 && point.R < rowCount && point.C < columnCount;
                }
            }

            static bool? IsRichardObviousWinner(int X, int R, int C)
            {
                var canHaveHole = X >= 7; // Richard will win

                if (canHaveHole)
                    return true;

                var canBeTooLong = X > R; // Richard will win

                if (canBeTooLong)
                    return true;

                var notMultiple = (R * C) % X > 0; // Richard will win

                if (notMultiple)
                    return true;

                var canExceedShortest = ((X + 1) / 2) > C; // Richard will win

                if (canExceedShortest)
                    return true;

                var canAvoidTouchingAllSides = true; // Gabriel will win
                for (var s = 1; s <= X / 2; s++)
                {
                    var l = X - s + 1;
                    canAvoidTouchingAllSides &= (s <= C - 2) && (l <= R - 2);
                }

                if (canAvoidTouchingAllSides)
                    return false;

                return null;
            }

            public static IEnumerable<Figure> GenerateFigures(int size)
            {
                if (size == 1)
                    return new[] { new Figure(new[] { new Point(5, 5) }) };

                return GenerateFigures(size - 1).SelectMany(f => f.GetAttachPoints().Select(f.WithAttached)).Distinct();
            }

            public class Point : IEquatable<Point>
            {
                public readonly int C;
                public readonly int R;

                public Point(int r, int c)
                {
                    C = c;
                    R = r;
                }

                public Point Offset(int r, int c)
                {
                    return new Point(R + r, C + c);
                }

                public override string ToString()
                {
                    return string.Format("C: {0}, R: {1}", C, R);
                }

                public bool Equals(Point other)
                {
                    if (ReferenceEquals(null, other)) return false;
                    if (ReferenceEquals(this, other)) return true;
                    return C == other.C && R == other.R;
                }

                public override bool Equals(object obj)
                {
                    if (ReferenceEquals(null, obj)) return false;
                    if (ReferenceEquals(this, obj)) return true;
                    if (obj.GetType() != GetType()) return false;
                    return Equals((Point)obj);
                }

                public override int GetHashCode()
                {
                    unchecked
                    {
                        return (C * 397) ^ R;
                    }
                }
            }

            public class Figure : IEquatable<Figure>
            {
                public readonly IReadOnlyCollection<Point> Points;
                public readonly int MaxC;
                public readonly int MaxR;

                public Figure(IEnumerable<Point> points)
                {
                    Points = Normalize(points).OrderBy(p => p.C).ThenBy(p => p.R).ToList().AsReadOnly();
                    MaxC = Points.Max(p => p.C);
                    MaxR = Points.Max(p => p.R);
                }

                static IEnumerable<Point> Normalize(IEnumerable<Point> points)
                {
                    var minC = points.Min(p => p.C);
                    var minR = points.Min(p => p.R);

                    return points.Select(p => new Point(p.R - minR, p.C - minC));
                }

                static IEnumerable<Point> GetNeighbours(Point point)
                {
                    yield return new Point(point.R - 1, point.C);
                    yield return new Point(point.R + 1, point.C);
                    yield return new Point(point.R, point.C - 1);
                    yield return new Point(point.R, point.C + 1);
                }

                public IEnumerable<Point> GetAttachPoints()
                {
                    return Points.SelectMany(GetNeighbours).Except(Points).Distinct();
                }

                public Figure WithAttached(Point point)
                {
                    return new Figure(Points.Concat(new[] { point }));
                }

                public override string ToString()
                {
                    var rows = MaxR + 1;
                    var cols = MaxC + 1;

                    var result = new char[rows][];

                    for (var r = 0; r < rows; r++)
                        result[r] = new String(' ', cols).ToCharArray();

                    foreach (var p in Points)
                        result[p.R][p.C] = '*';

                    return string.Join(Environment.NewLine, result.Select(l => new string(l)));
                }

                public bool Equals(Figure other)
                {
                    if (ReferenceEquals(null, other)) return false;
                    if (ReferenceEquals(this, other)) return true;
                    return Points.SequenceEqual(other.Points);
                }

                public override bool Equals(object obj)
                {
                    if (ReferenceEquals(null, obj)) return false;
                    if (ReferenceEquals(this, obj)) return true;
                    if (obj.GetType() != GetType()) return false;
                    return Equals((Figure)obj);
                }

                public override int GetHashCode()
                {
                    return (Points != null ? Points.Aggregate(0, (acc, p) => acc * 397 + p.GetHashCode()) : 0);
                }

                public Figure Rotated()
                {
                    return new Figure(Points.Select(p => new Point(p.C, -p.R)));
                }

                public Figure Mirrorred()
                {
                    return new Figure(Points.Select(p => new Point(p.R, -p.C)));
                }
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }
}
