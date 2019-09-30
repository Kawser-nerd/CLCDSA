import java.io.*;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class A implements Runnable {

    // all files <INPUT_PREFIX>-*.in will be solved
    private static final String INPUT_PREFIX = "A";
    private static final String OUTPUT_SUFFIX = "-default";

    private class TestCaseSolver {

        int n;
        String[] a;
        
        private void solve() {
            n = nextInt();
            a = new String[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextToken();
            }

            int answer = 0;
            for (int i = 0; i < n; i++) {
                if (canPut(i, i)) {
                    // leave everything as is
                } else {
                    // find and swap
                    boolean found = false;
                    for (int j = i + 1; j < n; j++)
                        if (canPut(i, j)) {

                            for (int k = j - 1; k >= i; k--) {
                                swap(k, k + 1);
                                answer++;
                            }

                            found = true;
                            break;
                        }

                    if (!found) {
                        throw new IllegalStateException();
                    }
                }
            }
            out.print(' ');
            out.print(answer);
        }

        private void swap(int i, int j) {
            String t = a[i];
            a[i] = a[j];
            a[j] = t;
        }

        private boolean canPut(int row, int sIdx) {
            for (int j = 0; j < n; j++)
                if (j > row && a[sIdx].charAt(j) == '1') {
                    return false;
                }
            return true;
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
            out = new PrintWriter(new FileWriter(inFile.getName() + OUTPUT_SUFFIX + ".out"));
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
            new A.TestCaseSolver().solve();
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
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(INPUT_PREFIX) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
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
        new Thread(new A()).start();
    }
}
