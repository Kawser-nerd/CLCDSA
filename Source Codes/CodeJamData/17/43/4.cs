using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Round2ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = args[0];
            var outFile = Path.ChangeExtension(inFile, ".out");

            using (var reader = new StreamReader(inFile))
            using (var writer = new StreamWriter(outFile))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    int rows = line[0];
                    int columns = line[1];

                    var grid = new char[rows, columns];

                    for (var i = 0; i < rows; i++)
                    {
                        var gridLine = reader.ReadLine();
                        for (var j = 0; j < columns; j++)
                        {
                            grid[i, j] = gridLine[j];
                        }
                    }

                    var solved = SolveGrid(rows, columns, grid);

                    if (solved == null)
                    {
                        writer.WriteLine("Case #{0}: IMPOSSIBLE", caseId);
                    }
                    else
                    {
                        writer.WriteLine("Case #{0}: POSSIBLE", caseId);

                        for (int i = 0; i < rows; i++)
                        {
                            for (var j = 0; j < columns; j++)
                            {
                                writer.Write(solved[i, j]);
                            }
                            writer.WriteLine();
                        }
                    }

                    writer.Flush();
                }
            }
        }

        private static char[,] SolveGrid(int r, int c, char[,] grid)
        {
            int spaceCount = 0;
            int[,] spaceIds = new int[r, c];
            int[,] shooterIds = new int[r, c];
            List<Tuple<int, int>> shooterCoordinates = new List<Tuple<int, int>>();

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i, j] == '.')
                    {
                        spaceIds[i, j] = spaceCount++;
                    }
                    else
                    {
                        spaceIds[i, j] = -1;
                    }

                    if (grid[i, j] == '-' || grid[i, j] == '|')
                    {
                        shooterIds[i, j] = shooterCoordinates.Count;
                        shooterCoordinates.Add(Tuple.Create(i, j));
                    }
                    else
                    {
                        shooterIds[i, j] = -1;
                    }
                }
            }

            bool[][] shooterSpacesHorizontal = new bool[shooterCoordinates.Count][];
            bool[][] shooterSpacesVertical = new bool[shooterCoordinates.Count][];

            for (int i = 0; i < shooterCoordinates.Count; i++)
            {
                var shooterCoord = shooterCoordinates[i];

                var hSpaces = new bool[spaceCount];
                if (TraceSpaces(shooterCoord.Item1, shooterCoord.Item2, 0, -1, grid, spaceIds, hSpaces) &&
                    TraceSpaces(shooterCoord.Item1, shooterCoord.Item2, 0, 1, grid, spaceIds, hSpaces))
                {
                    shooterSpacesHorizontal[i] = hSpaces;
                }

                var vSpaces = new bool[spaceCount];
                if (TraceSpaces(shooterCoord.Item1, shooterCoord.Item2, -1, 0, grid, spaceIds, vSpaces) &&
                    TraceSpaces(shooterCoord.Item1, shooterCoord.Item2, 1, 0, grid, spaceIds, vSpaces))
                {
                    shooterSpacesVertical[i] = vSpaces;
                }
            }

            var all = new bool[spaceCount];
            for (var i=0; i<shooterCoordinates.Count; i++)
            {
                if (shooterSpacesHorizontal[i] == null && shooterSpacesVertical[i] == null)
                {
                    return null;
                }

                var h = shooterSpacesHorizontal[i];
                if (h != null)
                {
                    for (var j=0; j<h.Length; j++)
                    {
                        all[j] |= h[j];
                    }
                }

                var v = shooterSpacesVertical[i];
                if (v != null)
                {
                    for (var j = 0; j < v.Length; j++)
                    {
                        all[j] |= v[j];
                    }
                }
            }

            if (!all.All(x => x))
                return null;

            var b = new bool[spaceCount];
            return FindResult(grid, shooterSpacesHorizontal, shooterSpacesVertical, shooterCoordinates, 0, b);
        }

        private static char[,] FindResult(char[,] grid, bool[][] h, bool[][] v, List<Tuple<int, int>> c, int i, bool[] b)
        {
            if (i >= h.Length)
            {
                return b.All(x => x) ? grid : null;
            }

            if (h[i] == null && v[i] == null)
            {
                return null;
            }

            if (h[i] != null)
            {
                var newB = b.ToArray();
                grid[c[i].Item1, c[i].Item2] = '-';
                for (var j=0; j<h[i].Length; j++)
                {
                    newB[j] |= h[i][j];
                }

                var result = FindResult(grid, h, v, c, i + 1, newB);
                if (result != null)
                    return result;
            }

            if (v[i] != null)
            {
                var newB = b.ToArray();
                grid[c[i].Item1, c[i].Item2] = '|';
                for (var j = 0; j < v[i].Length; j++)
                {
                    newB[j] |= v[i][j];
                }

                var result = FindResult(grid, h, v, c, i + 1, newB);
                if (result != null)
                    return result;
            }

            return null;
        }

        private static bool TraceSpaces(int i, int j, int x, int y, char[,] grid, int[,] spaceIds, bool[] spaces)
        {
            while (true)
            {
                var nextI = i + x;
                var nextJ = j + y;
                if (nextI < 0 || nextI >= grid.GetLength(0))
                    return true;
                if (nextJ < 0 || nextJ >= grid.GetLength(1))
                    return true;

                i = nextI;
                j = nextJ;

                switch (grid[i, j])
                {
                    case '\\':
                        if (y == 0)
                        {
                            y = x;
                            x = 0;
                        }
                        else
                        {
                            x = -y;
                            y = 0;
                        }
                        break;

                    case '/':
                        if (y == 0)
                        {
                            y = -x;
                            x = 0;
                        }
                        else
                        {
                            x = y;
                            y = 0;
                        }
                        break;

                    case '#':
                        return true;

                    case '-':
                    case '|':
                        return false;

                    case '.':
                        spaces[spaceIds[i, j]] = true;
                        break;
                }
            }
        }
    }
}