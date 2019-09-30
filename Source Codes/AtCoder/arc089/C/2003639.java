import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int[][] d = new int[a + 1][b + 1];
        for (int x = 1; x <= a; x++) {
            for (int y = 1; y <= b; y++) {
                d[x][y] = nextInt();
            }
        }

        int n = 150;
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int x = 1; x <= a; x++) {
                    for (int y = 1; y <= b; y++) {
                        c[i][j] = Math.max(c[i][j], d[x][y] - i * x - j * y);
                    }
                }
            }
        }

        for (int x = 1; x <= a; x++) {
            for (int y = 1; y <= b; y++) {
                int r = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        r = Math.min(r, i * x + j * y + c[i][j]);
                    }
                }
                if (r != d[x][y]) {
                    out.println("Impossible");
                    return;
                }
            }
        }
        out.println("Possible");
        out.println((2 * n) + " " + (2 * (n - 1) + n * n));
        for (int i = 0; i < n - 1; i++) {
            out.println((i + 1) + " " + (i + 2) + " X");
            out.println((n + i + 2) + " " + (n + i + 1) + " Y");
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.println((i + 1) + " " + (n + j + 1) + " " + c[i][j]);
            }
        }
        out.println(1 + " " + (n + 1));
    }

    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}