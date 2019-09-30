import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String PROBLEM_ID = "B";

    private class TestCaseRunner {

        int n;
        long l;
        int[] a;
        int DROP_TO = 100000;

        public void handleCase() throws IOException {
            l = nextLong();
            n = nextInt();
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }

            Arrays.sort(a);
            int mx = a[n - 1];

            long k = Math.round(1.0 * (l - DROP_TO) / mx);
            while (l - k * mx >= DROP_TO) {
                k++;
            }

            l -= k * mx;

            long[] d = new long[DROP_TO];
            d[0] = 0;
            for (int i = 1; i < DROP_TO; i++) {
                d[i] = Long.MAX_VALUE;
                for (int j = 0; j < n; j++)
                    if (i - a[j] >= 0) {
                        long t = d[i - a[j]];
                        if (t >= Long.MAX_VALUE) {
                            continue;
                        }

                        d[i] = Math.min(d[i], t + 1);
                    }
            }

            if (d[(int)l] >= Long.MAX_VALUE) {
                out.print("IMPOSSIBLE");
            } else {
                long answer = k + d[(int)l];
                out.print(answer);
            }
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
        double secondsPerTestCase = 1.0e-3 * (nowTime - startTime) / p;
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