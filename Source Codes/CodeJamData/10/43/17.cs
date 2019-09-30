using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ2010R2C {
    class Program {
        /*
        struct Box { 
            public int x1, y1, x2, y2;
            public Box(Box old) {
                x1 = old.x1; x2 = old.x2; y1 = old.y1; y2 = old.y2;
            }
        }
        private List<Box> Simulate(List<Box> old) {
            List<Box> result = new List<Box>();
            for (int i = 0; i < old.Count; ++i) {
                if (old[i].x1 == old[i].x2) continue;
                if (old[i].y1 == old[i].y2) continue;
                Box b2 = new Box();
                b2.x1 = old[i].x1 + 1;
                b2.y1 = old[i].y1 + 1;
                b2.x2 = old[i].x2;
                b2.y2 = old[i].y2;
            }
            for (int i = 0; i < old.Count; ++i)
                for (int j = 0; j < old.Count; ++j) {
                    if (
                }
                    return result;
        }*/
        bool[,] board;
        void Fill(int x1, int y1, int x2, int y2) {
            for (int i = x1; i <= x2; ++i)
                for (int j = y1; j <= y2; ++j)
                    board[i, j] = true;
        }
        int Simulate() {
            bool[,] result = new bool[101, 101];
            int count = 0;
            for (int i = 1; i<101; ++i)
            for (int j = 1; j<101; ++j) {
                if ((board[i - 1, j] && board[i, j - 1]) ||
                    (board[i, j] && (board[i - 1, j] || board[i, j - 1]))) {
                    result[i, j] = true;
                    count++;
                }
            }
            board = result;
            return count;
        }
        Program() {
            int ncases = int.Parse(Console.ReadLine());
            board = new bool[101, 101];
            for (int i = 0; i < ncases; ++i) {
                int r = int.Parse(Console.ReadLine());
                int result = 0;
                if (r > 0) {
                    for (int j = 0; j < r; ++j) {
                        int[] coords = Console.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                        Fill(coords[0], coords[1], coords[2], coords[3]);
                    }
                    result = 0;
                    do { result++; } while (Simulate() > 0);
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
