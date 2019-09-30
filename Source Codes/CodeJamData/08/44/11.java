import java.io.*;
import java.util.regex.Pattern;
import java.util.StringTokenizer;

/**
 * @author Roman
 */
public class D implements Runnable {

    public static final String PROBLEM_ID = "D";

    private class ProblemSolver {

        int len, k, times, ans;
        int[] p;
        boolean[] used;
        char[] s;
        char[] data;

        private void update() {
            char last = 0;
            int result = 0;
            for (int i = 0; i < len; i++)
                if (data[i] != last) {
                    last = data[i];
                    result++;
                    if (result > ans) {
                    //    return;
                    }
                }
            ans = Math.min(ans, result);
        }

        private void process() {
            for (int i = 0; i < times; i++) {
                int offset = i * k;
                for (int j = 0; j < k; j++) {
                    data[offset + j] = s[offset + p[j]];
                }
            }
            update();
        }

        private void genAll(int idx, int k) {
            if (idx >= k) {
                process();
                return;
            }
            for (int i = 0; i < k; i++)
                if (!used[i]) {
                    used[i] = true;
                    p[idx] = i;
                    genAll(idx + 1, k);
                    used[i] = false;
                }
        }

        private void solveOne() throws IOException {
            k = Integer.parseInt(nextLine());
            String str = nextLine().trim();
            s = str.toCharArray();
            len = s.length;
            times = len / k;
            ans = Integer.MAX_VALUE;

            p = new int[k];
            used = new boolean[k];
            data = new char[len];
            genAll(0, k);

            out.print(ans);
        }

        public void solve() throws Throwable {
            int tc = Integer.parseInt(nextLine());
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
        new D.ProblemSolver().solve();
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
        new Thread(new D()).start();
    }

}
