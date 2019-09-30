import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        int r = nextInt();
        int c = nextInt();
        char[][] m = new char[r][];
        for (int i = 0; i < r; ++i) {
            m[i] = next().toCharArray();
        }

        int ans = 0;
        int[][] id = new int[r][c];
        for (int s = 0; s < 1 << (r * c); ++s) {
            for (int[] t : id) {
                Arrays.fill(t, 0);
            }
            for (int i = 0, g = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j, ++g) {
                    if ((s & (1 << g)) == 0) {
                        switch (m[i][j]) {
                            case '|': id[(i + r - 1) % r][j]++; break;
                            case '-': id[i][(j + c - 1) % c]++; break;
                            case '\\': id[(i + r - 1) % r][(j + c - 1) % c]++; break;
                            case '/': id[(i + r - 1) % r][(j + 1) % c]++; break;
                        }
                    } else {
                        switch (m[i][j]) {
                            case '|': id[(i + 1) % r][j]++; break;
                            case '-': id[i][(j + 1) % c]++; break;
                            case '\\': id[(i + 1) % r][(j + 1) % c]++; break;
                            case '/': id[(i + 1) % r][(j + c - 1) % c]++; break;
                        }
                    }
                }
            }
            boolean ok = true;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    ok &= id[i][j] == 1;
                }
            }
            if (ok) {
                ++ans;
            }
        }
        out.println(prefix + ans);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(C.class.getSimpleName() + ".in"));
        out = new PrintWriter(C.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
