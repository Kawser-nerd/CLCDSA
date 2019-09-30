using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam {
    class b {
        static int[] f;
        static int n, m;
        static int[] zi = new int[] { -1, 0, 0, 1 };
        static int[] zj = new int[] { 0, -1, 1, 0 };
        static int find(int v) {
            if (v != f[v]) {
                return f[v] = find(f[v]);
            }
            return v;
        }
        static void uno(int a, int b) {
            a = find(a);
            b = find(b);
            f[a] = b;
        }
        static bool ok(int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m;
        }
        static void Main() {
            StreamReader cin = new StreamReader("b.in");
            StreamWriter cout = new StreamWriter("b.out");
            int T = int.Parse(cin.ReadLine());
            for (int ca = 0; ca < T; ++ca) {
                string[] tmps = cin.ReadLine().Split(' ');
                n = int.Parse(tmps[0]);
                m = int.Parse(tmps[1]);
                int[,] dt = new int[n, m];
                for (int i = 0; i < n; ++i) {
                    tmps = cin.ReadLine().Split(' ');
                    for (int j = 0; j < m; ++j) {
                        dt[i, j] = int.Parse(tmps[j]);
                    }
                }
                f = new int[n * m];
                for (int i = 0; i < n * m; ++i) {
                    f[i] = i;
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        for (int z = 0; z < 4; ++z) {
                            int ti = i + zi[z], tj = j + zj[z];
                            if (ok(ti, tj) && dt[ti, tj] < dt[i, j]) {
                                bool can = true;;
                                for (int zz = 0; zz < 4; ++zz) {
                                    int ni = i + zi[zz], nj = j + zj[zz];
                                    if (ok(ni, nj) && dt[ni, nj] < dt[ti, tj]) {
                                        can = false;
                                        break;
                                    }
                                }
                                if (can) {
                                    uno(i * m + j, ti * m + tj);
                                    break;
                                }
                            }
                        }
                    }
                }
                char[,] ans = new char[n, m];
                char[] color = new char[n * m];
                char now = 'a';
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (color[find(i * m + j)] == 0) {
                            ans[i, j] = now;
                            color[find(i * m + j)] = now;
                            ++now;
                        } else {
                            ans[i, j] = color[find(i * m + j)];
                        }
                    }
                }
                cout.WriteLine(string.Format("Case #{0}:", ca + 1));
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (j + 1 == m) {
                            cout.WriteLine(ans[i, j]);
                        } else {
                            cout.Write(ans[i, j] + " ");
                        }
                    }
                }
            }
            cin.Close();
            cout.Close();
        }
    }
}
