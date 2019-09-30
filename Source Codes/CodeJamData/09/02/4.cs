using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09QRQ2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                int height = int.Parse(bits[0]);
                int width = int.Parse(bits[1]);
                index++;
                int[,] map = new int[height, width];
                for (int j = 0; j < height; j++)
                {
                    string[] spots = lines[index].Split(' ');
                    for (int k = 0; k < width; k++)
                    {

                        map[j, k] = int.Parse(spots[k]);
                    }
                    index++;
                }
                output.Add(string.Format("Case #{0}:", i + 1));
                output.AddRange(Solve(height, width, map));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static IEnumerable<string> Solve(int height, int width, int[,] map)
        {
            int[,] basins = new int[height, width];
            int basin = 1;
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (IsSink(map, i, j, height, width))
                    {
                        Queue<KeyValuePair<int, int>> locs = new Queue<KeyValuePair<int, int>>();
                        locs.Enqueue(new KeyValuePair<int, int>(i, j));
                        while (locs.Count > 0)
                        {
                            KeyValuePair<int, int> spot = locs.Dequeue();
                            basins[spot.Key, spot.Value] = basin;
                            if (spot.Key > 0 && basins[spot.Key - 1, spot.Value] == 0 && FlowsTo(map, spot.Key - 1, spot.Value, spot.Key, spot.Value, height, width))
                            {
                                locs.Enqueue(new KeyValuePair<int, int>(spot.Key - 1, spot.Value));
                            }
                            if (spot.Key < height - 1 && basins[spot.Key + 1, spot.Value] == 0 && FlowsTo(map, spot.Key + 1, spot.Value, spot.Key, spot.Value, height, width))
                            {
                                locs.Enqueue(new KeyValuePair<int, int>(spot.Key + 1, spot.Value));
                            }
                            if (spot.Value > 0 && basins[spot.Key, spot.Value - 1] == 0 && FlowsTo(map, spot.Key, spot.Value - 1, spot.Key, spot.Value, height, width))
                            {
                                locs.Enqueue(new KeyValuePair<int, int>(spot.Key, spot.Value - 1));
                            }
                            if (spot.Value < width - 1 && basins[spot.Key, spot.Value + 1] == 0 && FlowsTo(map, spot.Key, spot.Value + 1, spot.Key, spot.Value, height, width))
                            {
                                locs.Enqueue(new KeyValuePair<int, int>(spot.Key, spot.Value + 1));
                            }
                        }
                        basin++;
                    }
                }
            }
            List<string[]> results = new List<string[]>();
            for (int i = 0; i < height; i++)
            {
                results.Add(new string[width]);
            }
            char current = 'a';
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (results[i][j] == null)
                    {
                        int target = basins[i, j];
                        for (int k = 0; k < height; k++)
                        {
                            for (int l = 0; l < width; l++)
                            {
                                if (basins[k, l] == target)
                                {
                                    results[k][l] = "" + current;
                                }
                            }
                        }
                        current++;
                    }
                }
            }
            List<string> realResults = new List<string>();
            for (int i = 0; i < height; i++)
            {
                realResults.Add(string.Join(" ", results[i]));
            }

            return realResults;
        }

        private static bool FlowsTo(int[,] map, int sourceY, int sourceX, int targetY, int targetX, int height, int width)
        {
            int finalX = -1;
            int finalY = -1;
            int best = map[sourceY, sourceX];
            if (sourceY > 0 && map[sourceY - 1, sourceX] < best)
            {
                best = map[sourceY - 1, sourceX];
                finalX = sourceX;
                finalY = sourceY - 1;
            }
            if (sourceX > 0 && map[sourceY, sourceX - 1] < best)
            {
                best = map[sourceY, sourceX - 1];
                finalX = sourceX - 1;
                finalY = sourceY;
            }
            if (sourceX < width - 1 && map[sourceY, sourceX + 1] < best)
            {
                best = map[sourceY, sourceX+1];
                finalX = sourceX + 1;
                finalY = sourceY;
            }
            if (sourceY < height - 1 && map[sourceY + 1, sourceX] < best)
            {
                best = map[sourceY + 1, sourceX];
                finalX = sourceX;
                finalY = sourceY + 1;
            }
            return finalX==targetX && finalY==targetY;
        }

        private static bool IsSink(int[,] map, int i, int j, int height, int width)
        {
            if (i > 0 && map[i - 1, j] < map[i,j])
            {
                return false;
            }
            if (i < height - 1 && map[i + 1, j] < map[i, j])
            {
                return false;
            }
            if (j > 0 && map[i, j - 1] < map[i, j])
            {
                return false;
            }
            if (j < width - 1 && map[i, j + 1] < map[i, j])
            {
                return false;
            }
            return true;
        }
    }
}
