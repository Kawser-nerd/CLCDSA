using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace AtCoder {
    public class Program {
        static int[] getKeys(char delimiter = ' ') {
            var Keys = Console.ReadLine().Split(delimiter);
            int N = Keys.Length;
            int[] Ns = new int[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }
        static long[] getKeys_L(char delimiter = ' ') {
            var Keys = Console.ReadLine().Split(delimiter);
            int N = Keys.Length;
            long[] Ns = new long[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = long.Parse(Keys[i]);
            }
            return Ns;
        }
        static double[] getKeys_D(char delimiter = ' ') {
            var Keys = Console.ReadLine().Split(delimiter);
            int N = Keys.Length;
            var Ns = new double[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = double.Parse(Keys[i]);
            }
            return Ns;
        }
        static int[] getLines(int N, char delimiter = ' ') {
            int[] Ns = new int[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = int.Parse(Console.ReadLine());
            }
            return Ns;
        }
        static long[] getLines_L(int N, char delimiter = ' ') {
            long[] Ns = new long[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = long.Parse(Console.ReadLine());
            }
            return Ns;
        }
        static double[] getLines_D(int N, char delimiter = ' ') {
            double[] Ns = new double[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = double.Parse(Console.ReadLine());
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
        public static void ShowDictionary<T1, T2>(Dictionary<T1, T2> dictionary) {
            foreach (var item in dictionary) {
                Console.WriteLine(item);
            }
        }
        static T[] getUniform<T>(int length, T value) {
            T[] Ts = new T[length];
            for (int i = 0; i < length; i++) {
                Ts[i] = value;
            }
            return Ts;
        }
        static void setUniform<T>(T[] ts, T value) {
            int length = ts.Length;
            for (int i = 0; i < length; i++) {
                ts[i] = value;
            }
        }
        static T[,] getUniform<T>(int row, int col, T value) {
            T[,] Ts = new T[row, col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    Ts[j, i] = value;
                }
            }
            return Ts;
        }
        static void setUniform<T>(T[,] ts, T value) {
            int N = ts.GetLength(0);
            int M = ts.GetLength(1);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    ts[j, i] = value;
                }
            }
        }
        static Tuple<int, int> findIndex<T>(T[,] map, T value) where T : IComparable {
            int row = map.GetLength(0);
            int col = map.GetLength(1);
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < row; j++) {
                    if (value.CompareTo(map[j, i]) == 0) return new Tuple<int, int>(j, i);
                }
            }
            return new Tuple<int, int>(-1, -1);
        }


        static void Main() {
            var keys = getKeys_L();
            int N = (int)keys[0];
            long K = keys[1];
            Dictionary<int, long> Counts = new Dictionary<int, long>();
            for (int i = 0; i < N; i++) {
                keys = getKeys_L();
                if (Counts.ContainsKey((int)keys[0])) {
                    Counts[(int)keys[0]] += keys[1];
                } else {
                    Counts.Add((int)keys[0], keys[1]);
                }
            }
            long sum = 0;
            foreach (var item in Counts.OrderBy(x => x.Key)) {
                sum += item.Value;
                if (sum >= K) {
                    Console.WriteLine(item.Key);
                    return;
                }
            }
            Console.WriteLine(Counts.Keys.Max());
        }
    }
}