using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        static int[] getKeys(char delimiter) {
            var Keys = Console.ReadLine().Split(' ');
            int N = Keys.Length;
            int[] Ns = new int[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }
        public static void Show<T>(T[,] map) {
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
        public static void Show<T>(T[,] map, string delimiter) {
            int H = map.GetLength(0);
            int W = map.GetLength(1);
            Console.WriteLine("-------------------------");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    Console.Write(map[i, j] + delimiter);
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------------------");
        }
        public static void Show<T>(IEnumerable<T> ts) {
            foreach (var item in ts) {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
        public static void Show<T>(IEnumerable<T> ts, string delimiter) {
            foreach (var item in ts) {
                Console.Write(item + delimiter);
            }
            Console.WriteLine();
        }

        static void Main() {
            var A = Console.ReadLine();
            if (A == "a") {
                Console.WriteLine(-1);
            } else {
                Console.WriteLine("a");
            }
        }
    }
}