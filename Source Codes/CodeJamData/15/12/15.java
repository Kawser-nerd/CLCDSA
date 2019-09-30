import java.io.*;
import java.util.StringTokenizer;

public class PB implements Runnable {
    static String PROBLEM_NAME = PB.class.getSimpleName().toLowerCase();
    static String INPUT_FILE_NAME = PROBLEM_NAME + ".in";
    static String OUTPUT_FILE_NAME = PROBLEM_NAME + ".out";

    static class InputReader {
        final BufferedReader rd;
        StringTokenizer tok = null;

        public InputReader(String filename) throws IOException {
            rd = new BufferedReader(new FileReader(new File(filename)));
        }

        public void close() {
            try {
                rd.close();
            } catch (IOException e) {
            }
        }

        public String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public String readLine() throws IOException {
            tok = null;
            return rd.readLine();
        }
    }

    public static void main(String[] args) {
        try {
            new Thread(new PB()).start();
        } catch (Exception e) {
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void solve() throws IOException {
        InputReader rd = new InputReader(INPUT_FILE_NAME);
        PrintWriter wr = new PrintWriter(new FileWriter(new File(OUTPUT_FILE_NAME)));

        int t = rd.nextInt();
        for (int ti = 0; ti < t; ++ti) {
            int b = rd.nextInt();
            long n = rd.nextInt();
            long[] m = new long[b];
            for (int i = 0; i < b; ++i) {
                m[i] = rd.nextInt();
            }
            wr.println(String.format("Case #%d: %d", ti + 1, subsolve(n, m)));
        }

        rd.close();
        wr.close();
    }

    private long f(long t, long[] m) {
        int b = m.length;
        long p = 0;
        for (int i = 0; i < b; ++i) {
            p += 1l + (t / m[i]);
        }
        return p;
    }

    private int subsolve(long n, long[] m) {
        int b = m.length;
        if (n <= b) {
            return (int)n;
        }

        long l = 0;
        long r = 100000L * n;
        while (r - l > 1) {
            long c = (l + r) / 2L;
            long p = f(c, m);
            if (p >= n) {
                r = c;
            } else {
                l = c;
            }
        }
        long rn = n - f(l, m);
        for (int i = 0; i < b; ++i) {
            if (r % m[i] == 0) {
                if (rn == 1) {
                    return i + 1;
                }
                --rn;
            }
        }
        return -1;
    }
}