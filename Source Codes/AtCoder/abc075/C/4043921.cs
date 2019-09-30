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
            bool[,] IsReachable = new bool[Key[0], Key[0]];
            List<string> Loop = new List<string>();
            for (int i = 0; i < Key[1]; i++) {
                var bridge = getKeys(' ');
                IsReachable[bridge[0] - 1, bridge[1] - 1] = true;
                IsReachable[bridge[1] - 1, bridge[0] - 1] = true;
            }

            state initial = new state(0);
            Stack<state> histories = new Stack<state>();
            histories.Push(initial);
            while (histories.Count > 0) {
                var state = histories.Pop();
                for (int i = 0; i < Key[0]; i++) {
                    if (IsReachable[state.Position, i]) {
                        if (state.History.Count > 1 && state.History[state.History.Count - 2] == i) {
                            continue;
                        }
                        state s = new state(i, state.History);
                        if (state.History.Contains(i)) {
                            getLoop(Loop, s.History);
                            continue;
                        }
                        histories.Push(s);
                    }
                }
            }
            //            Show(Loop);
            Console.WriteLine(Key[1] - Loop.Count);
        }

        static void getLoop(List<string> Loops, List<int> history) {
            int end = history.Last();
            bool start = false;
            string s;
//            Show(history);
            for (int i = 0; i < history.Count - 1; i++) {
                if (end == history[i]) start = true;
                if (start) {
                    s = Math.Min(history[i], history[i + 1]) + "," + Math.Max(history[i], history[i + 1]);
                    if (!Loops.Contains(s)) Loops.Add(s);
                }
            }
        }
    }

    class state {
        public List<int> History;
        public int Position;
        public state(int p) {
            Position = p;
            History = new List<int>();
            History.Add(p);
        }
        public state(int p, List<int> history) {
            Position = p;
            History = new List<int>();
            for (int i = 0; i < history.Count; i++) {
                History.Add(history[i]);
            }
            History.Add(p);
        }
    }

}