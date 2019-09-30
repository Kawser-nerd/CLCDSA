import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class B implements Runnable {

    private class DisjointSetUnion {

        int[] up;

        public DisjointSetUnion(int n) {
            up = new int[n];
            for (int i = 0; i < n; i++) {
                up[i] = i;
            }
        }

        int up(int p) {
            if (up[p] != p) {
                up[p] = up(up[p]);
            }
            return up[p];
        }

        public void join(int a, int b) {
            a = up(a);
            b = up(b);
            up[a] = b;
        }
    }

    private class TestCaseSolver {

        int n, m;
        int[][] a, idx;

        int[] dr = new int[] {-1, 0, 0, 1};
        int[] dc = new int[] {0, -1, 1, 0};

        private void solve() {
            n = nextInt();
            m = nextInt();
            a = new int[n][m];
            idx = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    a[i][j] = nextInt();
                    idx[i][j] = i * m + j;
                }

            DisjointSetUnion dsu = new DisjointSetUnion(n * m);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {

                    int lowest = Integer.MAX_VALUE;
                    int lowestI = 0;
                    int lowestJ = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                            if (a[ni][nj] < lowest) {
                                lowest = a[ni][nj];
                                lowestI = ni;
                                lowestJ = nj;
                            }
                        }
                    }

                    if (lowest < a[i][j]) {
                        dsu.join(idx[i][j], idx[lowestI][lowestJ]);
                    }

                }

            char letter = 'a';
            Map<Integer, Character> done = new HashMap<Integer, Character>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int component = dsu.up(idx[i][j]);
                    if (!done.containsKey(component)) {
                        done.put(component, letter++);
                    }
                    if (j > 0) {
                        out.print(' ');
                    }
                    out.print(done.get(component));
                }
                out.println();
            }
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

            out.println("Case #" + (tc + 1) + ":");
            new TestCaseSolver().solve();
        }

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(getClass().getSimpleName()) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
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
        new Thread(new B()).start();
    }
}