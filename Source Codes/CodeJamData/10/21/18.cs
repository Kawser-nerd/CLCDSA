using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ20101BA {
    class Program {
        private int firstMatch(string s1, string s2) {
            int m = Math.Min(s1.Length, s2.Length);
            for (int i = 0; i < m; ++i)
                if (s1[i] != s2[i]) return i;
            return m;
        }
        private int solve(int N, int M) {
            List<string> dirs=new List<string>();
            for (int i = 0; i < N; ++i)
                dirs.Add(Console.ReadLine().Substring(1) + "/");
            int result = 0;
            for (int i = 0; i < M; ++i) {
                string need = Console.ReadLine().Substring(1) + "/";
                int bestM = 0;
                string bestD = "";
                foreach (string d in dirs) {
                    int matched = firstMatch(d, need);
                    if (matched > bestM) { bestM = matched; bestD = d; }
                }
                string remaining = need.Substring(bestM);
                foreach (char c in remaining)
                    if (c == '/') ++result;
                dirs.Add(need);
            }
            return result;
        }
        public Program() {
            int ncases = int.Parse(Console.ReadLine());
            for (int i = 0; i < ncases; ++i) {
                int[] input = Console.ReadLine().Split().Select(p => int.Parse(p)).ToArray();
                Console.WriteLine("Case #{0}: {1}", i + 1, solve(input[0], input[1]));
            }
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
