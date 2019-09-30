import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int N = ni();
        int Q = ni();

        int[] X = new int[N];
        int[] R = new int[N];
        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = ni();
            R[i] = ni();
            H[i] = ni();
        }

        int[] A = new int[Q];
        int[] B = new int[Q];
        for (int i = 0; i < Q; i++) {
            A[i] = ni();
            B[i] = ni();
        }

        double[] v = new double[20000];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < H[i]; j++) {
                double h1 = j;
                double r1 = (double) R[i] * h1 / H[i];
                double h2 = j + 1;
                double r2 = (double) R[i] * h2 / H[i];

                double v1 = Math.PI * r1 * r1 * h1 / 3;
                double v2 = Math.PI * r2 * r2 * h2 / 3;

                v[X[i] + H[i] - 1 - j] += v2 - v1;
            }
        }

        double[] sum = new double[20001];
        for (int i = 1; i <= 20000; i++) {
            sum[i] = sum[i - 1] + v[i - 1];
        }

        for (int i = 0; i < Q; i++) {
            out.println(sum[B[i]] - sum[A[i]]);
        }
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