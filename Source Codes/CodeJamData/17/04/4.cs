using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;
using System.Text;

namespace ProblemD
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
            var stageSideSize = values[0];
            var theCase = new Case
            {
                Stage = new Stage
                {
                    ModelRows = Enumerable.Range(0, stageSideSize)
                    .Select(_ => new StringBuilder(new string('.', stageSideSize)))
                    .ToList()
                }
            };
            var initialModelCount = values[1];
            for (var initialModelIndex = 0; initialModelIndex < initialModelCount; initialModelIndex++)
            {
                var modelLine = Console.ReadLine().Split(' ');
                var model = modelLine[0].Single();
                var rowNumber = int.Parse(modelLine[1]);
                var columnNumber = int.Parse(modelLine[2]);
                theCase.Stage.ModelRows[rowNumber - 1][columnNumber - 1] = model;
            }
            return theCase;
        }

        static Solution SolveCase(Case theCase)
        {
            var sideSize = theCase.Stage.SideSize;
            var areRowsRestricted = new bool[sideSize];
            var areColumnsRestricted = new bool[sideSize];
            var diagonalCount = 2 * sideSize - 1;
            var areMainDirectionDiagonalsRestricted = new bool[diagonalCount];
            var areAlternativeDirectionDiagonalsRestricted = new bool[diagonalCount];
            var stage = theCase.Stage.Clone();
            var changes = new List<StageCell>();

            void UpdateRestrictions(int rowIndex, int columnIndex, char model)
            {
                if (model != '.')
                {
                    if (model != '+')
                    {
                        areRowsRestricted[rowIndex] = true;
                        areColumnsRestricted[columnIndex] = true;
                    }

                    if (model != 'x')
                    {
                        var mainDirectionDiagonalIndex = GetMainDirectionDiagonalIndex(rowIndex, columnIndex, sideSize);
                        areMainDirectionDiagonalsRestricted[mainDirectionDiagonalIndex] = true;
                        var alternativeDirectionDiagonalIndex = GetAlternativeDirectionDiagonalIndex(rowIndex, columnIndex);
                        areAlternativeDirectionDiagonalsRestricted[alternativeDirectionDiagonalIndex] = true;
                    }
                }
            }

            for (var rowIndex = 0; rowIndex < sideSize; rowIndex++)
                for (var columnIndex = 0; columnIndex < sideSize; columnIndex++)
                    UpdateRestrictions(rowIndex, columnIndex, stage.ModelRows[rowIndex][columnIndex]);

            void AddChange(int rowIndex, int columnIndex, char model)
            {
                changes.Add(new StageCell
                {
                    RowNumber = rowIndex + 1,
                    ColumnNumber = columnIndex + 1,
                    Model = model
                });
                stage.ModelRows[rowIndex][columnIndex] = model;
                UpdateRestrictions(rowIndex, columnIndex, model);
            }

            void TryImprove(int rowIndex, int columnIndex)
            {
                var model = stage.ModelRows[rowIndex][columnIndex];
                var isRowRestricted = areRowsRestricted[rowIndex];
                var isColumnRestricted = areColumnsRestricted[columnIndex];
                var mainDirectionDiagonalIndex = GetMainDirectionDiagonalIndex(rowIndex, columnIndex, sideSize);
                var isMainDirectionDiagonalRestricted = areMainDirectionDiagonalsRestricted[mainDirectionDiagonalIndex];
                var alternativeDirectionDiagonalIndex = GetAlternativeDirectionDiagonalIndex(rowIndex, columnIndex);
                var isAlternativeDirectionDiagonalRestricted =
                    areAlternativeDirectionDiagonalsRestricted[alternativeDirectionDiagonalIndex];

                if (model == '.')
                {
                    if (!isRowRestricted && !isColumnRestricted)
                    {
                        if (!isMainDirectionDiagonalRestricted && !isAlternativeDirectionDiagonalRestricted)
                        {
                            AddChange(rowIndex, columnIndex, 'o');
                        }
                        else
                        {
                            AddChange(rowIndex, columnIndex, 'x');
                        }
                    }
                    else if (!isMainDirectionDiagonalRestricted && !isAlternativeDirectionDiagonalRestricted)
                    {
                        AddChange(rowIndex, columnIndex, '+');
                    }
                }

                if ((model == '+') && !isRowRestricted && !isColumnRestricted)
                {
                    AddChange(rowIndex, columnIndex, 'o');
                }

                if ((model == 'x') && !isMainDirectionDiagonalRestricted && !isAlternativeDirectionDiagonalRestricted)
                {
                    AddChange(rowIndex, columnIndex, 'o');
                }
            }

            var circleCount = (sideSize + 1) / 2;
            for (var circleIndex = 0; circleIndex < circleCount; circleIndex++)
            {
                for (var columnIndex = circleIndex; columnIndex < sideSize - circleIndex; columnIndex++)
                {
                    TryImprove(circleIndex, columnIndex);
                    TryImprove(sideSize - circleIndex - 1, columnIndex);
                }

                for (var rowIndex = circleIndex + 1; rowIndex < sideSize - circleIndex - 1; rowIndex++)
                {
                    TryImprove(rowIndex, circleIndex);
                    TryImprove(rowIndex, sideSize - circleIndex - 1);
                }
            }

            return new Solution
            {
                Changes = changes,
                StylePointCount = stage.ModelRows.SelectMany(row => row.ToString()).Sum(model =>
                {
                    switch (model)
                    {
                        case '+':
                        case 'x':
                            return 1;

                        case 'o':
                            return 2;

                        default:
                            return 0;
                    }
                })
            };
        }

        private static int GetAlternativeDirectionDiagonalIndex(int rowIndex, int columnIndex)
        {
            return rowIndex + columnIndex;
        }

        private static int GetMainDirectionDiagonalIndex(int rowIndex, int columnIndex, int sideSize)
        {
            return rowIndex - columnIndex + sideSize - 1;
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine($"{solution.StylePointCount} {solution.Changes.Count}");
            foreach (var change in solution.Changes)
                Console.WriteLine($"{change.Model} {change.RowNumber} {change.ColumnNumber}");
        }

        class Case
        {
            public Stage Stage;
        }

        class Stage
        {
            public int SideSize => ModelRows.Count;
            public IReadOnlyList<StringBuilder> ModelRows;
            public override string ToString() => string.Concat(Environment.NewLine, ModelRows);
            public Stage Clone() => new Stage
            {
                ModelRows = ModelRows.Select(row => new StringBuilder(row.ToString())).ToList()
            };
        }

        class Solution
        {
            public int StylePointCount;
            public IReadOnlyCollection<StageCell> Changes;
        }

        struct StageCell
        {
            public int RowNumber;
            public int ColumnNumber;
            public char Model;
        }
    }
}
