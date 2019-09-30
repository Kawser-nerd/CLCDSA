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
                Console.Write("Case #{0}: ", caseNumber);
                WriteSolution(solutions[caseNumber - 1]);
            }
        }

        static Case ReadCase()
        {
            var values = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var rowCount = values[0];
            var columnCount = values[1];
            var rows = new string[rowCount];
            for (var rowIndex = 0; rowIndex < rowCount; rowIndex++)
                rows[rowIndex] = Console.ReadLine();
            return new Case
            {
                Rows = rows
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var emptyCells = new List<(int rowIndex, int columnIndex)>();
            var beamShooters = new List<BeamShooter>();

            for (var rowIndex = 0; rowIndex < theCase.Rows.Length; rowIndex++)
            {
                for (var columnIndex = 0; columnIndex < theCase.Rows[0].Length; columnIndex++)
                {
                    switch (theCase.Rows[rowIndex][columnIndex])
                    {
                        case '|':
                        case '-':
                            var beamShooter = TraceBeamShooter(rowIndex, columnIndex, theCase.Rows);
                            if ((beamShooter.HorizontalEmptyCells == null) && (beamShooter.VerticalEmptyCells == null))
                                return new Solution();
                            beamShooters.Add(beamShooter);
                            break;

                        case '.':
                            emptyCells.Add((rowIndex, columnIndex));
                            break;
                    }
                }
            }

            var emptyCellsLeft = new HashSet<(int rowIndex, int columnIndex)>(emptyCells);
            var beamShootersLeft = new List<BeamShooter>(beamShooters);
            var resultRows = theCase.Rows.Select(row => new StringBuilder(row)).ToArray();

            foreach (var beamShooter in beamShooters)
            {
                if (beamShooter.HorizontalEmptyCells == null)
                {
                    MakeBeamShooterVertical(emptyCellsLeft, beamShootersLeft, resultRows, beamShooter);
                }

                if (beamShooter.VerticalEmptyCells == null)
                {
                    MakeBeamShooterHorizontal(emptyCellsLeft, beamShootersLeft, resultRows, beamShooter);
                }
            }

            return SolveIf(emptyCellsLeft, beamShootersLeft, resultRows);
        }

        private static void MakeBeamShooterHorizontal(HashSet<(int rowIndex, int columnIndex)> emptyCellsLeft, List<BeamShooter> beamShootersLeft, StringBuilder[] resultRows, BeamShooter beamShooter)
        {
            resultRows[beamShooter.RowIndex][beamShooter.ColumnIndex] = '-';
            beamShootersLeft.Remove(beamShooter);
            foreach (var emptyCell in beamShooter.HorizontalEmptyCells)
                emptyCellsLeft.Remove(emptyCell);
        }

        private static void MakeBeamShooterVertical(HashSet<(int rowIndex, int columnIndex)> emptyCellsLeft, List<BeamShooter> beamShootersLeft, StringBuilder[] resultRows, BeamShooter beamShooter)
        {
            resultRows[beamShooter.RowIndex][beamShooter.ColumnIndex] = '|';
            beamShootersLeft.Remove(beamShooter);
            foreach (var emptyCell in beamShooter.VerticalEmptyCells)
                emptyCellsLeft.Remove(emptyCell);
        }

        static Solution SolveIf(HashSet<(int rowIndex, int columnIndex)> emptyCellsLeft,
            List<BeamShooter> beamShootersLeft, StringBuilder[] resultRows)
        {
            while (true)
            {
                var hasChange = true;
                while (hasChange)
                {
                    hasChange = false;
                    foreach (var emptyCell in emptyCellsLeft.ToList())
                    {
                        if (emptyCellsLeft.Contains(emptyCell))
                        {
                            var horizontalBeamShooters = beamShootersLeft.Where(beamShooter => beamShooter.HorizontalEmptyCells.Contains(emptyCell)).ToList();
                            var verticalBeamShooters = beamShootersLeft.Where(beamShooter => beamShooter.VerticalEmptyCells.Contains(emptyCell)).ToList();
                            if (horizontalBeamShooters.Count + verticalBeamShooters.Count == 0)
                                return new Solution();
                            if ((horizontalBeamShooters.Count == 1) && (verticalBeamShooters.Count == 0))
                            {
                                MakeBeamShooterHorizontal(emptyCellsLeft, beamShootersLeft, resultRows, horizontalBeamShooters.Single());
                                hasChange = true;
                            }
                            if ((horizontalBeamShooters.Count == 0) && (verticalBeamShooters.Count == 1))
                            {
                                MakeBeamShooterVertical(emptyCellsLeft, beamShootersLeft, resultRows, verticalBeamShooters.Single());
                                hasChange = true;
                            }
                        }
                    }
                }

                if (!emptyCellsLeft.Any())
                {
                    var solution = new Solution
                    {
                        Rows = resultRows.Select(row => row.ToString()).ToArray()
                    };
                    return solution;
                }

                {
                    var emptyCell = emptyCellsLeft.First();
                    var horizontalBeamShooters = beamShootersLeft.Where(aBeamShooter => aBeamShooter.HorizontalEmptyCells.Contains(emptyCell)).ToList();
                    var verticalBeamShooters = beamShootersLeft.Where(aBeamShooter => aBeamShooter.VerticalEmptyCells.Contains(emptyCell)).ToList();
                    var beamShooter = horizontalBeamShooters.Concat(verticalBeamShooters).First();

                    {
                        var emptyCellsLeftCopy = new HashSet<(int rowIndex, int columnIndex)>(emptyCellsLeft);
                        var beamShootersLeftCopy = beamShootersLeft.ToList();
                        var resultRowsCopy = resultRows.Select(row => new StringBuilder(row.ToString())).ToArray();
                        MakeBeamShooterHorizontal(emptyCellsLeftCopy, beamShootersLeftCopy, resultRowsCopy, beamShooter);
                        var solution = SolveIf(emptyCellsLeftCopy, beamShootersLeftCopy, resultRowsCopy);
                        if (solution.Rows != null)
                            return solution;
                    }

                    MakeBeamShooterVertical(emptyCellsLeft, beamShootersLeft, resultRows, beamShooter);
                }
            }
        }

        static BeamShooter TraceBeamShooter(
            int rowIndex, int columnIndex, string[] rows)
        {
            var leftEmptyCells = TraceFrom(rowIndex, columnIndex, Direction.Left, rows);
            var rightEmptyCells = TraceFrom(rowIndex, columnIndex, Direction.Right, rows);
            var upEmptyCells = TraceFrom(rowIndex, columnIndex, Direction.Up, rows);
            var downEmptyCells = TraceFrom(rowIndex, columnIndex, Direction.Down, rows);
            var horizontalEmptyCells = (leftEmptyCells == null) || (rightEmptyCells == null) ? null : leftEmptyCells.Union(rightEmptyCells).ToList();
            var verticalEmptyCells = (upEmptyCells == null) || (downEmptyCells == null) ? null : upEmptyCells.Union(downEmptyCells).ToList();
            return new BeamShooter
            {
                RowIndex = rowIndex,
                ColumnIndex = columnIndex,
                HorizontalEmptyCells = horizontalEmptyCells,
                VerticalEmptyCells = verticalEmptyCells
            };
        }

        static List<(int rowIndex, int columnIndex)> TraceFrom(int rowIndex, int columnIndex, Direction direction, string[] rows)
        {
            var emptyCells = new List<(int rowIndex, int columnIndex)>();
            var nextPosition = GetPositionInDirection(rowIndex, columnIndex, direction, rows);
            while (nextPosition != null)
            {
                switch (rows[nextPosition.Value.rowIndex][nextPosition.Value.columnIndex])
                {
                    case '|':
                    case '-':
                        return null;

                    case '#':
                        return emptyCells;

                    case '.':
                        emptyCells.Add((nextPosition.Value.rowIndex, nextPosition.Value.columnIndex));
                        nextPosition = GetPositionInDirection(nextPosition.Value.rowIndex, nextPosition.Value.columnIndex, direction, rows);
                        break;

                    case '/':
                        direction = MirrorRightUp(direction);
                        nextPosition = GetPositionInDirection(nextPosition.Value.rowIndex, nextPosition.Value.columnIndex, direction, rows);
                        break;

                    case '\\':
                        direction = MirrorRightDown(direction);
                        nextPosition = GetPositionInDirection(nextPosition.Value.rowIndex, nextPosition.Value.columnIndex, direction, rows);
                        break;

                    default:
                        throw new InvalidOperationException();
                }
            }
            return emptyCells;
        }

        static (int rowIndex, int columnIndex)? GetPositionInDirection(int rowIndex, int columnIndex, Direction direction, string[] rows)
        {
            switch (direction)
            {
                case Direction.Down:
                    if (rowIndex + 1 < rows.Length)
                        return (rowIndex + 1, columnIndex);
                    return null;

                case Direction.Up:
                    if (rowIndex > 0)
                        return (rowIndex - 1, columnIndex);
                    return null;

                case Direction.Left:
                    if (columnIndex > 0)
                        return (rowIndex, columnIndex - 1);
                    return null;

                case Direction.Right:
                    if (columnIndex + 1 < rows[0].Length)
                        return (rowIndex, columnIndex + 1);
                    return null;

                default:
                    throw new InvalidOperationException();
            }
        }

        static Direction MirrorRightUp(Direction direction)
        {
            switch (direction)
            {
                case Direction.Right:
                    return Direction.Up;

                case Direction.Up:
                    return Direction.Right;

                case Direction.Left:
                    return Direction.Down;

                case Direction.Down:
                    return Direction.Left;

                default:
                    throw new NotImplementedException();
            }
        }

        static Direction MirrorRightDown(Direction direction)
        {
            switch (direction)
            {
                case Direction.Right:
                    return Direction.Down;

                case Direction.Down:
                    return Direction.Right;

                case Direction.Left:
                    return Direction.Up;

                case Direction.Up:
                    return Direction.Left;

                default:
                    throw new NotImplementedException();
            }
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.Rows == null ? "IMPOSSIBLE" : "POSSIBLE");
            if (solution.Rows != null)
            {
                foreach (var row in solution.Rows)
                    Console.WriteLine(row);
            }
        }

        class Case
        {
            public string[] Rows;
        }

        class Solution
        {
            public string[] Rows;
        }

        enum Direction
        {
            Left, 
            Right,
            Up,
            Down
        }

        class BeamShooter
        {
            public int RowIndex;
            public int ColumnIndex;
            public List<(int rowIndex, int columnIndex)> HorizontalEmptyCells;
            public List<(int rowIndex, int columnIndex)> VerticalEmptyCells;
        }
    }
}
