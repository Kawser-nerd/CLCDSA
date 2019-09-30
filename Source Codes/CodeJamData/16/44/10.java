package gcj.gcj2016.round2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by hama_du on 5/1/16.
 */
public class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for (int t = 1 ; t <= T ; t++) {
            int n = in.nextInt();
            char[][] c = new char[n][];
            for (int i = 0; i < n ; i++) {
                c[i] = in.next().toCharArray();
            }
            out.println(String.format("Case #%d: %d", t, solve(n, c)));
        }
        out.flush();
    }

    private static int solve(int n, char[][] map) {
        int n2 = n*n;
        int best = n2;
        for (int i = 0 ; i < (1<<n2) ; i++) {
            char[][] wm = new char[n][];
            for (int j = 0; j < n ; j++) {
                wm[j] = map[j].clone();
            }
            for (int r = 0 ; r < n ; r++) {
                for (int c = 0; c < n ; c++) {
                    if ((i & (1<<(r*n+c))) >= 1) {
                        wm[r][c] = '1';
                    }
                }
            }
            if (dfs(wm, 0, 0)) {
                best = Math.min(best, Integer.bitCount(i));
            }
        }
        return best;
    }

    private static boolean dfs(char[][] wm, int wk, int mc) {
        int n = wm.length;
        if (wk == (1<<n)-1) {
            return mc == (1<<n)-1;
        }
        boolean once = false;
        boolean ret = true;
        for (int f = 0 ; f < n ; f++) {
            if ((wk & (1<<f)) == 0) {
                for (int mi = 0; mi < n ; mi++) {
                    if (wm[f][mi] == '1' && (mc & (1<<mi)) == 0) {
                        once = true;
                        ret &= dfs(wm, wk | (1<<f), mc | (1<<mi));
                    }
                }
            }
        }
        return once && ret;
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}
