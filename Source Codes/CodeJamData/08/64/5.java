package gcj4;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class MainB {
    static class Permutation {
        private static void swap(int[] p, int i, int j) {
            int t = p[i];
            p[i] = p[j];
            p[j] = t;
        }

        private static void revert(int[] p, int m, int n) {
            while (m < n) {
                int t = p[m];
                p[m] = p[n];
                p[n] = t;
                m++;
                n--;
            }
        }

        public static boolean pre(int[] p) {
            boolean find = false;
            int i = 0;
            for (i = p.length - 1; i > 0; i--)
                if (p[i] < p[i - 1]) {
                    find = true;
                    break;
                }
            if (find == false)
                return false;
            int j = 0;
            for (j = i; j < p.length; j++)
                if (p[j] >= p[i - 1])
                    break;
            swap(p, j - 1, i - 1);
            revert(p, i, p.length - 1);
            return true;
        }

        public static boolean next(int[] p) {
            boolean find = false;
            int i = 0;
            for (i = p.length - 1; i > 0; i--)
                if (p[i] > p[i - 1]) {
                    find = true;
                    break;
                }
            if (!find) {
                Arrays.sort(p);
                return false;
            }
            int j;
            for (j = p.length - 1; j > i - 1; j--)
                if (p[j] > p[i - 1])
                    break;
            swap(p, i - 1, j);
            revert(p, i, p.length - 1);
            return true;
        }
    }

    static int[][] mapa;
    static int[][] mapb;
    static boolean[][][][] memo;
    static boolean[][][][] vst;

    public static boolean dp(int ci, int cj, int cif, int cjf) {
        if (vst[ci][cj][cif][cjf])
            return memo[ci][cj][cif][cjf];
        vst[ci][cj][cif][cjf] = true;
        boolean ret = true;

        return memo[ci][cj][cif][cjf] = ret;
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {
        BufferedReader cin = new BufferedReader(new InputStreamReader(
                new FileInputStream(
                        "c:\\cc\\eclipse-workspace\\ACM\\gcj4\\B-small.in")));
        PrintWriter out = new PrintWriter(
                "c:\\cc\\eclipse-workspace\\ACM\\gcj4\\Bout.txt");
        int testcase = Integer.parseInt(cin.readLine());
        for (int tst = 1; tst <= testcase; tst++) {
            int n = Integer.parseInt(cin.readLine());
            mapa = new int[n][n];
            for (int i = 0; i < n-1; i++) {
                StringTokenizer st = new StringTokenizer(cin.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                mapa[x - 1][y - 1] = 1;
                mapa[y - 1][x - 1] = 1;
            }
            int m = Integer.parseInt(cin.readLine());
            mapb = new int[m][m];
            for (int i = 0; i < m-1; i++) {
                StringTokenizer st = new StringTokenizer(cin.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                mapb[x - 1][y - 1] = 1;
                mapb[y - 1][x - 1] = 1;
            }
            boolean ret = false;
            out2: for (int i = 0; i < (1 << n); i++) {

                if (Integer.bitCount(i) == m) {
                    int[] p = new int[m];
                    int tag = 0;
                    for (int j = 0; j < n; j++) {
                        if (((1 << j) & i) != 0) {
                            p[tag++] = j;
                        }
                    }
                    do {
                        boolean ok = true;
                        out: for (int j = 0; j < m; j++) {
                            for (int k = 0; k < m; k++) {
                                if (mapb[j][k] != mapa[p[j]][p[k]]) {
                                    ok = false;
                                    break out;
                                }
                            }
                        }
                        if (ok) {
                            ret = true;
                            break out2;
                        }
                    } while (Permutation.next(p));
                }
            }
            if (ret)
                out.println("Case #" + tst + ": YES");
            else
                out.println("Case #" + tst + ": NO");

        }
        out.close();
    }

}
