import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int N = ni();
        int[] x = new int[N];
        int[] y = new int[N];
        int[] c = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = ni();
            y[i] = ni();
            c[i] = ni();
        }

        double high = 1e9;
        double low = 0;
        for (int i = 0; i < 1000; i++) {
            double mid = (high + low) / 2;
            double xmax = 1e6;
            double xmin = -1e6;
            double ymax = 1e6;
            double ymin = -1e6;
            for (int j = 0; j < N; j++) {
                double d = mid / c[j];
                xmax = Math.min(xmax, x[j] + d);
                xmin = Math.max(xmin, x[j] - d);
                ymax = Math.min(ymax, y[j] + d);
                ymin = Math.max(ymin, y[j] - d);
            }
            if (xmax >= xmin && ymax >= ymin) {
                high = mid;
            } else {
                low = mid;
            }
        }

        out.println(high);
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}