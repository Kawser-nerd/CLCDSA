using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            var cases = Enumerable.Range(1, caseCount).Select(_ => ReadCase()).ToList();
            var solutions = cases
                //.AsParallel().AsOrdered()
                .Select(SolveCase).ToList();
            foreach (var caseNumber in Enumerable.Range(1, caseCount))
            {
                Console.WriteLine("Case #{0}:", caseNumber);
                WriteSolution(solutions[caseNumber - 1]);
            }
        }

        static Case ReadCase()
        {
            var sizes = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var lovers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var theCase = new Case
            {
                RowCount = sizes[0],
                ColumnCount = sizes[1]
            };
            theCase.Lovers = new Tuple<int, int>[theCase.RowCount + theCase.ColumnCount];
            for (var i = 0; i < lovers.Count; i += 2)
            {
                theCase.Lovers[i / 2] = Tuple.Create(lovers[i], lovers[i + 1]);
            }
            return theCase;
        }

        static Solution SolveCase(Case theCase)
        {
            var cells = new char[theCase.RowCount, theCase.ColumnCount];
            var loversLeft = theCase.Lovers.ToList();
            var courtiersLeft = Enumerable.Range(1, 2 * (theCase.RowCount + theCase.ColumnCount)).ToList();
            while (loversLeft.Any())
            {
                var isLoverPairFound = false;
                foreach (var loverPair in loversLeft)
                {
                    if (AreAdjunced(loverPair, courtiersLeft))
                    {
                        if (!TryBuildPath(theCase, loverPair, cells, courtiersLeft))
                            return new Solution();
                        loversLeft.Remove(loverPair);
                        courtiersLeft.Remove(loverPair.Item1);
                        courtiersLeft.Remove(loverPair.Item2);
                        isLoverPairFound = true;
                        break;
                    }
                }
                if (!isLoverPairFound)
                    return new Solution();
            }

            var solution = new Solution
            {
                Maze = new string[theCase.RowCount]
            };
            for (var row = 0; row < theCase.RowCount; row++)
            {
                var builder = new StringBuilder(theCase.ColumnCount);
                for (var column = 0; column < theCase.ColumnCount; column++)
                {
                    builder.Append(cells[row, column] == (char)0 ? '/' : cells[row, column]);
                }
                solution.Maze[row] = builder.ToString();
            }
            return solution;
        }

        static bool TryBuildPath(Case theCase, Tuple<int, int> loverPair, char[,] cells, List<int> courtiersLeft)
        {
            var clockwisePair = IsClockwise(loverPair, courtiersLeft) ? 
                loverPair : 
                Tuple.Create(loverPair.Item2, loverPair.Item1);

            var currentCoordinates = GetCourtierCoordinates(clockwisePair.Item1, theCase);
            var targetCoordinates = GetCourtierCoordinates(clockwisePair.Item2, theCase);
            Direction lastDirection;
            if (currentCoordinates.Column == -1)
            {
                currentCoordinates.Column++;
                lastDirection = Direction.Right;
            }
            else if (currentCoordinates.Row == -1)
            {
                currentCoordinates.Row++;
                lastDirection = Direction.Down;
            }
            else if (currentCoordinates.Column == theCase.ColumnCount)
            {
                currentCoordinates.Column--;
                lastDirection = Direction.Left;
            }
            else
            {
                currentCoordinates.Row--;
                lastDirection = Direction.Up;
            }

            while (currentCoordinates != targetCoordinates)
            {
                if ((currentCoordinates.Row < 0) || (currentCoordinates.Column < 0) ||
                    (currentCoordinates.Row >= theCase.RowCount) || (currentCoordinates.Column >= theCase.ColumnCount))
                    return false;

                switch (cells[currentCoordinates.Row, currentCoordinates.Column])
                {
                    case (char)0:
                        switch (lastDirection)
                        {
                            case Direction.Right:
                                cells[currentCoordinates.Row, currentCoordinates.Column] = '/';
                                currentCoordinates.Row--;
                                lastDirection = Direction.Up;
                                break;
                            case Direction.Down:
                                cells[currentCoordinates.Row, currentCoordinates.Column] = '\\';
                                currentCoordinates.Column++;
                                lastDirection = Direction.Right;
                                break;
                            case Direction.Left:
                                cells[currentCoordinates.Row, currentCoordinates.Column] = '/';
                                currentCoordinates.Row++;
                                lastDirection = Direction.Down;
                                break;
                            case Direction.Up:
                                cells[currentCoordinates.Row, currentCoordinates.Column] = '\\';
                                currentCoordinates.Column--;
                                lastDirection = Direction.Left;
                                break;
                            default:
                                throw new InvalidOperationException();
                        }
                        break;
                    case '/':
                        switch (lastDirection)
                        {
                            case Direction.Down:
                                currentCoordinates.Column--;
                                lastDirection = Direction.Left;
                                break;
                            case Direction.Right:
                                currentCoordinates.Row--;
                                lastDirection = Direction.Up;
                                break;
                            case Direction.Up:
                                currentCoordinates.Column++;
                                lastDirection = Direction.Right;
                                break;
                            case Direction.Left:
                                currentCoordinates.Row++;
                                lastDirection = Direction.Down;
                                break;
                            default:
                                throw new InvalidOperationException();
                        }
                        break;
                    case '\\':
                        switch (lastDirection)
                        {
                            case Direction.Down:
                                currentCoordinates.Column++;
                                lastDirection = Direction.Right;
                                break;
                            case Direction.Right:
                                currentCoordinates.Row++;
                                lastDirection = Direction.Down;
                                break;
                            case Direction.Up:
                                currentCoordinates.Column--;
                                lastDirection = Direction.Left;
                                break;
                            case Direction.Left:
                                currentCoordinates.Row--;
                                lastDirection = Direction.Up;
                                break;
                            default:
                                throw new InvalidOperationException();
                        }
                        break;
                    default:
                        throw new InvalidOperationException();
                }
            }

            return true;
        }

        static Direction GetNextDirection(Direction direction)
        {
            switch (direction)
            {
                case Direction.Right:
                    return Direction.Down;
                case Direction.Down:
                    return Direction.Left;
                case Direction.Left:
                    return Direction.Up;
                case Direction.Up:
                    return Direction.Right;
                default:
                    throw new ArgumentException();
            }
        }

        enum Direction
        {
            Right,
            Down,
            Left,
            Up
        }

        static bool AreAdjunced(Tuple<int, int> loverPair, List<int> courtiersLeft)
        {
            var firstIndex = courtiersLeft.IndexOf(loverPair.Item1);
            if ((firstIndex == 0) && (courtiersLeft[courtiersLeft.Count - 1] == loverPair.Item2))
                return true;
            if ((firstIndex == courtiersLeft.Count - 1) && (courtiersLeft[0] == loverPair.Item2))
                return true;
            if ((firstIndex > 0) && (courtiersLeft[firstIndex - 1] == loverPair.Item2))
                return true;
            if ((firstIndex < courtiersLeft.Count - 1) && (courtiersLeft[firstIndex + 1] == loverPair.Item2))
                return true;
            return false;
        }

        static bool IsClockwise(Tuple<int, int> loverPair, List<int> courtiersLeft)
        {
            var firstIndex = courtiersLeft.IndexOf(loverPair.Item1);
            if ((firstIndex == courtiersLeft.Count - 1) && (courtiersLeft[0] == loverPair.Item2))
                return true;
            if ((firstIndex < courtiersLeft.Count - 1) && (courtiersLeft[firstIndex + 1] == loverPair.Item2))
                return true;
            return false;
        }

        static Coordinates GetCourtierCoordinates(int courtier, Case theCase)
        {
            if (courtier <= theCase.ColumnCount)
                return new Coordinates
                {
                    Row = -1,
                    Column = courtier - 1
                };
            if (courtier <= theCase.ColumnCount + theCase.RowCount)
                return new Coordinates
                {
                    Row = courtier - theCase.ColumnCount - 1,
                    Column = theCase.ColumnCount
                };
            if (courtier <= theCase.ColumnCount * 2 + theCase.RowCount)
                return new Coordinates
                {
                    Row = theCase.RowCount,
                    Column = theCase.ColumnCount * 2 + theCase.RowCount - courtier
                };
            return new Coordinates
            {
                Row = theCase.ColumnCount * 2 + theCase.RowCount * 2 - courtier,
                Column = -1
            };
        }

        class Coordinates
        {
            public static bool operator==(Coordinates a, Coordinates b)
            {
                return (a.Row == b.Row) && (a.Column == b.Column);
            }

            public static bool operator!=(Coordinates a, Coordinates b)
            {
                return !(a == b);
            }

            public int Row;
            public int Column;

            public override bool Equals(object obj)
            {
                return (obj is Coordinates) && (this == (Coordinates)obj);
            }

            public override int GetHashCode()
            {
                return 0;
            }
        }

        static void WriteSolution(Solution solution)
        {
            if (solution.Maze == null)
            {
                Console.WriteLine("IMPOSSIBLE");
            }
            else
            {
                foreach (var line in solution.Maze)
                    Console.WriteLine(line);
            }
        }

        class Case
        {
            public int RowCount;
            public int ColumnCount;
            public Tuple<int, int>[] Lovers;
        }

        class Solution
        {
            public string[] Maze;
        }
    }
}
