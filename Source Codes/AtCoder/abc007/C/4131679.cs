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

        static int sx, sy, gx, gy, Row, Col;
        static bool[,] ReadMap() {
            var inputs = getKeys(' ');
            Row = inputs[0];
            Col = inputs[1];
            bool[,] Map = new bool[inputs[0], inputs[1]];
            inputs = getKeys(' ');
            sx = inputs[1] - 1;
            sy = inputs[0] - 1;
            inputs = getKeys(' ');
            gx = inputs[1] - 1;
            gy = inputs[0] - 1;
            for (int i = 0; i < Row; i++) {
                string R = Console.ReadLine();
                for (int j = 0; j < Col; j++) {
                    Map[i, j] = R[j] == '#';
                }
            }
            return Map;
        }
        static void Main() {
            var MAP = ReadMap();
            var entered = new bool[Row, Col];
            List<int> Answer = new List<int>();
            Queue<List<int>> Histories = new Queue<List<int>>();
            var init = new List<int>(new int[] { sy * 100 + sx });
            Histories.Enqueue(init);
            while (Histories.Count > 0) {
                var history = Histories.Dequeue();
                var P = history.Last();
                if (P / 100 == gy && P % 100 == gx) {
                    Answer = history;
                    break;
                }
                if (P % 100 > 0 && !MAP[P / 100, P % 100 - 1] && !entered[P / 100, P % 100 - 1]) {
                    entered[P / 100, P % 100 - 1] = true;
                    var H = new List<int>();
                    for (int i = 0; i < history.Count; i++) {
                        H.Add(history[i]);
                    }
                    H.Add(P - 1);
                    Histories.Enqueue(H);
                }
                if (P % 100 < Col - 1 && !MAP[P / 100, P % 100 + 1] && !entered[P / 100, P % 100 + 1]) {
                    entered[P / 100, P % 100 + 1] = true;
                    var H = new List<int>();
                    for (int i = 0; i < history.Count; i++) {
                        H.Add(history[i]);
                    }
                    H.Add(P + 1);
                    Histories.Enqueue(H);
                }

                if (P / 100 > 0 && !MAP[P / 100 - 1, P % 100] && !entered[P / 100 - 1, P % 100]) {
                    entered[P / 100-1, P % 100] = true;
                    var H = new List<int>();
                    for (int i = 0; i < history.Count; i++) {
                        H.Add(history[i]);
                    }
                    H.Add(P - 100);
                    Histories.Enqueue(H);
                }

                if (P / 100 < Row - 1 && !MAP[P / 100 + 1, P % 100] && !entered[P / 100 + 1, P % 100]) {
                    entered[P / 100 + 1, P % 100] = true;
                    var H = new List<int>();
                    for (int i = 0; i < history.Count; i++) {
                        H.Add(history[i]);
                    }
                    H.Add(P + 100);
                    Histories.Enqueue(H);
                }
            }
            Console.WriteLine(Answer.Count - 1);
        }
    }
}