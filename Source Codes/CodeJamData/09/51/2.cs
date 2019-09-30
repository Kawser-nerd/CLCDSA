using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static int[] dr = new int[4] { -1, 0, 1, 0 };
        static int[] dc = new int[4] { 0, 1, 0, -1 };

        static long Normalize(long position, int count)
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    long ii = (position >> 8 * i) & 0xFF;
                    long jj = (position >> 8 * j) & 0xFF;
                    if (ii > jj)
                    {
                        position &= ~((0xFFL << 8 * i) | (0xFFL << 8 * j));
                        position |= (ii << 8 * j) | (jj << 8 * i);
                    }
                }
            }
            return position;
        }

        static int Dfs(long position, int count, int index, bool[] seen)
        {
            int result = 1;
            seen[index] = true;
            int row = (int)((position >> (8 * index + 4)) & 0xF);
            int col = (int)((position >> (8 * index)) & 0xF);
            for (int i = 0; i < count; i++)
            {
                if (!seen[i])
                {
                    int r = (int)((position >> (8 * i + 4)) & 0xF);
                    int c = (int)((position >> (8 * i)) & 0xF);
                    for (int k = 0; k < 4; k++)
                    {
                        if (row + dr[k] == r && col + dc[k] == c)
                        {
                            result += Dfs(position, count, i, seen);
                        }
                    }
                }
            }
            return result;
        }

        static bool IsFree(string[] map, long position, int count, int row, int col)
        {
            if (map[row][col] == '#')
            {
                return false;
            }
            for (int j = 0; j < count; j++)
            {
                if (row == (int)((position >> (8 * j + 4)) & 0xF) &&
                    col == (int)((position >> (8 * j)) & 0xF))
                {
                    return false;
                }
            }
            return true;
        }

        static void MakeStep(string[] map, long position, int count, bool first,
            int distance, Queue<long> queue, Dictionary<long, int> dict)
        {
            for (int i = 0; i < count; i++)
            {
                int row = (int)((position >> (8 * i + 4)) & 0xF);
                int col = (int)((position >> (8 * i)) & 0xF);
                for (int k = 0; k < 4; k++)
                {
                    int r = row + dr[k];
                    int c = col + dc[k];
                    if (IsFree(map, position, count, r, c) &&
                        IsFree(map, position, count, row - dr[k], col - dc[k]))
                    {
                        long newpos = position & ~(0xFFL << 8 * i);
                        newpos |= (long)((r << 4) + c) << 8 * i;
                        if (Dfs(newpos, count, 0, new bool[count]) == count)
                        {
                            newpos = Normalize(newpos, count);
                            if (!dict.ContainsKey(newpos) || dict[newpos] > distance)
                            {
                                dict[newpos] = distance;
                                queue.Enqueue(newpos);
                            }
                        }
                        else if (first)
                        {
                            MakeStep(map, newpos, count, false, distance + 1, queue, dict);
                        }
                    }
                }
            }
        }

        static int Solve(string[] map)
        {
            long start = 0;
            int startCount = 0;
            long end = 0;
            int endCount = 0;
            for (int i = 0; i < map.Length; i++)
            {
                for (int j = 0; j < map[0].Length; j++)
                {
                    if (map[i][j] == 'o' || map[i][j] == 'w')
                    {
                        start |= (long)((i << 4) + j) << 8 * startCount;
                        startCount += 1;
                    }
                    if (map[i][j] == 'x' || map[i][j] == 'w')
                    {
                        end |= (long)((i << 4) + j) << 8 * endCount;
                        endCount += 1;
                    }
                }
            }

            Dictionary<long, int> dict = new Dictionary<long, int>();
            dict[start] = 0;
            Queue<long> queue = new Queue<long>();
            queue.Enqueue(start);
            while (queue.Count > 0)
            {
                long position = queue.Dequeue();
                int distance = dict[position];
                MakeStep(map, position, startCount, true, distance + 1, queue, dict);
            }

            return dict.ContainsKey(end) ? dict[end] : -1;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < T; i++)
                    {
                        string[] temp = reader.ReadLine().Split();
                        int R = Int32.Parse(temp[0]);
                        int C = Int32.Parse(temp[1]);
                        string[] map = new string[R + 2];
                        map[0] = map[R + 1] = new string('#', C + 2);
                        for (int j = 0; j < R; j++)
                        {
                            map[j + 1] = "#" + reader.ReadLine().Trim() + "#";
                        }
                        int answer = Solve(map);
                        writer.WriteLine("Case #" + (i + 1) + ": " + answer);
                    }
                }
            }
        }
    }
}
