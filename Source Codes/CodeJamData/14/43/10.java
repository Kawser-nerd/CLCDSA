import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class C {
    private final Scanner in;
    private final PrintWriter out;

    public C(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        final String filename = "C-large";
        try (Scanner in = new Scanner(new FileReader(new File(filename + ".in")));
             PrintWriter out = new PrintWriter(filename + ".out")) {
            new C(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }

    private void solve() {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            System.out.println("#" + test);

            int w = in.nextInt();
            int h = in.nextInt();

            int n = in.nextInt();


            Building[] p = new Building[n + 2];
            for (int i = 0; i < n; ++i) {
                p[i] = new Building(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
            }

            p[n] = new Building(-1, 0, -1, h - 1);
            p[n + 1] = new Building(w, 0, w, h - 1);

            int[] D = new int[p.length];

            final int INF = Integer.MAX_VALUE / 2;
            Arrays.fill(D, INF);

            D[n] = 0;

            boolean[] u = new boolean[D.length];
            Arrays.fill(u, false);

            while (!u[n + 1]) {
                int mi = -1;
                for (int i = 0; i < D.length; ++i) {
                    if (!u[i] && (mi < 0 || D[mi] > D[i])) {
                        mi = i;
                    }
                }

                if (mi < 0) break;

                u[mi] = true;
//                System.out.println(mi);
                for (int j = 0; j < D.length; ++j) {
                    if (u[j]) continue;
                    int e = p[mi].dist(p[j]);
                    if (D[j] > D[mi] + e) {
//                        System.out.println(mi + " -> " + j + " : " + e);
                        D[j] = D[mi] + e;
                    }
                }
            }

            out.print("Case #" + test + ": ");
            out.println(D[n + 1]);
            System.out.println(D[n + 1]);
        }
    }

    class Building {
        int x0, y0, x1, y1;

        Building(int x0, int y0, int x1, int y1) {
            this.x0 = x0;
            this.y0 = y0;
            this.x1 = x1;
            this.y1 = y1;
        }


        int dist(Building b) {
            int xd = Math.max(x0 - b.x1, b.x0 - x1) - 1;
            int yd = Math.max(y0 - b.y1, b.y0 - y1) - 1;
            return Math.max(xd, yd);
        }

    }

}
