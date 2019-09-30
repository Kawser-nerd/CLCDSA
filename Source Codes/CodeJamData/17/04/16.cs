using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace Problem1D
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line1 = reader.ReadLine().Split(' ');
                    var dim = int.Parse(line1[0]);

                    var modelCount = int.Parse(line1[1]);

                    var models = new List<Model>();
                    for (var i = 0; i < modelCount; i++)
                    {
                        var modelLine = reader.ReadLine().Split(' ');
                        models.Add(
                            new Model
                            {
                                Type = modelLine[0][0],
                                X = int.Parse(modelLine[1]) - 1,
                                Y = int.Parse(modelLine[2]) - 1
                            });
                    }

                    int score;
                    var additionalModels = PlaceModels(dim, models, out score);

                    writer.WriteLine("Case #{0}: {1} {2}", caseId, score, additionalModels.Count);
                    foreach (var model in additionalModels)
                    {
                        writer.WriteLine($"{model.Type} {model.X + 1} {model.Y + 1}");
                    }
                    writer.Flush();
                }
            }
        }

        private static List<Model> PlaceModels(int size, List<Model> models, out int score)
        {
            score = 0;
            var newModels = new List<Model>();

            var placed = new char[size, size];

            var notPlus = new bool[size, size];
            var notX = new bool[size, size];

            foreach (var model in models)
            {
                if (model.Type != '+')
                {
                    PlaceX(size, notX, model.X, model.Y);
                    score++;
                }

                if (model.Type != 'x')
                {
                    PlacePlus(size, notPlus, model.X, model.Y);
                    score++;
                }

                placed[model.X, model.Y] = model.Type;
            }

            Console.WriteLine("--------");
            Console.WriteLine("In:");
            WriteGrid(placed);

            for (var ix = 0; ix < size; ix++)
            {
                var i = ix%2 > 0 ? ix/2: size-1-(ix/ 2);
                for (var j = 0; j < size; j++)
                {
                    var type = '\0';

                    if (!notX[i, j])
                    {
                        type = placed[i, j] == 0 ? 'x' : 'o';
                        placed[i, j] = type;
                        score++;
                        PlaceX(size, notX, i, j);
                    }

                    if (!notPlus[i, j])
                    {
                        type = placed[i, j] == 0 ? '+' : 'o';
                        placed[i, j] = type;
                        score++;
                        PlacePlus(size, notPlus, i, j);
                    }

                    if (type != '\0')
                    {
                        newModels.Add(new Model { Type = type, X = i, Y = j });
                    }
                }
            }

            Console.WriteLine("Out:");
            WriteGrid(placed);

            return newModels;
        }

        private static void WriteGrid(char[,] placed)
        {
            for (var i = 0; i < placed.GetLength(0); i++)
            {
                for (var j = 0; j < placed.GetLength(1); j++)
                {
                    Console.Write(placed[i,j]);
                }
                Console.WriteLine();
            }
        }

        private static void PlaceX(int size, bool[,] grid, int i, int j)
        {
            for (var x = 0; x < size; x++)
            {
                grid[x, j] = true;
                grid[i, x] = true;
            }
        }

        private static void PlacePlus(int size, bool[,] grid, int i, int j)
        {
            for (var x = 0; x < size; x++)
            {
                var newJ = (x - i) + j;
                if (newJ >= 0 && newJ < size)
                {
                    grid[x, newJ] = true;
                }

                newJ = (i - x) + j;
                if (newJ >= 0 && newJ < size)
                {
                    grid[x, newJ] = true;
                }
            }
        }

        public struct Model
        {
            public char Type;
            public int X;
            public int Y;
        }
    }
}
