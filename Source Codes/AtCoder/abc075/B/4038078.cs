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

        static void Main() {
            var Key = getKeys(' ');
            int[,] Map = new int[Key[0], Key[1]];
            bool[,] isBomb = new bool[Key[0], Key[1]];
            string S;
            for (int i = 0; i < Key[0]; i++) {
                S = Console.ReadLine();
                for (int j = 0; j < Key[1]; j++) {
                    if (S[j] == '#') {
                        isBomb[i, j] = true;
                        Increment(Map, i, j);
                    }
                }
            }
            for (int i = 0; i < Key[0]; i++) {
                S = "";
                for (int j = 0; j < Key[1]; j++) {
                    S += (isBomb[i, j]) ? "#" : Map[i, j].ToString();
                }
                Console.WriteLine(S);
            }
        }
    
        static void Increment(int[,] MAP, int h, int w) {
            if (w > 0) {
                MAP[h, w - 1]++;
            }
            if (w < MAP.GetLength(1) - 1) {
                MAP[h, w + 1]++;
            }
            if (h > 0) {
                if (w > 0) {
                    MAP[h - 1, w - 1]++;
                }
                MAP[h - 1, w]++;
                if (w < MAP.GetLength(1) - 1) {
                    MAP[h - 1, w + 1]++;
                }
            }
            if (h < MAP.GetLength(0) - 1) {
                if (w > 0) {
                    MAP[h + 1, w - 1]++;
                }
                MAP[h + 1, w]++;
                if (w < MAP.GetLength(1) - 1) {
                    MAP[h + 1, w + 1]++;
                }
            }
        }
    }
}