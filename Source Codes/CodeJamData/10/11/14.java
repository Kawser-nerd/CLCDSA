import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class A {

    private static final String PROBLEM = "a";

    //private static final String TEST = "small-attempt0";
    private static final String TEST = "large";

    private String solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = nextToken().trim().toCharArray();
            if (a[i].length != n) {
                throw null;
            }
        }
        char[][] b = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[j][n - 1 - i] = a[i][j];
            }
        }
        for (int it = 0; it < n; it++) {
            for (int j = 0; j < n; j++) {
                int i = n - 1;
                while (i > 0) {
                    if (b[i][j] == '.') {
                        b[i][j] = b[i - 1][j];
                        b[i - 1][j] = '.';
                    }
                    i--;
                }
            }
        }
        char[][] q = extend(b);
        for (char[] row : q) {
            System.out.println(new String(row));
        }
        int maxR = count(q, 'R');
        int maxB = count(q, 'B');
        if (maxR >= k && maxB >= k) {
            return "Both";
        } else if (maxR >= k) {
            return "Red";
        } else if (maxB >= k) {
            return "Blue";
        } else {
            return "Neither";
        }
    }

    private static char[][] extend(char[][] b) {
        int n = b.length;
        char[][] r = new char[n + 2][n + 2];
        for (char[] x : r) {
            Arrays.fill(x, '#');
        }
        for (int i = 0; i < n; i++) {
            System.arraycopy(b[i], 0, r[i + 1], 1, n);
        }
        return r;
    }

    private static int count(char[][] q, char c) {
        int n = q.length;
        int res = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            int cnt = 0;
                            int x = i;
                            int y = j;
                            while (q[x][y] == c) {
                                cnt++;
                                x += dx;
                                y += dy;
                            }
                            res = Math.max(res, cnt);
                        }
                    }
                }
            }
        }
        return res;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + TEST + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + TEST + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}