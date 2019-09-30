import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String PROBLEM_ID = "B";

    private class TestCaseRunner {

        int n, k, b, t;
        int[] x, v, own;
        boolean[] was;

        public void handleCase() throws IOException {
            n = nextInt();
            k = nextInt();
            b = nextInt();
            t = nextInt();

            x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }

            v = new int[n];
            for (int i = 0; i < n; i++) {
                v[i] = nextInt();
            }

            own = new int[n];
            for (int i = 0; i < n; i++) {
                own[i] = x[i] + v[i] * t;
            }

            int total = 0;
            int swaps = 0;
            was = new boolean[n];
            for (;;) {
                if (total >= k) {
                    break;
                }

                int minI = -1;
                int minD = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++)
                    if (!was[i]) {
                        int d = jumps(i);
                        if (d < minD) {
                            minD = d;
                            minI = i;
                        }
                    }

                if (minI == -1) {
                    break;
                }

                total++;
                swaps += minD;
                was[minI] = true;
            }

            if (total < k) {
                out.print("IMPOSSIBLE");
            } else {
                out.print(swaps);
            }
        }

        private int jumps(int u) {
            if (own[u] < b) {
                return Integer.MAX_VALUE;
            }
            int res = 0;
            for (int i = u + 1; i < n; i++)
                if (own[i] < b) {
                    res++;    
                }
            return res;
        }

    }


    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(new B()).start();
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