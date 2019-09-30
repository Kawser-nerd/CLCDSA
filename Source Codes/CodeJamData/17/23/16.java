import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int numQueries = in.nextInt();
            int[] maxDistance = new int[n];
            int[] speed = new int[n];
            for (int i = 0; i < n; i++) {
                maxDistance[i] = in.nextInt();
                speed[i] = in.nextInt();
            }

            final long infinity = (long) 1e15;
            long[][] d = new long[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = in.nextInt();
                    if (i == j) {
                        d[i][j] = 0;
                    } else if (d[i][j] < 0) {
                        d[i][j] = infinity;
                    }
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }

            double[][] best = new double[n][n];
            double[][] nbest = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        best[i][j] = infinity;
                    }
                }
            }
            for (int h = 0; h < n; h++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        nbest[i][j] = best[i][j];
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            if (d[h][k] > maxDistance[h]) {
                                continue;
                            }
                            double t = d[h][k] / (double) speed[h];
                            nbest[i][j] = Math.min(nbest[i][j], best[i][h] + t + best[k][j]);
                        }
                    }
                }
                double[][] tmp = best;
                best = nbest;
                nbest = tmp;
            }

            out.print("Case #" + testNumber + ":");
            for (int query = 0; query < numQueries; query++) {
                int s = in.nextInt() - 1;
                int t = in.nextInt() - 1;
                out.printf(" %.15f", best[s][t]);
            }
            out.println();
        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

