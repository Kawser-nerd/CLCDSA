using System;
using System.Reflection;
using System.Linq.Expressions;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        static int[] getKeys(char delimiter) {
            var Keys = Console.ReadLine().Split(' ');
            int[] Ns = new int[Keys.Length];
            for (int i = 0; i < Keys.Length; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }
        static void Show<T>(T[,] map) {
            int H = map.GetLength(0);
            int W = map.GetLength(1);
            Console.WriteLine("-------------------------");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    Console.Write(map[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------------------");
        }
        static void Show<T>(IEnumerable<T> ts) {
            foreach (var item in ts) {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
        static void Main() {
            var Key = getKeys(' ');
            long N = Key[0];
            long K = Key[1];
            Position[] positions = new Position[N];
            long MIN = long.MaxValue;
            for (int i = 0; i < N; i++) {
                Key = getKeys(' ');
                positions[i] = new Position(Key[0], Key[1]);
            }
            long Left, Top, Bottom, Right;
            for (int i = 0; i < N; i++) {
                Left = positions[i].X;
                foreach (var item in positions.Where(x => Left < x.X)) { 
                    Right = item.X;
                    for (int j = 0; j < N; j++) {
                        Bottom = positions[j].Y;
                        foreach (var item2 in positions.Where(y => y.Y > Bottom)) {
                            Top = item2.Y;
                            if (positions.Where(p => (p.X >= Left && p.X <= Right && p.Y >= Bottom && p.Y <= Top)).Count() >= K) {
                                MIN = Math.Min(MIN, (Right - Left) * (Top - Bottom));
                            }
                        }
                    }
                }
            }
            Console.WriteLine(MIN);
        }
    }
    class Position {
        public int X;
        public int Y;
        public Position(int x,int y) {
            X = x;
            Y = y;
        }
    }
}