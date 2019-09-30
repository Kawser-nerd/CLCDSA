import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;

public class C implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("C-small-attempt1.in"));
        PrintWriter out = new PrintWriter("C-small-attempt1.out");

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] a = new int[r + 2][c + 2];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    a[i + 1][j + 1] = in.nextInt();
                }
            }

            int best = 0;
            int[][] f = new int[r + 2][c + 2];
            search:
            for (int msk = 0; msk < (1 << (r * c)); msk++) {
                int m = msk;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        f[i + 1][j + 1] = m & 1;
                        m /= 2;
                    }
                }

                for (int i = 1; i <= r; i++) {
                    for (int j = 1; j <= c; j++) {
                        if (f[i - 1][j - 1] + f[i - 1][j + 0] + f[i - 1][j + 1] +
                            f[i - 0][j - 1] + f[i - 0][j + 0] + f[i - 0][j + 1] +
                            f[i + 1][j - 1] + f[i + 1][j + 0] + f[i + 1][j + 1] != a[i][j]) {
                            continue search;
                        }
                    }
                }

                int cur = 0;
                for (int i = 1; i <= c; i++) {
                    cur += f[r / 2 + 1][i];
                }
                if (cur > best) {
                    best = cur;
                }
            }

            System.out.printf("Case #%d: %d\n", test, best);
            out.printf("Case #%d: %d\n", test, best);
            
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] s) {
        new Thread(new C()).start();
    }
}
