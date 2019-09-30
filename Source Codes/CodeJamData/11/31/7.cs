using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "../A-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] str = sr.ReadLine().Split(' ');
                int R = int.Parse(str[0]);
                int C = int.Parse(str[1]);
                char[][] tiles = new char[R][];
                for (int j = 0; j < R; j++)
                {
                    tiles[j] = sr.ReadLine().ToCharArray();
                }
                sw.WriteLine(string.Format("Case #{0}:", i));
                if (Replace(ref tiles))
                {
                    foreach (var tile in tiles) sw.WriteLine(tile);
                }
                else sw.WriteLine("Impossible");
                Console.WriteLine(string.Format("Case #{0}: Done", i));
            }
            sw.Close();
            sr.Close();
        }
        static bool Replace(ref char[][] tiles)
        {
            int R = tiles.Length;
            int C = tiles[0].Length;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (tiles[i][j] == '#')
                    {
                        if (i + 1 >= R) return false;
                        if (j + 1 >= C) return false;
                        if (tiles[i][j + 1] != '#') return false;
                        if (tiles[i + 1][j] != '#') return false;
                        if (tiles[i + 1][j + 1] != '#') return false;
                        tiles[i][j] = '/';
                        tiles[i][j + 1] = '\\';
                        tiles[i + 1][j] = '\\';
                        tiles[i + 1][j + 1] = '/';
                    }
                }
            }
            return true;
        }
    }
}
