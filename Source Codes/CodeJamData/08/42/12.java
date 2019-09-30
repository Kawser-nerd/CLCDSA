import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

/**
 * @author Roman
 */
public class B implements Runnable {

    public static final String PROBLEM_ID = "B";

    private class ProblemSolver {

        private void solveOne() throws IOException {
            int n = nextInt();
            int m = nextInt();
            int a = nextInt();

            int x1 = 0; int y1 = 0;
            for (int x2 = -n; x2 <= n; x2++)
                for (int y2 = -m; y2 <= m; y2++)
                    for (int x3 = -n; x3 <= n; x3++)
                        for (int y3 = -m; y3 <= m; y3++) {
                            int s = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
                            if (s < 0) s = -s;
                            if (s == a) {
                                int dx1 = x1, dx2 = x2, dx3 = x3;
                                int dy1 = y1, dy2 = y2, dy3 = y3;

                                int move;

                                move = 0;
                                if (x2 < 0) move = Math.max(move, -x2);
                                if (x3 < 0) move = Math.max(move, -x3);
                                if (move > 0) {
                                    dx1 += move;
                                    dx2 += move;
                                    dx3 += move;
                                }
                                if (dx1 > n || dx2 > n || dx3 > n) {
                                    continue;
                                }

                                move = 0;
                                if (y2 < 0) move = Math.max(move, -y2);
                                if (y3 < 0) move = Math.max(move, -y3);
                                if (move > 0) {
                                    dy1 += move;
                                    dy2 += move;
                                    dy3 += move;
                                }
                                if (dy1 > m || dy2 > m || dy3 > m) {
                                    continue;
                                }

                                int sConfirm = dx1 * (dy2 - dy3) + dx2 * (dy3 - dy1) + dx3 * (dy1 - dy2);
                                if (sConfirm < 0) sConfirm = -sConfirm;

                                if (s != sConfirm) {
                                    throw new IllegalStateException();
                                }

                                out.print(dx1);
                                out.print(' ');
                                out.print(dy1);
                                out.print(' ');
                                out.print(dx2);
                                out.print(' ');
                                out.print(dy2);
                                out.print(' ');
                                out.print(dx3);
                                out.print(' ');
                                out.print(dy3);
                                return;
                            }
                        }
            out.print("IMPOSSIBLE");
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
        new B.ProblemSolver().solve();
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
        new Thread(new B()).start();
    }

}
