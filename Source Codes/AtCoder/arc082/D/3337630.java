import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int X;
    static int K;
    static int[] R;
    static int Q;
    static int[] T, A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        X = sc.nextInt();
        K = sc.nextInt();
        R = sc.nextIntArray(K);

        Q = sc.nextInt();
        T = new int[Q];
        A = new int[Q];
        for (int i = 0; i < Q; i++) {
            T[i] = sc.nextInt();
            A[i] = sc.nextInt();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int l : solve()) {
            pw.println(l);
        }
        pw.flush();
    }

    static int[] solve() {

        int[] H = new int[K];
        int[] U = new int[K];
        int[] V = new int[K];

        H[0] = 0;
        U[0] = Math.min(R[0], X);
        V[0] = X;
        for (int i = 1; i < K; i++) {
            int t = R[i] - R[i-1];
            Result result;
            if( i % 2 == 0 ) {
                result = down(H[i-1], U[i-1], V[i-1], t);
            } else {
                result = up(H[i-1], U[i-1], V[i-1], t);
            }
            H[i] = result.h;
            U[i] = result.u;
            V[i] = result.v;
        }

//        for (int i = 0; i < K; i++) {
//            System.out.println( H[i] + " " + U[i] + " " + V[i]);
//        }

        int[] ans = new int[Q];
        int k = 0;
        int q = 0;

        while(q != Q && T[q] < R[0]) {
            ans[q] = calc(T[q], A[q], -1, 0, 0, 0, X);
            q++;
        }

        while(q != Q) {
            int t = T[q];
            if( k == K-1 || (R[k] <= t && t < R[k+1]) ) {
                ans[q] = calc(T[q], A[q], k, R[k], H[k], U[k], V[k]);
                q++;

            } else {
                k++;
            }
        }
        return ans;
    }

    static int calc(int t, int a, int k, int r, int h, int u, int v) {
        // r??(t-r)?????
        // k?????????????????
        Result result;
        if( k % 2 == 0 ) {
            result = up(h, u, v, t-r);
        } else {
            result = down(h, u, v, t-r);
        }

        return f(result.h, result.u, result.v, a);
    }

    static int f(int h, int u, int v, int a) {
        if( a <= u ) {
            return h;
        } else if( a < v ) {
            return h + (a - u);
        } else {
            return h + (v - u);
        }
    }

    static Result down(int h, int u, int v, int t) {
        int h1 = Math.max(h - t, 0);
        int v1 = v;
        int dh = h - t;
        int u1;
        if( dh > 0 ) {
            u1 = u;
        } else {
            // U?????
            u1 = Math.min(u + (-dh), v);
        }
        return new Result(h1, u1, v1);
    }

    static Result up(int h, int u, int v, int t) {
        int h1 = Math.min(h + t, X);
        int u1 = u;
        int dh = X - (h + v - u) - t;
        int v1;
        if( dh > 0 ) {
            v1 = v;

        } else {
            // V?????
            v1 = Math.max(v - (-dh), u);
        }
        return new Result(h1, u1, v1);
    }

    static class Result {
        int h, u, v;

        public Result(int h, int u, int v) {
            this.h = h;
            this.u = u;
            this.v = v;
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}