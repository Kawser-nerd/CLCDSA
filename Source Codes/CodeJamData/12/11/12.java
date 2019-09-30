import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
    private static final String TASKNAME = "a";

    private void solve() throws Exception {
        int tests = nextInt();
        for (int test = 1; test <= tests; ++test) {
            printf("Case #%d: ", test);
            int a = nextInt();
            int b = nextInt();
            double[] p = new double[a + 1];
            p[0] = 1;
            for (int i = 0; i < a; ++i) {
                p[i + 1] = p[i] * nextDouble();
            }
            double ans = 2 + b;
            for (int i = a; i >= 0; --i) {
                ans = Math.min(ans, (a - i + b - i + 1) * p[i] + (a - i + b - i + 1 + b + 1) * (1 - p[i]));
            }
            printf("%.20f\n", ans);
        }
    }

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(new OutputStreamWriter(System.out));
            reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
            writer = new PrintWriter(new File(TASKNAME + ".out"));

            solve();

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(13);
        }
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Locale.setDefault(Locale.US);
        new Main().run();
        System.err.printf("%.3f\n", (System.currentTimeMillis() - time) * 1e-3);
    }

    private StringTokenizer tokenizer;
    private PrintWriter writer;
    private BufferedReader reader;

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private void print(Object o) {
        writer.print(o);
    }

    private void println(Object o) {
        writer.println(o);
    }

    private void printf(String format, Object... args) {
        writer.printf(format, args);
    }
}
