import java.util.regex.Pattern;
import java.util.*;
import java.io.*;

/**
 * @author Roman
 */
public class B implements Runnable {

    public static final String PROBLEM_ID = "B";

    // START of shared data between test cases

    // END of shared data between test cases

    /**
     * New instance is created for each test case
     */
    private class TestCaseSolver {

        class Data implements Comparable<Data> {
            int color, a, b;

            public Data(int color, int a, int b) {
                this.color = color;
                this.a = a;
                this.b = b;
            }

            public int compareTo(Data that) {
                int t = this.a - that.a;
                if (t != 0) return t;
                return that.b - this.b;
            }

        }

        Map<String, Integer> colors = new HashMap<String, Integer>();

        int getColorIdx(String color) {
            Integer result = colors.get(color);
            if (result == null) {
                result = colors.size();
                colors.put(color, result);
            }
            return result;
        }

        int n, m;
        Data[] a;
        int[] colorCoverage;
        int answer = Integer.MAX_VALUE;

        // Solves test case
        public void solve() throws Throwable {
            n = nextInt();
            a = new Data[n];
            for (int i = 0; i < n; i++) {
                String color = nextToken();
                int colorIdx = getColorIdx(color);
                int l = nextInt();
                int r = nextInt();
                a[i] = new Data(colorIdx, l ,r);                
            }

            Arrays.sort(a);

            m = colors.size();
            colorCoverage = new int[m];
            for (int i = 0; i < n; i++) {
                colorCoverage[ a[i].color ] += a[i].b - a[i].a + 1;
            }

            for (int c1 = 0; c1 < m; c1++)
                for (int c2 = c1; c2 < m; c2++)
                    for (int c3 = c2; c3 < m; c3++) {
                        if (answer <= 1) {
                            break;
                        }
                        int result = solve(c1, c2, c3);
                        answer = Math.min(answer, result);
                    }

            if (answer == Integer.MAX_VALUE) {
                out.print("IMPOSSIBLE");
            } else {
                out.print(answer);
            }
        }

        final int FENCE_SIZE = 10000;

        private int solve(int c1, int c2, int c3) {
            if (c1 == c2 || c1 == c3) {
                c1 = -1;
            }
            if (c2 == c1 || c2 == c3) {
                c2 = -1;
            }
            if (c3 == c1 || c3 == c2) {
                c3 = -1;
            }

            int total = 0;
            if (c1 >= 0) {
                total += colorCoverage[c1];
            }
            if (c2 >= 0) {
                total += colorCoverage[c2];
            }
            if (c3 >= 0) {
                total += colorCoverage[c3];
            }

            if (total < FENCE_SIZE) {
                return Integer.MAX_VALUE;
            }

            int result = 0;
            int lastR = 0;

            int i = 0;
            while (i < n && lastR < FENCE_SIZE) {

                int lastPaintedR = lastR;
                
                int j = i;
                while (j < n && a[j].a <= lastR + 1) {
                    if (a[j].color == c1 || a[j].color == c2 || a[j].color == c3) {
                        lastPaintedR = Math.max(lastPaintedR, a[j].b);
                        if (lastPaintedR >= FENCE_SIZE) {
                            break;
                        }
                    }
                    j++;
                }

                if (lastPaintedR <= lastR) {
                    return Integer.MAX_VALUE;
                }

                result++;
                lastR = lastPaintedR;

                if (result > answer) {
                    return Integer.MAX_VALUE;
                }

                i = j;
            }

            if (lastR >= FENCE_SIZE) {
                return result;
            }

            return Integer.MAX_VALUE;
        }

    }

    // Template goes below
    public static final String PROBLEM_IN_SUFFIX = ".in";
    public static final String PROBLEM_OUT_SUFFIX = ".out";
    public static final Pattern PROBLEM_FILE_PATTERN = Pattern.compile("^" + PROBLEM_ID + ".*" + PROBLEM_IN_SUFFIX + "$", Pattern.CASE_INSENSITIVE);

    static {
        Locale.setDefault(Locale.ENGLISH);
    }


    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer;

    private String nextLine() throws IOException {
        return in.readLine();
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = nextLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        String token = nextToken();
        return Integer.parseInt(token);
    }

    private void solveFile() throws Throwable {
        tokenizer = new StringTokenizer("");
        int tc = nextInt();
        for (int t = 0; t < tc; t++) {
            System.out.println("Progress: #" + (t + 1) + " out of " + tc);

            out.print("Case #" + (t + 1) + ": ");
            new B.TestCaseSolver().solve();
            out.println();
        }
    }

    private void solve(String fileName) {
        try {
            System.out.println("Solving " + fileName);

            in = new BufferedReader(new FileReader(fileName));
            out = new PrintWriter(new FileWriter(fileName + PROBLEM_OUT_SUFFIX));

            solveFile();

            in.close();
            out.close();
        } catch (Throwable t) {
            t.printStackTrace();
            System.out.flush();
            System.err.flush();
            System.exit(-1);
        }
    }

    public void run() {
        File dir = new File(".");
        FilenameFilter filter = new FilenameFilter() {
            public boolean accept(File file, String name) {
                return PROBLEM_FILE_PATTERN.matcher(name).matches();
            }
        };
        String[] children = dir.list(filter);
        if (children != null) {
            for (String file : children) {
                solve(file);
            }
        }
    }

    public static void main(String[] args) {
        new Thread(new B()).start();
    }

}
