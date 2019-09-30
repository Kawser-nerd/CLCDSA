import java.io.*;
import java.util.*;

/**
 * @author def
 * @version 1.0
 */
public class C {

    public static void main(String args[]) throws IOException {
        new C().solve();
    }

    void solve() throws IOException {
        in = new BufferedReader(new FileReader("C-large.in"));
        out = new PrintWriter("C-large.out");

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int[][] g = new int[m][n];
            for (int i = 0; i < m; ++i) {
                String l = in.readLine();
                int j = 0;
                for (int k = 0; k < n / 4; ++k) {
                    int v = Integer.parseInt("" + l.charAt(k), 16);
                    int d = 3;
                    while (v > 0) {
                        if ((v & 1) == 1) {
                            g[i][j + d] = 1;
                        }
                        v >>>= 1;
                        --d;
                    }
                    j += 4;
                }
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][j] != 2) {
                        boolean flag = true;
                        int d = 0;
                        if (i > 0) {
                            d = g[i - 1][j] - 1;
                        } else if (j > 0) {
                            d = g[i][j - 1] - 1;
                        }
                        if (d == 0) d = 1;
                        int k;
                        for (k = i + d; flag && k < m && j + k - i < n; ++k) {
                            int p = j + k - i;
                            for (int q = i; flag && q <= k; ++q) {
                                flag = /*g[q][p] != 2 &&*/ g[q][p] != g[q][p - 1];
                            }
                            for (int q = j; flag && q <= p; ++q) {
                                flag = /*g[k][q] != 2 &&*/ g[k][q] != g[k - 1][q];
                            }
                        }
                        g[i][j] = flag ? k - i : k - i - 1;
                        /*
                        for (int p = 0; p < r; ++p) {
                            for (int q = 0; q < r; ++q) {
                                g[i + p][j + q] = 2;
                            }
                        }
                        */
                    }
                }
            }
            int s = Math.min(n, m);
            int a[] = new int[s + 1];
            for (int k = s; k > 0; --k) {
                for (int i = 0; i < m - k + 1; i++) {
                    for (int j = 0; j < n - k + 1; j++) {
                        if (g[i][j] >= k && g[i][j] != -1 && g[i + k - 1][j + k - 1] != -1
                                && g[i][j + k - 1] != -1 && g[i + k - 1][j] != -1) {
                            a[k]++;
                            for (int p = 0; p < k; ++p) {
                                for (int q = 0; q < k; ++q) {
                                    g[i + p][j + q] = -1;
                                }
                            }
                        }
                    }
                }
            }
            /*
            for (int k = s; k > 0; --k) {
                for (int i = 0; i < m - k + 1; i += k) {
                    for (int j = 0; j < n - k + 1; j += k) {
                        boolean flag = true;
                        for (int p = 0; flag && p < k; ++p) {
                            for (int q = 0; q < k; ++q) {
                                if (g[i + p][j + q] == 2) {
                                    flag = false;
                                    break;
                                }
                                if (p > 0 && g[i + p][j + q] == g[i + p - 1][j + q]) {
                                    flag = false;
                                    break;
                                }
                                if (q > 0 && g[i + p][j + q] == g[i + p][j + q - 1]) {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (flag) {
                            a[k]++;
                            for (int p = 0; p < k; ++p) {
                                for (int q = 0; q < k; ++q) {
                                    g[i + p][j + q] = 2;
                                }
                            }
                        }
                    }
                }
            }
            */
            int cnt = 0;
            for (int i = 1; i <= s; ++i) {
                if (a[i] > 0) ++cnt;
            }
            out.println("Case #" + c + ": " + cnt);
            System.out.println("Case #" + c + ": " + cnt);
            for (int i = s; i > 0; --i) {
                if (a[i] > 0) {
                    out.println(i + " " + a[i]);
                }
            }
        }

        out.close();
    }

    BufferedReader in;
    PrintWriter out;
}