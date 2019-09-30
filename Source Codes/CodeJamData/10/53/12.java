import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C implements Runnable {

    private static final String PROBLEM_ID = "C";

    private class TestCaseRunner {

        class Pair implements Comparable<Pair> {
            int p, v;

            Pair(int p, int v) {
                this.p = p;
                this.v = v;
            }

            public int compareTo(Pair that) {
                if (this.v > that.v) return -1;
                if (this.v < that.v) return 1;
                if (this.p > that.p) return -1;
                if (this.p < that.p) return 1;
                return 0;
            }

        }

        int n;
        TreeSet<Pair> set = new TreeSet<Pair>();
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();

        public void handleCase() throws IOException {
            n = nextInt();
            for (int i = 0; i < n; i++) {
                int p = nextInt();
                int v = nextInt();

                set.add(new Pair(p, v));
                count.put(p, v);
            }

            int result = 0;
            for (;;) {
                Pair p = set.pollFirst();
                if (p.v <= 1) {
                    break;
                }
                result++;

                // current
                p.v -= 2;
                set.add(p);
                count.put(p.p, p.v);

                // left
                {
                    int nP = p.p - 1;
                    process(nP);
                }

                // right
                {
                    int nP = p.p + 1;
                    process(nP);
                }
            }

            out.print(result);
        }

        private void process(int nP) {
            if (!count.containsKey(nP)) {
                count.put(nP, 1);
                set.add(new Pair(nP, 1));
            } else {
                int nV = count.get(nP);
                Pair newPair = new Pair(nP, nV);
                boolean removed = set.remove(newPair);
                if (!removed) {
                    throw new IllegalStateException();
                }
                newPair.v++;
                set.add(newPair);
                count.put(newPair.p, newPair.v);
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