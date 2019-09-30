package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    static int[][] m = new int[501][501];
    static int[][] c = new int[501][501];
    private static final int MOD = 100003;

    static {
        c[0][0] = 1;
        for (int i = 1; i < 501; i++) {
            c[i][0] = 1;
            c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= MOD;
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        for (int[] ints : m) {
            Arrays.fill(ints, -1);
        }

        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.println("Case #" + (i + 1) + ": " + new C().solve(in));
        }
        out.close();
    }

    private int solve(Scanner in) {
        int n = in.nextInt();
        int s = 0;
        for (int i = 1; i < n; i++) {
            s += get(n, i);
            s %= MOD;
        }
        return s;
    }

    private int get(int n, int k) {
        if (m[n][k] >= 0) return m[n][k];
        if (k == 1) {
            m[n][k] = 1;
        } else {
            int s = 0;
            for (int i = 1; i < k; i++) {
                s += (1L * get(k, i) * c[n - k - 1][k - i - 1]) % MOD;
                s %= MOD;
            }
            m[n][k] = s;
        }
        return m[n][k];
    }
}