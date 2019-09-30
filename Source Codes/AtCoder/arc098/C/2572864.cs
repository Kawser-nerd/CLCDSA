using System;
using System.Collections.Generic;

namespace ConsoleApplicationABC98D_ {
    class Program {
        static void Main(string[] args) {
            String line;
            line = Console.ReadLine();
            String[] var = line.Split(new char[] { ' ' });
            int N = int.Parse(var[0]);
            int K = int.Parse(var[1]);
            int Q = int.Parse(var[2]);
            line = Console.ReadLine();
            String[] Astr = line.Split(new char[] { ' ' });
            int[] A = new int[N];
            for (int i = 0; i < N; i++) { A[i] = int.Parse(Astr[i]); }


            int[] A0 = (int[])A.Clone();
            Array.Sort(A0);
            int minXmY = A0[A0.Length - 1] - A0[0];

            var A3 = new List<int>();
            var A2 = new List<int>();
            for (int i = N - Q; i >= 0; i--) {
                int Y = A0[i];
                A3.Clear();
                A2.Clear();
                for (int j = 0; j < N; j++) {
                    if (A[j] >= Y) {
                        A2.Add(A[j]);
                    } else {
                        if (A2.Count >= K) {
                            A2.Sort();
                            A3.AddRange(A2.GetRange(0, A2.Count - K + 1));
                        }
                        A2.Clear();
                        if (j >= N - K) { break; }
                    }
                }
                if (A2.Count >= K) {
                    A2.Sort();
                    A3.AddRange(A2.GetRange(0, A2.Count - K + 1));
                }
                if (A3.Count >= Q) {
                    A3.Sort();
                    int XmY = A3[Q - 1] - Y;
                    if (minXmY > XmY) { minXmY = XmY; }
                }
            }

            Console.WriteLine(minXmY.ToString());
        }
    }
}