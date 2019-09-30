import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
    private static final String TASKNAME = "b";

    private void solve() throws Exception {
        int tests = nextInt();
        test:
        for (int test = 1; test <= tests; ++test) {
            printf("Case #%d: ", test);
            int n = nextInt();
            int[][] need = new int[2][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    need[j][i] = nextInt();
                }
            }
            int[] level = new int[n];
            int stars = 0;
            int done = 0;
            while (true) {
                boolean found = false;
                j:
                for (int j = 1; j >= 0; --j) {
                    int ind = -1;
                    for (int i = 0; i < n; ++i) {
                        if (level[i] <= j && stars >= need[j][i]) {
                            if (ind == -1 || need[1][ind] < need[1][i]) {
                                ind = i;
                            }
                        }
                    }
                    if (ind >= 0) {
                        stars += j + 1 - level[ind];
                        level[ind] = j + 1;
                        ++done;
                        found = true;
                        break j;
                    }
                }
                if (!found) {
                    break;
                }
            }
            for (int i : level) {
                if (i != 2) {
                    println("Too Bad");
                    continue test;
                }
            }
            println(done);
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
