using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace AtCoder {
    public class Program {
        static int[] getKeys() {
            var Keys = Console.ReadLine().Split(' ');
            int N = Keys.Length;
            int[] Ns = new int[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }
        static int[] getKeys(char delimiter) {
            var Keys = Console.ReadLine().Split(delimiter);
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
            var Key = getKeys();
            int N = Key[0];
            int M = Key[1];
            int R = Key[2];
            int[,] Route = new int[N, N];
            Key = getKeys();
            int[] stopOvers = new int[R];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Route[i, j] = int.MaxValue;
                }
            }
            for (int i = 0; i < R; i++) {
                stopOvers[i] = Key[i] - 1;
            }
            for (int i = 0; i < M; i++) {
                Key = getKeys();
                Route[Key[0] - 1, Key[1] - 1] = Key[2];
                Route[Key[1] - 1, Key[0] - 1] = Key[2];
            }
            getDistance(N, Route);
            Stack<List<int>> Permutation = new Stack<List<int>>();
            int answer = int.MaxValue;
            Permutation.Push(new List<int>());
            while (Permutation.Count > 0) {
                var list = Permutation.Pop();
                if (list.Count == stopOvers.Length) {
                    int sum = 0;
                    for (int i = 1; i < list.Count; i++) {
                        sum += Route[list[i - 1], list[i]];
                    }
                    answer = Math.Min(answer, sum);
                }
                for (int i = 0; i < stopOvers.Length; i++) {
                    if (!list.Contains(stopOvers[i])) {
                        var l = new List<int>(list);
                        l.Add(stopOvers[i]);
                        Permutation.Push(l);
                    }
                }
            }
            Console.WriteLine(answer);
        }

        static void getDistance(int N, int[,] Route) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        if (Route[j, i] + Route[i, k] >= 0) {//OverFlow??
                            Route[j, k] = Math.Min(Route[j, k], Route[j, i] + Route[i, k]);
                        }
                    }
                }
            }
        }

    }
}