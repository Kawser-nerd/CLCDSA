import java.io.*;
import java.util.*;

public class C_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("C-small-attempt0.out"));

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int m = in.nextInt();
            int n = in.nextInt();
            boolean[][] a = new boolean[m][n];

            for (int i = 0; i < m; i++) {
                String s = in.next();
                for (int j = 0; j < n; j++) {
                    a[i][j] = s.charAt(j) == '.';
                }
            }

            int[][] b = new int[m + 1][1 << n];
            boolean[] p = new boolean[n];
            boolean[] q = new boolean[n];
            for (int i = 0; i < m; i++) {
                search:
                for (int j = 0; j < 1 << n; j++) {
                    int tmp = j;
                    for (int k = 0; k < n; k++) {
                        p[k] = tmp % 2 == 1;
                        tmp /= 2;
                    }
                    for (int k = 0; k < n; k++) {
                        if (k < n - 1 && p[k] && p[k + 1]) {
                            continue search;
                        }
                        if (p[k] && (i == 0 || !a[i - 1][k])) {
                            continue search;
                        }
                    }

                    search2:
                    for (int l = 0; l < 1 << n; l++) {
                        int d = 0;
                        tmp = l;
                        for (int k = 0; k < n; k++) {
                            q[k] = tmp % 2 == 1;
                            if (q[k]) {
                                d++;
                            }
                            tmp /= 2;
                        }
                        for (int k = 0; k < n; k++) {
                            if (k < n - 1 && q[k] && q[k + 1]) {
                                continue search2;
                            }
                            if (q[k] && !a[i][k]) {
                                continue search2;
                            }
                            if (q[k] && k > 0 && p[k - 1]) {
                                continue search2;
                            }
                            if (q[k] && k < n - 1 && p[k + 1]) {
                                continue search2;
                            }
                        }
                        b[i + 1][l] = Math.max(b[i + 1][l], b[i][j] + d);
                    }
                }
            }

            int ans = 0;
            for (int j = 0; j < 1 << n; j++) {
                if (b[m][j] > ans) {
                    ans = b[m][j];
                }
            }
            out.printf("Case #%d: %d\n", test + 1, ans);
        }

        in.close();
        out.close();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new C_as()).start();
    }
}