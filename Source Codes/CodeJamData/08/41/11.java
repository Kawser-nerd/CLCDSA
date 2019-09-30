import java.io.*;
import java.util.*;

public class A_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int tn = in.nextInt();
        for (int test = 0; test < tn; test++) {
            int m = in.nextInt();
            int v = in.nextInt();
            int[][] c = new int[2][m + 1];
            Arrays.fill(c[0], Integer.MAX_VALUE);
            Arrays.fill(c[1], Integer.MAX_VALUE);
            boolean[] ch = new boolean[m + 1];
            int[] op = new int[m + 1];
            
            for (int i = 1; i <= (m - 1) / 2; i++) {
                op[i] = in.nextInt();
                ch[i] = in.nextInt() == 1;
            }
            for (int i = (m + 1) / 2; i <= m; i++) {
                int x = in.nextInt();
                c[x][i] = 0;
            }

            for (int i = (m - 1) / 2; i >= 1; i--) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        if (c[j][2 * i] != Integer.MAX_VALUE && c[k][2 * i + 1] != Integer.MAX_VALUE) {
                            if (op[i] == 0) {
                                c[j | k][i] = Math.min(c[j][2 * i] + c[k][2 * i + 1], c[j | k][i]);
                                if (ch[i]) {
                                    c[j & k][i] = Math.min(c[j][2 * i] + c[k][2 * i + 1] + 1, c[j & k][i]);
                                }
                            }
                            if (op[i] == 1) {
                                c[j & k][i] = Math.min(c[j][2 * i] + c[k][2 * i + 1], c[j & k][i]);
                                if (ch[i]) {
                                    c[j | k][i] = Math.min(c[j][2 * i] + c[k][2 * i + 1] + 1, c[j | k][i]);
                                }
                            }
                        }
                    }
                }
            }

            if (c[v][1] == Integer.MAX_VALUE) {
                out.printf("Case #%d: IMPOSSIBLE\n", test + 1);
            } else {
                out.printf("Case #%d: %d\n", test + 1, c[v][1]);
            }
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
        new Thread(new A_as()).start();
    }
}