import java.io.*;
import java.util.regex.Pattern;
import java.util.StringTokenizer;
import java.util.Arrays;

/**
 * @author Roman
 */
public class A implements Runnable {

    public static final String PROBLEM_ID = "A";

    private class ProblemSolver {

        static final int AND = 1;
        static final int OR = 2;

        int m, v, interior;
        int[] gateType;
        boolean[] gateChangeable;
        int[] leafValue;
        int[][] d;
        boolean[] calculated;

        private void solveOne() throws IOException {
            m = nextInt();
            v = nextInt();
            interior = (m - 1) / 2;
            gateType = new int[interior + 1];
            gateChangeable = new boolean[interior + 1];
            for (int i = 1; i <= interior; i++) {
                int g = nextInt();
                int c = nextInt();
                gateType[i] = g == 1 ? AND : OR;
                gateChangeable[i] = (c == 1);
            }
            leafValue = new int[m + 1];
            for (int i = interior + 1; i <= m; i++) {
                leafValue[i] = nextInt();
            }
            calculated = new boolean[m + 1];
            d = new int[m + 1][2];
            for (int[] a : d) {
                Arrays.fill(a, Integer.MAX_VALUE);
            }
            rec(1);

            if (d[1][v] >= Integer.MAX_VALUE) {
                out.print("IMPOSSIBLE");
            } else {
                out.print(d[1][v]);
            }
        }

        private void rec(int p) {
            if (calculated[p]) {
                return;
            }

            if (p > interior) {
                d[p][ leafValue[p] ] = 0;
            } else {

                int l = p << 1;
                int r = l + 1;
                rec(l);
                rec(r);

                int type = gateType[p];
                if (type == AND) {
                    for (int lv = 0; lv <= 1; lv++)
                        for (int rv = 0; rv <= 1; rv++) {
                            if (d[l][lv] >= Integer.MAX_VALUE || d[r][rv] >= Integer.MAX_VALUE) {
                                continue;
                            }
                            int pv = lv & rv;
                            d[p][pv] = Math.min(d[p][pv], d[l][lv] + d[r][rv]);
                        }
                } else {
                    for (int lv = 0; lv <= 1; lv++)
                        for (int rv = 0; rv <= 1; rv++) {
                            if (d[l][lv] >= Integer.MAX_VALUE || d[r][rv] >= Integer.MAX_VALUE) {
                                continue;
                            }
                            int pv = lv | rv;
                            d[p][pv] = Math.min(d[p][pv], d[l][lv] + d[r][rv]);
                        }
                }

                if (gateChangeable[p]) {
                    if (type == AND) {
                        for (int lv = 0; lv <= 1; lv++)
                            for (int rv = 0; rv <= 1; rv++) {
                                if (d[l][lv] >= Integer.MAX_VALUE || d[r][rv] >= Integer.MAX_VALUE) {
                                    continue;
                                }
                                int pv = lv | rv;
                                d[p][pv] = Math.min(d[p][pv], d[l][lv] + d[r][rv] + 1);
                            }
                    } else {
                        for (int lv = 0; lv <= 1; lv++)
                            for (int rv = 0; rv <= 1; rv++) {
                                if (d[l][lv] >= Integer.MAX_VALUE || d[r][rv] >= Integer.MAX_VALUE) {
                                    continue;
                                }
                                int pv = lv & rv;
                                d[p][pv] = Math.min(d[p][pv], d[l][lv] + d[r][rv] + 1);
                            }
                    }

                }
            }

            calculated[p] = true;
        }

        public void solve() throws Throwable {
            int tc = nextInt();
            for (int t = 0; t < tc; t++) {
                out.print("Case #" + (t + 1) + ": ");
                solveOne();
                out.println();
            }
        }

    }

    public static final String PROBLEM_IN_SUFFIX = ".in";
    public static final String PROBLEM_OUT_SUFFIX = ".out";
    public static final Pattern PROBLEM_FILE_PATTERN = Pattern.compile("^" + PROBLEM_ID + ".*" + PROBLEM_IN_SUFFIX + "$", Pattern.CASE_INSENSITIVE);

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
        new A.ProblemSolver().solve();
    }

    private void solve(String fileName) {
        try {
            in = new BufferedReader(new FileReader(fileName));
            out = new PrintWriter(new FileWriter(fileName + PROBLEM_OUT_SUFFIX));

            solveFile();

            in.close();
            out.close();
        } catch (Throwable t) {
            t.printStackTrace();
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
        new Thread(new A()).start();
    }

}
