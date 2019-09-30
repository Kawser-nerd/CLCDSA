import java.util.Locale;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.regex.Pattern;
import java.io.*;

/**
 * @author Roman
 */
public class D implements Runnable {

    static {
        Locale.setDefault(Locale.ENGLISH);
    }

    public static final String PROBLEM_ID = "D";

    private class ProblemSolver {

        int MODULO = 10007;

        private void solveOne() throws IOException {
            int h = nextInt();
            int w = nextInt();

            int[][] d = new int[h][w];
            int[][] block = new int[h][w];

            int blocks = nextInt();
            for (int p = 0; p < blocks; p++) {
                int row = nextInt();
                int col = nextInt();
                block[row - 1][col - 1] = 1;
            }

            for (int[] v : d) {
                Arrays.fill(v, -1);
            }
            d[0][0] = 1;
            for (int r = 0; r < h; r++)
                for (int c = 0; c < w; c++)
                    if (d[r][c] != -1) {
                        int nr, nc;

                        nr = r + 1;
                        nc = c + 2;
                        if (nr < h && nc < w && block[nr][nc] == 0) {
                            if (d[nr][nc] == -1) {
                                d[nr][nc] = 0;
                            }
                            d[nr][nc] += d[r][c];
                            d[nr][nc] %= MODULO;
                        }

                        nr = r + 2;
                        nc = c + 1;
                        if (nr < h && nc < w && block[nr][nc] == 0) {
                            if (d[nr][nc] == -1) {
                                d[nr][nc] = 0;
                            }
                            d[nr][nc] += d[r][c];
                            d[nr][nc] %= MODULO;
                        }
                    }


            if (d[h - 1][w - 1] == -1) {
                d[h - 1][w - 1] = 0;
            }
            out.print(d[h - 1][w - 1] % MODULO);
        }

        public void solve() throws Throwable {
            int tc = nextInt();
            for (int t = 0; t < tc; t++) {
                System.out.println("Progress: #" + (t + 1) + " out of " + tc);

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
        new D.ProblemSolver().solve();
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
        new Thread(new D()).start();
    }

}
