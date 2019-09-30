import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        P[] p;
        long[][] d;
        boolean[] u;
        long M;

        void dfs(int x) {
            u[x] = true;
            for (int y = 0; y < d.length; y++) {
                if (d[x][y] <= M && !u[y]) {
                    dfs(y);
                }
            }
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            in.nextInt(); // s
            p = new P[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int z = in.nextInt();
                p[i] = new P(x, y, z);
                // v
                in.nextInt();
                in.nextInt();
                in.nextInt();
            }

            d = new long[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] =
                            (p[i].x - p[j].x) * (p[i].x - p[j].x) +
                                    (p[i].y - p[j].y) * (p[i].y - p[j].y) +
                                    (p[i].z - p[j].z) * (p[i].z - p[j].z);
                }
            }

            long L = -1;
            long R = 1000 * 1000 * 3;
            u = new boolean[n];
            while (L < R - 1) {
                M = (L + R) / 2;
                Arrays.fill(u, false);
                dfs(0);
                if (u[1]) {
                    R = M;
                } else {
                    L = M;
                }
            }

            out.println("Case #" + testNumber + ": " + Math.sqrt(R));
        }

        class P {
            int x;
            int y;
            int z;

            public P(int x, int y, int z) {
                this.x = x;
                this.y = y;
                this.z = z;
            }

        }

    }
}

