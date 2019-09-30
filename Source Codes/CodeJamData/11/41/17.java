import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    static class W implements Comparable<W> {
        final int w, l;

        public W(int b, int e, int w) {
            this.w = w;
            this.l = e - b;
        }

        public int compareTo(W o) {
            return w - o.w;
        }
    }

    public void solveOne(String prefix) throws IOException {
        int x = nextInt();
        int s = nextInt();
        int r = nextInt();
        double t = nextInt();
        int n = nextInt();
        W[] w = new W[n + 1];
        for (int i = 0; i < n; ++i) {
            w[i] = new W(nextInt(), nextInt(), nextInt());
            x -= w[i].l;
        }
        w[n] = new W(0, x, 0);

        Arrays.sort(w);
        double answer = 0;
        for (int i = 0; i < w.length; ++i) {
            double runTime = Math.min(t, (double)w[i].l / (r + w[i].w));
            answer += runTime;
            t -= runTime;
            double rd = w[i].l - runTime * (r + w[i].w);
            System.err.println(i + ": " + rd);
            answer += rd / (s + w[i].w);
        }
        out.println(prefix + answer);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(A.class.getSimpleName() + ".in"));
        out = new PrintWriter(A.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }
}
