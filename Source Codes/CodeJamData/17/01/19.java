import java.util.*;
import java.io.*;

public class PA implements Runnable {
    static class Data {
        private StringTokenizer tok;
        private final BufferedReader rd;
        private final PrintWriter wr;

        Data() {
            tok = null;
            rd = new BufferedReader(new InputStreamReader(System.in));
            wr = new PrintWriter(System.out);
        }

        Data(String name) throws IOException {
            tok = null;
            rd = new BufferedReader(new FileReader(new File(name + ".in")));
            wr = new PrintWriter(new File(name + ".out"));
        }

        void println(String line) {
            wr.println(line);
        }

        void close() throws IOException {
            rd.close();
            wr.close();
        }

        String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        static Data console() {
            return new Data();
        }

        static Data files(String name) throws IOException {
            return new Data(name);
        }
    }

    public static void main(String[] args) {
        new Thread(new PA()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Throwable t) {
            throw new RuntimeException(t);
        }
    }

    private void solve() throws IOException {
        Data data = Data.files("a");

        int t = data.nextInt();
        for (int i = 0; i < t; ++i) {
            String s = data.nextToken().trim();
            int k = data.nextInt();
            int res = subsolve(s, k);
            data.println(String.format("Case #%d: %s", i + 1, (res >= 0) ? res : "IMPOSSIBLE"));
        }

        data.close();
    }

    private int subsolve(String s, int k) {
        int n = s.length();
        boolean[] c = new boolean[n];
        for (int i = 0; i < n; ++i) {
            c[i] = (s.charAt(i) == '+');
        }
        int cnt = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            if (!c[i]) {
                for (int j = 0; j < k; ++j) {
                    c[i + j] = !c[i + j];
                }
                ++cnt;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!c[i]) {
                return -1;
            }
        }
        return cnt;
    }
}
