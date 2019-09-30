import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class C implements Runnable {

    private static final String PROBLEM_ID = "C";

    static int[][] cache = new int [600][600];

    static {
        for (int[] v : cache) {
            Arrays.fill(v, -1);
        }
    }

    private class TestCaseRunner {

        int n, ans;

        int cnt;
        int[] a = new int[1000];

        public void handleCase() throws IOException {
            n = nextInt() - 1;

            // rec(0, 2);
            // out.print(ans % 100003);

            ans = 0;
            for (int i = 0; i < n; i++) {
                ans += f(i, n - i);
            }

            out.print(ans % 100003);
        }

        private int f(int n, int m) {
            if (n < 0) {
                return 0;
            }
            if (m < 0) {
                throw new IllegalStateException();
            }
            if (n == 0) {
                return 1;
            }
            if (m == 0) {
                return 0;
            }

            if (cache[n][m] != -1) {
                return cache[n][m];
            }

            int res = 0;
            for (int i = 1; i <= m; i++) {
                res += f(n - i, m);
                res %= 100003;
            }

            cache[n][m] = res;
            return res;
        }

        private void rec(int pos, int num) {
            if (num > n) {
                analyse();
                return;
            }

            rec(pos + 1, num + 1);

            a[cnt++] = num;
            rec(pos + 1, num + 1);
            cnt--;
        }

        private void analyse() {
            int p = n;
            for (;;) {
                int idx = -1;
                for (int i = 0; i < cnt; i++)
                    if (a[i] == p) {
                        idx = i;
                        break;
                    }

                if (idx == -1) {
                    return;
                }

                if (idx == 0) {
                    ans++;
                    return;
                }

                p = idx + 1;
            }
        }

    }


    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(new C()).start();
    }

    public void run() {
        File[] all = new File(".").listFiles();
        Arrays.sort(all, new Comparator<File>() {
            public int compare(File a, File b) {
                return a.getName().toLowerCase().compareTo(b.getName().toLowerCase());
            }
        });

        int processed = 0;
        for (File inFile : all)
            if (inFile.isFile()) {
                String name = inFile.getName().toLowerCase();
                if (name.startsWith(PROBLEM_ID.toLowerCase()) && name.endsWith(".in")) {
                    try {
                        runFile(inFile);
                        processed++;
                    } catch (Throwable t) {
                        throw new IllegalStateException("Fatal error", t);
                    }
                }
            }

        if (processed > 0) {
            System.out.println("Processed " + processed + " files for problem " + PROBLEM_ID);
        } else {
            System.err.println("No input files found for problem " + PROBLEM_ID);
        }
    }

    private void runFile(File inFile) throws IOException {
        in = new BufferedReader(new FileReader(inFile));
        out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        long startTime = System.currentTimeMillis();

        System.out.println("Processing file: " + inFile.getName());
        int tc = nextInt();
        for (int p = 0; p < tc; p++) {
            long nowTime = System.currentTimeMillis();
            System.out.print("Running test case #" + (p + 1) + " out of " + tc);
            if (p > 0) {
                System.out.print(" (remaining time: " + remainingTime(p, tc, startTime, nowTime) + ")");
            }
            System.out.println();

            out.print("Case #" + (p + 1) + ": ");
            new TestCaseRunner().handleCase();
            out.println();
        }

        in.close();
        out.close();
    }


    private String remainingTime(int p, int tc, long startTime, long nowTime) {
        double secondsPerTestCase = 1.0 * (nowTime - startTime) / p;
        double secondsRemaining = (tc - p) * secondsPerTestCase;
        double minutesRemaining = secondsRemaining / 60;

        int minutes = (int) Math.floor(minutesRemaining);
        int seconds = (int) Math.round(secondsRemaining - minutes * 60);
        return minutes + " min " + seconds + " sec";
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private BigInteger nextBigInt() throws IOException {
        return new BigInteger(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}