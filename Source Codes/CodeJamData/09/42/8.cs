using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ09R1A {
    class GCJ09R2_B : Z {
        public override void Solve() {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++) {

                string[] s = Console.ReadLine().Split(' ');
                int N = int.Parse(s[0]);
                int M = int.Parse(s[1]);
                int F = int.Parse(s[2]);

                string[] map = new string[N];
                for (int i = 0; i < N; i++) {
                    map[i] = Console.ReadLine();
                }
                string ret = DigPuzzle(N, M, F, map);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);


                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string DigPuzzle(int N, int M, int maxFall, string[] map) {
            // State.  i, j, dugleft, dugright (this row). Dis = totdug
            // Moves: EITHER walk to hole
            // Moves: OR dig section
            // L->R (not including R), drop into right
            // R->L (not including L) drop into left

            int Z = N * M + 1;

            Queue<int>[] States = new Queue<int>[Z];
            for (int i = 0; i < Z; i++) {
                States[i] = new Queue<int>();
            }
            States[0] = new Queue<int>();
            States[0].Enqueue(0);
            States[0].Enqueue(0);
            States[0].Enqueue(0);
            States[0].Enqueue(-1);

            for (int totdug = 0; totdug < Z; totdug++) {
                while (States[totdug].Count > 0) {
                    int i1 = States[totdug].Dequeue();
                    if (i1 == N - 1) return string.Format("Yes {0}", totdug);
                    int j1 = States[totdug].Dequeue();
                    int dugleft = States[totdug].Dequeue();
                    int dugright = States[totdug].Dequeue();
                    bool[] thisrow = new bool[M];
                    bool[] nextrow = new bool[M];
                    for (int j = 0; j < M; j++) {
                        if (map[i1][j] == '#' && (j > dugright || j < dugleft)) thisrow[j] = true;
                        if (map[i1 + 1][j] == '#') nextrow[j] = true;
                    }
                    // Walk left
                    int jpos = j1;
                    while (jpos > 0 && !thisrow[jpos - 1] && nextrow[jpos - 1]) jpos--;
                    int jleft = jpos;
                    while (jpos < M - 1 && !thisrow[jpos + 1] && nextrow[jpos + 1]) jpos++;
                    int jright = jpos;

                    // Drop left
                    int j2 = jleft - 1;
                    if (j2 >= 0 && !thisrow[j2]) {
                        int ifall = falldis(map, i1 + 1, j2, N);
                        if (ifall <= maxFall) {
                            int i2 = i1 + ifall;
                            States[totdug].Enqueue(i2);
                            States[totdug].Enqueue(j2);
                            States[totdug].Enqueue(0);
                            States[totdug].Enqueue(-1);
                        }
                    }

                    // Drop right
                    j2 = jright + 1;
                    if (j2 < M && !thisrow[j2]) {
                        int ifall = falldis(map, i1 + 1, j2, N);
                        if (ifall <= maxFall) {
                            int i2 = i1 + ifall;
                            States[totdug].Enqueue(i2);
                            States[totdug].Enqueue(j2);
                            States[totdug].Enqueue(0);
                            States[totdug].Enqueue(-1);
                        }
                    }

                    // Dig left
                    for (int jRightDig = jleft + 1; jRightDig <= jright; jRightDig++) {
                        for (int jLeftDig = jleft + 1; jLeftDig <= jRightDig; jLeftDig++) {
                            int dug = jRightDig - jLeftDig + 1;
                            j2 = jLeftDig;
                            int ifall = falldis(map, i1 + 1, j2, N);
                            if (ifall <= maxFall) {
                                int i2 = i1 + ifall;
                                States[totdug + dug].Enqueue(i2);
                                States[totdug + dug].Enqueue(j2);
                                if (ifall == 1) {
                                    States[totdug + dug].Enqueue(jLeftDig);
                                    States[totdug + dug].Enqueue(jRightDig);
                                } else {
                                    States[totdug + dug].Enqueue(0);
                                    States[totdug + dug].Enqueue(-1);
                                }
                            }
                        }
                    }

                    // Dig right
                    for (int jRightDig = jleft; jRightDig <= jright - 1; jRightDig++) {
                        for (int jLeftDig = jleft; jLeftDig <= jRightDig; jLeftDig++) {
                            int dug = jRightDig - jLeftDig + 1;
                            j2 = jRightDig;
                            int ifall = falldis(map, i1 + 1, j2, N);
                            if (ifall <= maxFall) {
                                int i2 = i1 + ifall;
                                States[totdug + dug].Enqueue(i2);
                                States[totdug + dug].Enqueue(j2);
                                if (ifall == 1) {
                                    States[totdug + dug].Enqueue(jLeftDig);
                                    States[totdug + dug].Enqueue(jRightDig);
                                } else {
                                    States[totdug + dug].Enqueue(0);
                                    States[totdug + dug].Enqueue(-1);
                                }
                            }
                        }
                    }
                }
            }

            return "No";
        }

        private int falldis(string[] map, int i, int j, int N) {
            int top = i - 1;
            while (i < N - 1 && map[i + 1][j] == '.') i++;
            return i - top;
        }

    }
}
