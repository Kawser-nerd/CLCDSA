import java.util.*;
import java.io.*;

public class PB implements Runnable {
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

        long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        static Data console() {
            return new Data();
        }

        static Data files(String name) throws IOException {
            return new Data(name);
        }
    }

    public static void main(String[] args) {
        new Thread(new PB()).start();
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
        Data data = Data.files("b");

        int t = data.nextInt();
        for (int i = 0; i < t; ++i) {
            long x = data.nextLong();
            long res = subsolve(x);
            data.println(String.format("Case #%d: %s", i + 1, res));
        }

        data.close();
    }

    private long pow10(int k) {
        long res = 1;
        for (int i = 0; i < k; ++i) {
            res = res * 10L;
        }
        return res;
    }

    private long rep(long d, int k) {
        long res = 0;
        for (int i = 0; i < k; ++i) {
            res = res * 10L + d;
        }
        return res;
    }

    private long subsolve(long x) {
        long res = 0;
        long prevd = 0;
        for (int i = 18; i >= 1; --i) {
            for (long d = 9; d >= prevd; --d) {
                long ures = res + rep(d, i);
                if (ures <= x) {
                    res += d * pow10(i - 1);
                    prevd = d;
                    break;
                }
            }
        }
        return res;
    }
}
