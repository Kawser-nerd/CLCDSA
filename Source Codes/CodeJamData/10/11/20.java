import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    int[] dx = {1, 0, -1, 0, 1, 1, -1, -1};
    int[] dy = {0, 1, 0, -1, 1, -1, 1, -1};

    boolean check(char[][] t, char c, int k) {
        int sz = t.length;
        for (int x = 0; x < sz; ++x) {
            for (int y = 0; y < sz; ++y) {
                if (t[x][y] == c) {
                    for (int d = 0; d < dx.length; ++d) {
                        boolean ok = true;
                        int nx = x;
                        int ny = y;
                        for (int i = 0; ok && i < k; ++i) {
                            ok = nx >= 0 && ny >= 0 && nx < sz && ny < sz && t[nx][ny] == c;
                            nx += dx[d];
                            ny += dy[d];
                        }
                        if (ok) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    private void solve() throws IOException {
        int size = nextInt();
        int k = nextInt();
        char[][] t = new char[size][];
        for (int i = 0; i < size; ++i) {
            t[i] = next().toCharArray();
        }
        for (int u = 0; u < size; ++u) {
            char[] tt = t[u];
            for (int i = size - 1, j = size - 1; i >= 0; --i) {
                if (tt[i] != '.') {
                    tt[j] = tt[i];
                    if (j != i) {
                        tt[i] = '.';
                    }
                    --j;
                }
            }
        }
        boolean blue = check(t, 'B', k);
        boolean red = check(t, 'R', k);
        if (blue && red) {
            out.println("Both");
        } else if (blue) {
            out.println("Blue");
        } else if (red) {
            out.println("Red");
        } else {
            out.println("Neither");
        }
    }

    public void run() throws IOException {
        String fn = A.class.getSimpleName().toLowerCase();
        in = new BufferedReader(new FileReader(fn + ".in"));
        out = new PrintWriter(fn + ".out");
        int n = nextInt();
        for (int i = 1; i <= n; ++i) {
            out.print("Case #" + i + ": ");
            solve();
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
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new A().run();
    }
}