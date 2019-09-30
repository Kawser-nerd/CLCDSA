using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace B
{
    class Input
    {
        public int NumberOfIngredients { get; set; }
        public int NumberOfPackages { get; set; }
        public int[] Recipe { get; set; }
        public IList<int>[] Packages { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var path = args[0];
            var testCases = ParseInput(path);
            var caseNo = 1;

            using (var stream = new FileStream($"{path}.out", FileMode.Create))
            {
                using (var sw = new StreamWriter(stream))
                {
                    foreach (var testCase in testCases)
                    {
                        var result = Solve(testCase);
                        Console.WriteLine($"Case #{caseNo}: {result}");
                        sw.WriteLine($"Case #{caseNo}: {result}");
                        caseNo++;
                    }
                }
            }
        }

        private static IList<Input> ParseInput(string path)
        {
            using (var stream = new FileStream($"{path}.in", FileMode.Open))
            {
                using (var sr = new StreamReader(stream))
                {
                    var count = int.Parse(sr.ReadLine());
                    var testCases = new List<Input>(count);
                    while (count-- > 0)
                    {
                        var line = sr.ReadLine().Split(' ');
                        var N = int.Parse(line[0]);
                        var P = int.Parse(line[0]);

                        line = sr.ReadLine().Split(' ');
                        var recipe = new int[N];
                        for (var i = 0; i < N; ++i)
                        {
                            recipe[i] = int.Parse(line[i]);
                        }

                        var packages = new List<int>[P];
                        for (var i = 0; i < N; ++i)
                        {
                            line = sr.ReadLine().Split(' ');
                            packages[i] = new List<int>();
                            foreach (var package in line)
                            {
                                packages[i].Add(int.Parse(package));
                            }

                            packages[i].Sort();
                        }

                        testCases.Add(new Input { NumberOfIngredients = N, NumberOfPackages = P, Recipe = recipe, Packages = packages });
                    }
                    return testCases;
                }
            }
        }

        private static int Solve(Input input)
        {
            var result = 0;
            var servings = (int)Math.Floor((double)input.Packages[0].First() / input.Recipe[0]) / 2;
            var maxNumberofServings = (int)Math.Ceiling((double)input.Packages[0].Last() / input.Recipe[0]) * 2;

            Console.WriteLine("Servings:" + servings);
            Console.WriteLine("maxNumberofServings:" + maxNumberofServings);

            while (servings <= maxNumberofServings)
            {
                var recipe = GetRecipe(servings, input.Recipe);
                var possible = true;
                while (possible)
                {
                    var packages = new int[input.NumberOfIngredients];
                    for (var i = 0; i < input.Packages.Length; ++i)
                    {
                        try
                        {
                            packages[i] = input.Packages[i].First((package) => (Math.Abs(package - recipe[i]) * 10) <= recipe[i]);
                        }
                        catch
                        {
                            possible = false;
                            break;
                        }
                    }

                    if (possible)
                    {
                        for (var i = 0; i < input.Packages.Length; ++i)
                        {
                            input.Packages[i].Remove(packages[i]);
                        }
                        result++;
                    }
                }
                servings++;
            }
            return result;
        }

        private static int[] GetRecipe(int servings, int[] recipe)
        {
            var result = new int[recipe.Length];
            for (var i = 0; i < recipe.Length; ++i)
            {
                result[i] = recipe[i] * servings;
            }
            return result;
        }
    }
}
