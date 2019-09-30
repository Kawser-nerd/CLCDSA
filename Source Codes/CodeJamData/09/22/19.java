import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class BWrong2 implements Runnable {

    private class TestCaseSolver {

        private BigInteger solve(String s, String min) {
            BigInteger n = new BigInteger(min);

            char[] c = s.toCharArray();

            BigInteger result = null;
            for (int i = 0; i < c.length; i++) {
                for (int j = 0; j < c.length; j++)
                    if (true) {
                        char[] cClone = c.clone();

                        char x = cClone[i]; cClone[i] = cClone[j]; cClone[j] = x;
                        Arrays.sort(cClone, i + 1, c.length);

                        BigInteger cur = new BigInteger(new String(cClone));
                        if (cur.compareTo(n) > 0) {
                            if (result == null || cur.compareTo(result) < 0) {
                                result = cur;
                            }
                        }

                    }
            }

            return result;
        }

        private void solve() {
            String s = nextToken();

            BigInteger result = solve(s, s);
            if (result == null) {
                char[] c = s.toCharArray();
                Arrays.sort(c);

                result = solve(new String(c) + "0", s);
            }

            out.print(" " + result);
        }

    }

    private BufferedReader in;
    private PrintWriter out;

    private StringTokenizer tokenizer = new StringTokenizer("");

    private String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private int estimatedTimeLeft(int tc, int tCount, long timeStart) {
        long time = System.currentTimeMillis();
        double timePerTest = (1.0 * (time - timeStart)) / tc;
        return (int) (timePerTest * (tCount - tc) / 1000.0);
    }

    private void solve(File inFile) {
        long timeStart = System.currentTimeMillis();

        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }

        int tCount = nextInt();
        for (int tc = 0; tc < tCount; tc++) {
            System.out.print("Solving test case #" + (tc + 1) + "/" + tCount);
            if (tc > 0) {
                System.out.print(", estimated time left: " + estimatedTimeLeft(tc, tCount, timeStart) + " sec");
            }
            System.out.println();

            out.print("Case #" + (tc + 1) + ":");
            new BWrong2.TestCaseSolver().solve();
            out.println();
        }

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote("B") + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
        final File[] inFiles = new File(".").listFiles(
            new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return inPattern.matcher(name).matches();
                }
            }
        );
        for (File inFile : inFiles) {
            System.out.println("Solving [" + inFile.getName() + ']');
            solve(inFile);
        }
    }

    public static void main(String[] args) {
        new Thread(new BWrong2()).start();
    }
}
