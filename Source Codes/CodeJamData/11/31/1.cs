using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Square_Tiles {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int R = Convert.ToInt32(lines[0]);
            int C = Convert.ToInt32(lines[1]);
            char[,] map = new char[R, C];
            int count = 0;
            for (int i = 0; i < R; i++) {
                string l = sr.ReadLine();
                for (int j = 0; j < C; j++) {
                    map[i, j] = l[j];
                    if (l[j] == '#')
                        count++;
                }
            }
            sw.WriteLine();
            if (!solve(map, R, C))
                sw.WriteLine("Impossible");
            else
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++)
                        sw.Write(map[i, j]);
                    sw.WriteLine();
                }
        }
        private bool solve(char[,] map, int r, int c) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (map[i, j] == '#') {
                        map[i, j] = '/';
                        if (j + 1 >= c || i + 1 >= r)
                            return false;
                        if (map[i, j + 1] != '#' || map[i + 1, j] != '#' || map[i + 1, j + 1] != '#')
                            return false;
                        map[i, j + 1] = '\\';
                        map[i + 1, j] = '\\';
                        map[i + 1, j + 1] = '/';
                    }
            return true;
        }
    }
}
