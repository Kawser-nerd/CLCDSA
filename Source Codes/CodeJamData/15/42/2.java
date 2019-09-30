
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B {

    private static final double INF = 1e10;

    private String solveTest() throws IOException {
        int n = nextInt();
        double v = Double.parseDouble(next());
        double x = Double.parseDouble(next());
        Pipe[] pipes = new Pipe[n];
        for (int i = 0; i < n; i++) {
            pipes[i] = new Pipe(Double.parseDouble(next()), Double.parseDouble(next()) - x);
        }
        Arrays.sort(pipes, new Comparator<Pipe>() {
            public int compare(Pipe o1, Pipe o2) {
                return -Double.compare(o1.r, o2.r);
            }
        });
        double l = 0;
        double r = INF;
        while (true) {
            double m = (l + r) / 2;
            if (m == l || m == r) break;
            if (can(pipes, m, v)) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == INF) return "IMPOSSIBLE"; else return "" + r;
    }

    private boolean can(Pipe[] pipes, double t, double v) {
        double max = 0;
        double min = 0;
        for (Pipe pipe : pipes) {
            if (pipe.c > 0) {
                max += pipe.c * pipe.r * t;
            } else {
                min += pipe.c * pipe.r * t;
            }
        }
        double vv = 0;
        double qq = 0;
        for (Pipe pipe : pipes) {
            if (pipe.c == 0) {
                vv += pipe.r * t;
            } else {
                if (pipe.c > 0) {
                    max -= pipe.c * pipe.r * t;
                    double tt = Math.min(t, -(min+qq) / (pipe.c * pipe.r));
                    qq += tt * pipe.c * pipe.r;
                    vv += tt * pipe.r;
                } else {
                    min -= pipe.c * pipe.r * t;
                    double tt = Math.min(t, -(max+qq) / (pipe.c * pipe.r));
                    qq += tt * pipe.c * pipe.r;
                    vv += tt * pipe.r;
                }
            }
        }
        return vv >= v;
    }

    class Pipe {
        double r, c;

        public Pipe(double r, double c) {
            this.r = r;
            this.c = c;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}