import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.regex.Pattern;

/**
 * @author Roman
 */
public class C implements Runnable {

    static {
        Locale.setDefault(Locale.ENGLISH);
    }

    public static final String PROBLEM_ID = "C";

    private class ProblemSolver {

        int h, w;
        int[] forbiddenMask;
        int[][] d;

        private boolean canPlace(int r, int mask, int p) {
            if ((mask & (1 << p)) != 0) {
                return false;
            }
            if ((forbiddenMask[r] & (1 << p)) != 0) {
                return false;
            }
            return true;
        }

        private void rec(int r, int mask, int nMask, int p, int count) {
            if (p >= w) {
                d[r + 1][nMask] = Math.max(d[r + 1][nMask], count);
                return;
            }

            if (canPlace(r, mask, p)) {
                int maskX = mask;
                if (p - 1 >= 0) maskX |= 1 << (p - 1);
                maskX |= 1 << p;
                if (p + 1 < w) maskX |= 1 << (p + 1);

                int nMaskX = nMask;
                if (p - 1 >= 0) nMaskX |= 1 << (p - 1);
                if (p + 1 < w) nMaskX |= 1 << (p + 1);

                rec(r, maskX, nMaskX, p + 1, count + 1);
            }

            rec(r, mask, nMask, p + 1, count);
        }

        private void solveOne() throws IOException {
            h = nextInt();
            w = nextInt();
            forbiddenMask = new int[h];
            for (int i = 0; i < h; i++) {
                String s = nextToken().trim();
                if (s.length() != w) {
                    throw new IllegalStateException();
                }

                int fMask = 0;
                char[] c = s.toCharArray();
                for (int j = 0; j < w; j++)
                    if (c[j] == 'x') {
                        fMask |= 1 << j;
                    }
                forbiddenMask[i] = fMask;
            }

            int l = 0;
            int r = h - 1;
            while (l < r) {
                int t = forbiddenMask[l];
                forbiddenMask[l] = forbiddenMask[r];
                forbiddenMask[r] = t;
                l++;
                r--;
            }

            int w2 = 1 << w;
            d = new int[h + 1][w2];
            for (int[] v : d) {
                Arrays.fill(v, -1);
            }

            d[0][forbiddenMask[0]] = 0;
            for (int i = 0; i < h; i++) {
                for (int mask = 0; mask < w2; mask++)
                    if (d[i][mask] >= 0) {
                        rec(i, mask, i + 1 < h ? forbiddenMask[i + 1] : 0, 0, d[i][mask]);
                    }
            }

            int answer = 0;
            for (int mask = 0; mask < w2; mask++)
                answer = Math.max(answer, d[h][mask]);
            out.print(answer);
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
        new C.ProblemSolver().solve();
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
        new Thread(new C()).start();
    }

}
