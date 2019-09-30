using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B {

    

    class Program {

        char[][] cave;
        int[][] visited;

        int cols, rows;
        int falls;

        public string RemoveSpaces(string s) {
            s = s.Trim();
            while (s.IndexOf("  ") >= 0) {
                s = s.Replace("  ", " ");
            }
            return s;
        }

        public void Load(string fileName) {
            StreamReader r = new StreamReader(fileName);
            StreamWriter w = new StreamWriter(fileName.Replace(".in", ".out"));

            int n = int.Parse(RemoveSpaces(r.ReadLine()));

            for (int tc = 0; tc < n; tc++) {
                string line = RemoveSpaces(r.ReadLine());
                string[] items = line.Split(' ');
                rows = int.Parse(items[0]);
                cols = int.Parse(items[1]);
                falls = int.Parse(items[2]);

                visited = new int[rows][];
                cave = new char[rows][];               
                for (int i = 0; i < rows; i++) {
                    cave[i] = new char[cols];
                    string caveLine = RemoveSpaces(r.ReadLine());
                    for (int j = 0; j < cols; j++) {
                        cave[i][j] = caveLine[j];
                    }
                    visited[i] = new int[cols];
                }

                                
                int res = Solve();

                if (res != -1) {
                    w.WriteLine("Case #{0}: Yes {1}", tc + 1, res);
                } else {
                    w.WriteLine("Case #{0}: No", tc + 1);
                }
            }
            w.Close();
            r.Close();
        }

        public int Solve() {
            best = int.MaxValue;
            Solve(0, 0, 0, 0);
            if (best < int.MaxValue) {
                return best;
            }
            return -1;
        }

        int best;


        void Dump(int x, int y) {
            for(int j = 0; j < rows; j++) {
                for (int i = 0; i < cols; i++) {
                    if ((i != x) || (j != y)) {
                        Console.Write(cave[j][i]);
                    } else {
                        Console.Write("*");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public void Solve(int x, int y, int drills, int falls) {
            //Dump(x, y);
            if (falls > this.falls) {
                return;
            }
            if (drills >= best) {
                return;
            }
            if ((y < rows - 1) && (cave[y + 1][x] == '.')) {
                Solve(x, y + 1, drills, falls + 1);
                return;
            }

            if (y == rows - 1) {
                if (best > drills) {
                    best = drills;
                }
                return;
            }

            visited[y][x]++;



            if ((x > 0) && (cave[y][x - 1] == '.')) {
                if (visited[y][x - 1] == 0) {
                    Solve(x - 1, y, drills, 0);                    
                }
                if ((y < rows - 1) && (cave[y + 1][x - 1] == '#')) {                    
                    cave[y + 1][x - 1] = '.';                    
                    // drill & jump
                    Solve(x - 1, y + 1, drills+1, 1);

                    if ((x < cols-1) && (cave[y][x + 1] == '.')) {
                        Solve(x + 1, y, drills + 1, 0);
                    }

                    cave[y + 1][x - 1] = '#';
                }
                
                
            }
            if ((x < cols-1) && (cave[y][x + 1] == '.')) {
                if (visited[y][x + 1] == 0) {
                    Solve(x + 1, y, drills, 0);
                }
                if ((y < rows - 1) && (cave[y + 1][x + 1] == '#')) {
                    cave[y + 1][x + 1] = '.';
                    // drill & jump
                    Solve(x + 1, y+1, drills+1, 1);

                    if ((x > 0) && (cave[y][x - 1] == '.')) {
                        Solve(x-1, y, drills + 1, 0);
                    }
                    

                    cave[y + 1][x + 1] = '#';
                }
            }
            

            visited[y][x]--;            
        }

        static void Main(string[] args) {
            Program p = new Program();
            p.Load("B-small-attempt1.in");
        }
    }
}
