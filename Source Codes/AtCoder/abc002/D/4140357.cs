using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

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

        static int N;
        static bool[,] relations;
        static void Main() {
            var Key = getKeys();
            N = Key[0];
            int M = Key[1];
            relations = new bool[N, N];
            for (int i = 0; i < N; i++) {
                relations[i, i] = true;
            }
            for (int i = 0; i < M; i++) {
                Key = getKeys();
                relations[Key[0] - 1, Key[1] - 1] = true;
                relations[Key[1] - 1, Key[0] - 1] = true;
            }

            int Max = (int)Math.Pow(2, N);
            int answer = 0;
            for (int i = 0; i < Max; i++) {
                answer = Math.Max(answer, count(getMembers(i)));
            }
            Console.WriteLine(answer);
        }

        static int count(List<int> members) {
            for (int j = 0; j < members.Count; j++) {
                for (int k = 0; k < members.Count; k++) {
                    if (!relations[members[j], members[k]]) {
                        return 0;
                    }
                }
            }
            return members.Count;
        }

        //bitPattern???????????
        static List<int> getMembers(int pattern) {
            List<int> members = new List<int>();
            int mask = 1;
            for (int i = 0; i < N; i++) {
                if ((mask & pattern) != 0) {
                    members.Add(i);
                }
                mask *= 2;
            }
            return members;
        }
    }
}