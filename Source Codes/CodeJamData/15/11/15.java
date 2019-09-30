import java.io.*;
import java.util.StringTokenizer;

public class PA implements Runnable {
    static String PROBLEM_NAME = PA.class.getSimpleName().toLowerCase();
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
            new Thread(new PA()).start();
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
            int n = rd.nextInt();
            int[] m = new int[n];
            for (int i = 0; i < n; ++i) {
                m[i] = rd.nextInt();
            }
            String result = subsolve(m);
            wr.println(String.format("Case #%d: %s", ti + 1, result));
        }

        rd.close();
        wr.close();
    }

    private String subsolve(int[] m) {
        int result1 = 0;
        int n = m.length;
        for (int i = 1; i < n; ++i) {
            if (m[i] < m[i - 1]) {
                result1 += m[i - 1] - m[i];
            }
        }

        int r10 = 0;
        for (int i = 1; i < n; ++i) {
            if (m[i] < m[i - 1]) {
                r10 = Math.max(r10, m[i - 1] - m[i]);
            }
        }

        int result2 = 0;
        for (int i = 0; i < n - 1; ++i) {
            result2 += Math.min(r10, m[i]);
        }

        return String.format("%d %d", result1, result2);
    }
}