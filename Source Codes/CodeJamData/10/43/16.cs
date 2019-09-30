using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemC
{
    class Program
    {
        static int Solve(bool[,] curr)
        {
            List<int> pos = new List<int>();
            for (int y = 0; y < curr.GetLength(0); y++)
            {
                for (int x = 0; x < curr.GetLength(1); x++)
                {
                    if (curr[y, x])
                    {
                        pos.Add(y);
                        pos.Add(x);
                    }
                }
            }

            int result = 0;
            while (pos.Count > 0)
            {
                int minx = 100;
                int miny = 100;
                for (int i = 0; i < pos.Count; i += 2)
                {
                    miny = Math.Min(miny, pos[i]);
                    minx = Math.Min(minx, pos[i + 1]);
                }

                miny -= 1;
                minx -= 1;
                for (int i = 0; i < pos.Count; i += 2)
                {
                    pos[i] -= miny;
                    pos[i + 1] -= minx;
                }

                curr = new bool[110, 110];
                for (int i = 0; i < pos.Count; i += 2)
                {
                    curr[pos[i], pos[i + 1]] = true;
                }

                List<int> next = new List<int>();
                for (int i = 0; i < pos.Count; i += 2)
                {
                    int y = pos[i];
                    int x = pos[i + 1];
                    if (curr[y - 1, x] || curr[y, x - 1])
                    {
                        next.Add(y);
                        next.Add(x);
                    }
                    if (!curr[y, x + 1] && curr[y - 1, x + 1])
                    {
                        next.Add(y);
                        next.Add(x + 1);
                    }
                }

                pos = next;
                result += 1;
            }

            return result;
        }

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
            {
                using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
                {
                    int total = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < total; i++)
                    {
                        bool[,] curr = new bool[110, 110];
                        int cnt = Int32.Parse(reader.ReadLine());
                        for (int j = 0; j < cnt; j++)
                        {
                            string[] temp = reader.ReadLine().Split();
                            int x1 = Int32.Parse(temp[0]);
                            int y1 = Int32.Parse(temp[1]);
                            int x2 = Int32.Parse(temp[2]);
                            int y2 = Int32.Parse(temp[3]);
                            for (int x = x1; x <= x2; x++)
                            {
                                for (int y = y1; y <= y2; y++)
                                {
                                    curr[y, x] = true;
                                }
                            }
                        }
                        int ans = Solve(curr);
                        writer.WriteLine("Case #" + (i + 1) + ": " + ans);
                    }
                }
            }
        }
    }
}
