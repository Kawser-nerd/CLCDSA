using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var squareSize = int.Parse(Console.ReadLine());
                var knownPieceCount = 2 * squareSize - 1;
                var knownPieces = new List<int[]>(knownPieceCount);
                for (var pieceIndex = 0; pieceIndex < knownPieceCount; pieceIndex++)
                {
                    var line = Console.ReadLine();
                    var piece = line.Split(' ').Select(item => int.Parse(item)).ToArray();
                    knownPieces.Add(piece);
                }

                var lines = new int[squareSize][];
                var columns = new int[squareSize][];
                var knownPiecesLeft = knownPieces.ToList();

                var firstLine = knownPieces.OrderBy(piece => piece[0]).First();
                knownPiecesLeft.Remove(firstLine);
                lines[0] = firstLine;

                var solution = TrySolve(lines, columns, knownPiecesLeft, 0);

                Console.WriteLine("Case #{0}: {1}", caseNumber, string.Join(" ", solution));
            }
        }

        static int[] TrySolve(IList<int[]> lines, IList<int[]> columns, IList<int[]> knownPiecesLeft, int knownPieceIndex)
        {
            return TrySolveAsColumn(lines, columns, knownPiecesLeft, knownPieceIndex) ??
                TrySolveAsLine(lines, columns, knownPiecesLeft, knownPieceIndex);
        }

        static int[] TrySolveAsLine(IList<int[]> lines, IList<int[]> columns, IList<int[]> knownPiecesLeft, int knownPieceIndex)
        {
            if (knownPieceIndex == knownPiecesLeft.Count)
            {
                return TryGetResultingLine(lines, columns) ?? TryGetResultingColumn(lines, columns);
            }

            var line = knownPiecesLeft[knownPieceIndex];
            for (var lineIndex = 0; lineIndex < lines.Count; lineIndex++)
            {
                if (CanBeLine(lines, columns, line, lineIndex))
                {
                    var newLines = lines.ToList();
                    newLines[lineIndex] = line;
                    var result = TrySolve(newLines, columns, knownPiecesLeft, knownPieceIndex + 1);
                    if (result != null)
                        return result;
                }
            }

            return null;
        }

        static int[] TrySolveAsColumn(IList<int[]> lines, IList<int[]> columns, IList<int[]> knownPiecesLeft,
            int knownPieceIndex)
        {
            return TrySolveAsLine(columns, lines, knownPiecesLeft, knownPieceIndex);
        }

        static bool CanBeLine(IList<int[]> lines, IList<int[]> columns, int[] line, int lineIndex)
        {
            if (lines[lineIndex] != null)
                return false;

            for (var columnIndex = 0; columnIndex < line.Length; columnIndex++)
            {
                if ((columns[columnIndex] != null) && (columns[columnIndex][lineIndex] != line[columnIndex]))
                    return false;
            }

            return true;
        }

        static int[] TryGetResultingLine(IList<int[]> lines, IList<int[]> columns)
        {
            for (var lineIndex = 0; lineIndex < lines.Count; lineIndex++)
            {
                if (lines[lineIndex] == null)
                {
                    var result = new int[columns.Count];
                    for (var columnIndex = 0; columnIndex < columns.Count; columnIndex++)
                        result[columnIndex] = columns[columnIndex][lineIndex];
                    return result;
                }
            }

            return null;
        }

        static int[] TryGetResultingColumn(IList<int[]> lines, IList<int[]> columns)
        {
            return TryGetResultingLine(columns, lines);
        }
    }
}
