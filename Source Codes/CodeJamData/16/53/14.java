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
import java.util.LinkedList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Rene
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
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int s = in.nextInt();
            Asteroid[] a = new Asteroid[n];
            for (int i = 0; i < n; i++) {
                a[i] = new Asteroid(in.nextInt(), in.nextInt(), in.nextInt(),
                        in.nextInt(), in.nextInt(), in.nextInt());
            }
            double result = stupid(a);
            out.printf("Case #%d: %.8f\n", testNumber, result);

        }

        public double stupid(Asteroid[] a) {
            int n = a.length;
            double[][] dist = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    double z = a[i].dist(a[j]);
                    dist[i][j] = z;
                    dist[j][i] = z;
                }
            }
            double ub = 1000000;
            double lb = 0.0;
            boolean[] seen = new boolean[n];
            for (int i = 0; i < 50; i++) {
                double mid = (ub + lb) / 2;
                Arrays.fill(seen, false);
                LinkedList<Integer> list = new LinkedList<>();
                list.add(0);
                seen[0] = true;
                while (list.size() > 0) {
                    int u = list.poll();
                    for (int k = 0; k < n; k++) {
                        if (dist[u][k] <= mid && !seen[k]) {
                            seen[k] = true;
                            list.add(k);
                        }
                    }
                }
                if (seen[1]) ub = mid;
                else lb = mid;
            }
            return (lb + ub) / 2;
        }

        public class Asteroid {
            int x;
            int y;
            int z;
            int vx;
            int vy;
            int vz;

            public Asteroid(int x, int y, int z, int vx, int vy, int vz) {
                this.x = x;
                this.y = y;
                this.z = z;
                this.vx = vx;
                this.vy = vy;
                this.vz = vz;
            }

            double dist(Asteroid other) {
                double dx = x - other.x;
                double dy = y - other.y;
                double dz = z - other.z;
                return Math.sqrt(dx * dx + dy * dy + dz * dz);
            }

        }

    }
}

