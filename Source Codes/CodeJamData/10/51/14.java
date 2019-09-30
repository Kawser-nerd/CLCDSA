import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final String PROBLEM_ID = "A";

    static int MAXP;
    static boolean[] IS_PRIME;

    static {
        MAXP = 1000000;
        IS_PRIME = new boolean[MAXP];

        Arrays.fill(IS_PRIME, true);
        IS_PRIME[0] = false;
        IS_PRIME[1] = false;
        for (int i = 2; i < MAXP; i++)
            if (IS_PRIME[i])
                for (int j = i + i; j < MAXP; j += i) {
                    IS_PRIME[j] = false;
                }
    }

    private class TestCaseRunner {

        int d, dd, n;
        long[] a;
        boolean[] may;

        public void handleCase() throws IOException {
            d = nextInt();
            n = nextInt();
            a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }

            dd = (int) Math.round(Math.pow(10, d));
            may = new boolean[dd];
            for (int p = 0; p < dd; p++)
                if (IS_PRIME[p]) {
                    process(p);
                }

            String result = "I don't know.";
            int count = 0;
            int answer = 0;
            for (int i = 0; i < dd; i++)
                if (may[i]) {
                    count++;
                    answer = i;
                }

            if (count == 1) {
                result = Integer.toString(answer);
            }

            out.print(result);
        }

        private void process(int p) {
            for (long v : a)
                if (v < 0 || v >= p) {
                    return;
                }


            if (n == 1) {
                for (int i = 0; i < p; i++) {
                    may[i] = true;
                }
                return;
            }

            if (n == 2) {
                if (a[0] == a[1]) {
                    may[(int)a[0]] = true;
                } else {
                    for (int i = 0; i < p; i++) {
                        may[i] = true;
                    }
                }
                return;
            }

            for (int i = 0; i < n - 1; i++)
                if (a[i] == a[i + 1]) {
                    may[(int)a[i]] = true;

                    /*
                    for (int j = i + 1; j < n; j++)
                        if (a[j] != a[i]) {
                            throw new IllegalStateException();
                        }
                        */
                    
                    return;
                }


            long x = ((a[0] - a[1]) % p + p) % p;
            long y = ((a[1] - a[2]) % p + p) % p;

            Pair result = new Pair();
            gcd(p, x, result);

            long beta = (result.y % p + p) % p;
            long A = ((y * beta) % p + p) % p;
            long B = ((a[1] - A * a[0]) % p + p) % p;

            for (int i = 0; i < n - 1; i++) {
                long next = ((a[i] * A + B) % p + p) % p;
                if (next != a[i + 1]) {
                    // System.out.println("*");
                    return;
                    // throw new IllegalStateException();
                }
            }

            long next = ((a[n - 1] * A + B) % p + p) % p;
            may[(int) next] = true;
        }

        class Pair {
            long x, y;
        }

        long gcd(long a, long b, Pair p) {
            if (a == 0) {
                p.x = 0;
                p.y = 1;
                return b;
            }
            Pair nP = new Pair();
            long d = gcd(b % a, a, nP);
            p.x = nP.y - (b / a) * nP.x;
            p.y = nP.x;
            return d;
        }

    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(new A()).start();
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