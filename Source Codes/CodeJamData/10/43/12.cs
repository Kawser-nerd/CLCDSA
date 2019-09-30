using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int NUM = int.Parse(sr.ReadLine().Trim());
                    for (int i = 0; i < NUM; ++i)
                    {
                        int r = int.Parse(sr.ReadLine().Trim());
                        bool[,] map = new bool[100, 100];
                        for (int j = 0; j < r; ++j)
                        {
                            string[] strs = sr.ReadLine().Trim().Split(' ');
                            int x1 = int.Parse(strs[0]), y1 = int.Parse(strs[1]), x2 = int.Parse(strs[2]), y2 = int.Parse(strs[3]);
                            for (int x = Math.Min(x1, x2); x <= Math.Max(x1, x2); ++x)
                            {
                                for (int y = Math.Min(y1, y2); y <= Math.Max(y1, y2); ++y)
                                {
                                    map[y - 1, x - 1] = true;
                                }
                            }
                        }

                        int res = 0;
                        while (true)
                        {
                            bool[,] map2 = new bool[100, 100];
                            bool live = false;
                            ++res;
                            for (int x = 0; x < 100; ++x)
                            {
                                for (int y = 0; y < 100; ++y)
                                {
                                    int nx = x - 1, ny = y - 1;
                                    if (map[y, x] && (nx < 0 || !map[y, nx]) && (ny < 0 || !map[ny, x]))
                                    {
                                        map2[y, x] = false;
                                    }
                                    else if (!map[y, x] && (nx >= 0 && map[y, nx]) && (ny >= 0 && map[ny, x]))
                                    {
                                        map2[y, x] = true;
                                    }
                                    else
                                    {
                                        map2[y, x] = map[y, x];
                                    }
                                    if (map2[y, x]) { live = true; }
                                }
                            }
                            if (!live) break;
                            map = map2;
                        }

                        string rstr = "Case #" + (i + 1) + ": " + res;
                        Console.WriteLine(rstr);
                        sw.WriteLine(rstr);
                    }

                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }
    }
}
