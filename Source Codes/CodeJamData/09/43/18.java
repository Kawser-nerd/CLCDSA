import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Comparator;
import java.util.regex.Pattern;

public class C implements Runnable {

    // all files <INPUT_PREFIX>-*.in will be solved
    private static final String INPUT_PREFIX = "C";
    private static final String OUTPUT_SUFFIX = "-default";

    private class TestCaseSolver {

        int n;
        int[][] a;
        boolean[] was;
        int[] f;

        private void solve() {
            n = nextInt();
            final int m = nextInt();

            int[][] nums = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    nums[i][j] = nextInt();
                }

            Arrays.sort(nums, new Comparator<int[]>() {
                public int compare(int[] x, int[] y) {
                    for (int i = 0; i < m; i++) {
                        int t = x[i] - y[i];
                        if (t != 0) {
                            return t;
                        }
                    }
                    return 0;
                }
            });

            a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (less(nums[i], nums[j]) && intersect(nums[i], nums[j])) {
                        a[i][j] = 1;
                    }

            was = new boolean[n];
            f = new int[n];
            Arrays.fill(f, -1);

            int answer = 0;
            for (int i = 0; i < n; i++) {
                Arrays.fill(was, false);
                if (xtry(i)) {
                    answer++;
                }
            }

            out.print(' ');
            out.print(n - answer);
        }

        private boolean less(int[] x, int[] y) {
            int m = x.length;
            for (int i = 0; i < m; i++)
                if (x[i] >= y[i]) {
                    return false;
                }
            return true;
        }

        boolean xtry(int u) {
            if (was[u]) return false;
            was[u] = true;

            for (int v = 0; v < n; v++)
                if ((a[u][v] > 0) && (f[v] == -1 || xtry(f[v]))) {
                    f[v] = u;
                    return true;
                }

            return false;
        }

        private boolean intersect(int[] x, int[] y) {
            return true;
            /*
            int m = x.length;
            for (int i = 0; i < m; i++)
                if (x[i] == y[i]) {
                    return true;
                }

            for (int i = 0; i < m - 1; i++) {
                int d1 = sig(x[i] - y[i]);
                int d2 = sig(x[i + 1] - y[i + 1]);
                if (d1 != d2) {
                    return true;
                }
            }

            return false;
            */
        }

        private int sig(int x) {
            if (x < 0) {
                return -1;
            }
            if (x > 0) {
                return 1;
            }
            return 0;
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
            new C.TestCaseSolver().solve();
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
        new Thread(new C()).start();
    }
}
