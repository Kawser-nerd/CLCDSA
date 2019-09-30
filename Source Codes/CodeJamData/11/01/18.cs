using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Bot_Trust {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int n = Convert.ToInt32(lines[0]);
            int[,] order = new int[n, 2];
            int[,] next = new int[n, 2];
            int[] last = new int[2];
            last[0] = last[1] = -1;
            for (int i = 0; i < n; i++) {
                int r = 1;
                if (lines[i * 2 + 1] == "O")
                    r = 0;
                order[i, r] = Convert.ToInt32(lines[i * 2 + 2]);
                for (int j = last[r] + 1; j < i; j++)
                    next[j, r] = i;
                last[r] = i;
            }
            int res = 0;
            int[] pos = new int[2];
            pos[0] = pos[1] = 1;
            for (int c = 0; c < n; c++) {
                bool finish = false;
                while (!finish) {
                    res++;
                    for (int r = 0; r < 2; r++) {
                        if (order[c, r] > 0) {
                            if (order[c, r] == pos[r]) {
                                finish = true;
                            } else if (order[c, r] > pos[r]) {
                                pos[r]++;
                            } else {
                                pos[r]--;
                            }
                        } else {
                            if (order[next[c, r], r] > pos[r]) {
                                pos[r]++;
                            } else if (order[next[c, r], r] < pos[r]) {
                                pos[r]--;
                            }
                        }
                    }
                }
            }
            sw.WriteLine(res);
        }
    }
}
