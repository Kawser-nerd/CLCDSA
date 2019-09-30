using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleJam
{
    [DebuggerDisplay("X = {X} Y = {Y}")]
    public struct Point
    {
        public int X;
        public int Y;

        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public static Point operator -(Point first, Point other)
        {
            return new Point(first.X - other.X, first.Y - other.Y);
        }

        public static Point operator +(Point first, Point other)
        {
            return new Point(first.X + other.X, first.Y + other.Y);
        }

        public static int operator *(Point first, Point second)
        {
            return second.X*first.Y - second.Y*first.X;
        }

        public static Point operator *(Point first, int scale)
        {
            return new Point(first.X * scale, first.Y*scale);
        }

        public Point MirrorByDirectionBefore(int rayDirection, Point orienti)
        {
            if (rayDirection % 2 == 0)
            {
                return new Point(2 * orienti.X - X, Y);
            }
            return new Point(X, 2*orienti.Y - Y);
        }


        public Point MirrorByDirectionAfter(int rayDirection, Point pointAngle)
        {
            return MirrorByDirectionBefore(rayDirection + 1, pointAngle);
        }

        public Point MirrorByPoint(Point mirror)
        {
            return mirror * 2 - this;
        }

        public  Point GetWithDirection(int direction, int scale = 1)
        {
            int realOfs = (direction + 4)%4;
            return this + Ofs[realOfs] * scale;
        }

        public Point GetWithDirectionMiddleBefore(int direction)
        {
            int realOfs = (direction) % 4;
            return this + MiddleBeforeOfs[realOfs];
        }


        public static Point[] Ofs = new[]
                                        {
                                            new Point(1, 1), new Point(-1, 1), new Point(-1, -1), new Point(1, -1)
                                        };

        public static Point[] MiddleBeforeOfs = new[]
                                        {
                                            new Point(2, 0), new Point(0, 2), new Point(-2, 0), new Point(0, -2)
                                        };

        public Point GetWithDirectionMiddleAfter(int rayDirection)
        {
            int realOfs = (rayDirection + 1) % 4;
            return this + MiddleBeforeOfs[realOfs];
        }

    }

    public enum State { Empty, Mirror, X}

    public class Ray
    {
        private Point Origin;
        private Point Final;

        public Point CurrentCellCenter;

        int GetRayDirection()
        {
            var right = Final.X - Origin.X > 0;
            var bottom = Final.Y - Origin.Y > 0;
            if (right && bottom)
                return 0;
            if (!right && bottom)
                return 1;
            return right ? 3 : 2;
        }

        public static int  GetOrientedSquere(Point center, Point first, Point second)
        {
            return (first - center)*(second - center);
        }

        public Ray PassCell(State[][] matrix, out bool meet, bool initial)
        {
            if (!initial && GetStateForPoint(matrix, CurrentCellCenter) == State.X && GetOrientedSquere(Origin, Final, CurrentCellCenter) == 0)
            {
                meet = true;
                return null;
            }

            meet = false;

            int rayDirection = GetRayDirection();

            var pointAngle = CurrentCellCenter.GetWithDirection(rayDirection);

            var square = GetOrientedSquere(Origin, Final, pointAngle);

            if (square == 0)
            {
                var angleCenterCell = CurrentCellCenter.GetWithDirection(rayDirection, 2);
                var before = CurrentCellCenter.GetWithDirectionMiddleBefore(rayDirection);
                var after = CurrentCellCenter.GetWithDirectionMiddleAfter(rayDirection);
                bool isMirrorBefore = GetStateForPoint(matrix, before) == State.Mirror;
                bool isMirrorAfter = GetStateForPoint(matrix, after) == State.Mirror;
                bool isMirrorForAngle = GetStateForPoint(matrix, angleCenterCell) == State.Mirror;

                // back
                if (isMirrorAfter && isMirrorBefore && isMirrorForAngle)
                   
                    return new Ray(){Origin = Origin.MirrorByPoint(pointAngle), Final = Final.MirrorByPoint(pointAngle), CurrentCellCenter = CurrentCellCenter};
                // forward
                if (!isMirrorAfter && !isMirrorBefore && !isMirrorForAngle 
                    || isMirrorBefore && isMirrorAfter && !isMirrorForAngle
                    || !isMirrorAfter && isMirrorBefore && !isMirrorForAngle
                    || isMirrorAfter && !isMirrorBefore && !isMirrorForAngle)
                    return new Ray(){Origin = Origin, Final = Final, CurrentCellCenter = CurrentCellCenter.GetWithDirection(rayDirection, 2)};
                // destroy
                if (!isMirrorAfter && !isMirrorBefore && isMirrorForAngle)
                    return null;
                // before mirror
                if (isMirrorBefore && isMirrorForAngle && !isMirrorAfter)
                {
                    var newOrigin = Origin.MirrorByDirectionBefore(rayDirection, pointAngle);
                    var newFinal = Final.MirrorByDirectionBefore(rayDirection, pointAngle);
                    var newCell = CurrentCellCenter.GetWithDirectionMiddleAfter(rayDirection);
                    return new Ray(){Origin = newOrigin, Final = newFinal, CurrentCellCenter = newCell};
                }
                // after mirror
                if (!isMirrorBefore && isMirrorAfter && isMirrorForAngle)
                {
                    var newOrigin = Origin.MirrorByDirectionAfter(rayDirection, pointAngle);
                    var newFinal = Final.MirrorByDirectionAfter(rayDirection, pointAngle);
                    var newCell = CurrentCellCenter.GetWithDirectionMiddleBefore(rayDirection);
                    return new Ray() { Origin = newOrigin, Final = newFinal, CurrentCellCenter = newCell };
                }

            }

            if (square < 0)
            {
                var newCellCenter = CurrentCellCenter.GetWithDirectionMiddleBefore(rayDirection);

                if (GetStateForPoint(matrix, newCellCenter) == State.Mirror)
                {
                    var newOrigin = Origin.MirrorByDirectionBefore(rayDirection, pointAngle);
                    var newFinal = Final.MirrorByDirectionBefore(rayDirection, pointAngle);

                    return new Ray {Origin = newOrigin, Final = newFinal, CurrentCellCenter = CurrentCellCenter};
                }

                return new Ray {Origin = Origin, Final = Final, CurrentCellCenter = newCellCenter};
            }

            if (square > 0)
            {
                var newCellCenter = CurrentCellCenter.GetWithDirectionMiddleAfter(rayDirection);

                if (GetStateForPoint(matrix, newCellCenter) == State.Mirror)
                {
                    var newOrigin = Origin.MirrorByDirectionAfter(rayDirection, pointAngle);
                    var newFinal = Final.MirrorByDirectionAfter(rayDirection, pointAngle);
                    return new Ray { Origin = newOrigin, Final = newFinal, CurrentCellCenter = CurrentCellCenter };
                }

                return new Ray {Origin = Origin, Final = Final, CurrentCellCenter = newCellCenter};
            }

            return null;
        }

        private static State GetStateForPoint(State[][] matrix, Point newCellCenter)
        {
            return matrix[newCellCenter.X / 2][newCellCenter.Y / 2];
        }

        public bool TraceRay(int maxDistance, State[][] cells)
        {
            bool dd;
            var currentRay = PassCell(cells, out dd, true);
            if (currentRay == null)
                return false;
            int quadMaxDistance = maxDistance*maxDistance;
            while (QuadDistance(currentRay.Origin, CurrentCellCenter) <= quadMaxDistance)
            {
                bool meet;
                currentRay = currentRay.PassCell(cells, out meet, false);
                if (currentRay == null)
                    return meet;
            }
            return false;
        }

        private int QuadDistance(Point p1, Point p2)
        {
            return (p1.X - p2.X)*(p1.X - p2.X) + (p1.Y - p2.Y)*(p1.Y - p2.Y);
        }

        public static int TraceAllRays(State[][] states, int distance)
        {
            Point X = default(Point);
            for (int i = 0; i < states.Length; i++)
            {
                var state = states[i];
                for (int j = 0; j < state.Length; j++)
                {
                    State s = state[j];
                    if (s == State.X)
                    {
                        X = new Point(i, j);
                    }
                }
            }

            int reflections = 0;
            if (CalcToMirrorDistance(states, new Point(1, 0), X) <= distance)
                reflections++;
            if (CalcToMirrorDistance(states, new Point(0, 1), X) <= distance)
                reflections++;
            if (CalcToMirrorDistance(states, new Point(-1, 0), X) <= distance)
                reflections++;
            if (CalcToMirrorDistance(states, new Point(0, -1), X) <= distance)
                reflections++;

            Point ajustedX = new Point(2 * X.X + 1, 2 * X.Y + 1);

            Point[] uniquePairs = GenerateUniquePairs(distance);

            var possibleFinals = uniquePairs.SelectMany(p => ExpandPoint(p, ajustedX));
            var rays = possibleFinals.Select(f => new Ray() {CurrentCellCenter = ajustedX, Final = f, Origin = ajustedX});

            var finalRays = rays.Where(r => r.TraceRay(2*distance, states)).ToList();
            reflections += finalRays.Count();

            return reflections;
        }

        private static Point[] GenerateUniquePairs(int distance)
        {
            var points = new List<Point>();
            for (int i = 1; i <= distance; i++)
            {
                for (int j = 1; j <= distance; j++)
                {
                    if (GCD(i,j) == 1)
                        points.Add(new Point(i, j));
                }
            }
            return points.ToArray();
        }

        public static Point[] ExpandPoint(Point pair, Point ajustedX)
        {
            var helpPoint = new Point(pair.X, -pair.Y);
            return new[]
                       {
                           ajustedX + pair*2,
                           ajustedX - pair*2,
                           ajustedX + helpPoint*2,
                           ajustedX - helpPoint*2
                       };
        }

        public static int CalcToMirrorDistance(State[][] states, Point direction, Point x)
        {
            int result = 0;
            var current = x;
            while (states[current.X][current.Y] != State.Mirror)
            {
                result++;
                current = current + direction;
            }
            return 2*result - 1;
        }

        static int GCD(int a, int b)
        {
            while (b != 0)
            {
                int remainder = a % b;
                a = b;
                b = remainder;
            }

            return a;
        }
    }

    class Program
    {
        

        static void Main(string[] args)
        {
            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    var line = tr.ReadLine();
                    var ints = line.Split().Select(int.Parse).ToArray();
                    int H = ints[0];
                    int W = ints[1];
                    int D = ints[2];
                    var states = new State[H][];
                    for (int j = 0; j < H; j++)
                    {
                        states[j] = ParseLine(tr.ReadLine());
                    }
                    int resultRays = Ray.TraceAllRays(states, D);
                    tw.WriteLine(string.Format("Case #{0}: {1}", i + 1, resultRays));
                }
            }
        }

        private static State[] ParseLine(string readLine)
        {
            return readLine.Select(c =>
                                {
                                    switch(c)
                                    {
                                        case '.':
                                            return State.Empty;
                                        case '#':
                                            return State.Mirror;
                                        case 'X':
                                            return State.X;
                                        default:
                                            throw  new Exception();
                                    }
                                }).ToArray();
        }
    }
}
