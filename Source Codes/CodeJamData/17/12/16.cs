using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;

namespace CodeJam
{
    public class PercentileComparer : IComparer<int>
    {
        public static int BinarySearchIterative(List<int> inputArray, int key, int min, int max)
        {
            while (min <= max)
            {
                int mid = (min + max) / 2;
                if (key == inputArray[mid])
                {
                    return ++mid;
                }
                else if (key < inputArray[mid])
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid + 1;
                }
            }
            return -1;
        }

        public static bool WithinPercentile2(int b, int x)
        {
            if (x >= b * 0.9 && x <= b * 1.1)
                return true;

            return false;
        }

        public static bool WithinPercentile(int x, int y)
        {
            double xd = x;
            double yd = y;

            if (xd >= yd * 0.9 && xd <= yd * 1.1)
                return true;

            return false;
        }

        public int Compare(int x, int y)
        {
            if (WithinPercentile(x, y))
                return 0;

            return Comparer<int>.Default.Compare(x, y);
        }
    }

    class Program
    {
        private const string FileName = "B-large";
        
        static string Solve(int N, int P, int[] recipe, List<List<int>> quantities)
        {
            var percentileComparer = new PercentileComparer();

            int totalKits = 0;

            for (int i = 0; i < quantities.Count; i++)
                quantities[i].Sort();

            var baseComponentPackages = quantities[0];

            for (int bc = 0; bc < baseComponentPackages.Count; bc++)
            {
                int curr = baseComponentPackages[bc];

                int idealPackageCount = (int)Math.Round((double)curr / (double)recipe[0]);
                int ideal = recipe[0] * idealPackageCount;

                int low = (int)(ideal / 1.1 / recipe[0]);
                int high = (int)(ideal / 0.9 / recipe[0]) + 1;

                for (int packageCount = low; packageCount <= high; packageCount++)
                {
                    if (!PercentileComparer.WithinPercentile2(recipe[0] * packageCount, curr))
                        continue;

                    bool found = true;
                    int[] indicesToRemove = new int[quantities.Count];

                    indicesToRemove[0] = bc;
                    for (int q = 1; q < quantities.Count; q++)
                    {
                        int needeQuantity = packageCount * recipe[q];

                        int idx = -1;
                        for (int dd = 0; dd < quantities[q].Count; dd++)
                        {
                            if (PercentileComparer.WithinPercentile2(needeQuantity, quantities[q][dd]))
                            {
                                idx = dd;
                                break;
                            }
                        }
                        //   int idx = quantities[q].BinarySearch(needeQuantity, percentileComparer);

                        if (idx < 0)
                        {
                            found = false;
                            break;
                        }

                        indicesToRemove[q] = idx;
                    }

                    if (found)
                    {
                        for (int q = 0; q < quantities.Count; q++)
                        {
                            quantities[q].RemoveAt(indicesToRemove[q]);
                        }
                        bc--;
                        totalKits++;

                        break;
                    }
                }
            }

            return totalKits.ToString();
        }

        static void Main(string[] args)
        {
            var data = File.ReadAllLines($"D:\\!CodeJam\\2\\{FileName}.in").ToArray();

            List<string> result = new List<string>();

            int testCaseNumber = 1;
            for (int i = 1; i < data.Length; i++)
            {
                string[] tokens = data[i].Split(' ');
                int[] intTokens = tokens.Select(t => Int32.Parse(t)).ToArray();
                int N = intTokens[0];
                int P = intTokens[1];

                i++;
                string[] recipe = data[i].Split(' ');
                int[] recipeNumbers = recipe.Select(s => Int32.Parse(s)).ToArray();
                List<List<int>> quantities = new List<List<int>>();

                for (int j = 0; j < N; j++)
                {
                    i++;
                    var q = data[i].Split(' ').Select(s => Int32.Parse(s)).ToList();

                    quantities.Add(q);
                }

                result.Add($"Case #{testCaseNumber}: {Solve(N, P, recipeNumbers, quantities)}");

                testCaseNumber++;
            }

            File.WriteAllLines($"D:\\!CodeJam\\2\\{FileName}.out", result);
        }
    }
}
