import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] D;
    static int[] Q;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();

        D = new int[N][];
        for (int i = 0; i < N; i++) {
            D[i] = sc.nextIntArray(N);
        }
        Q = sc.nextIntArray(sc.nextInt());

        PrintWriter pw = new PrintWriter(System.out);
        int[] ans = solve();
        for (int each : ans) {
            pw.println(each);
        }
        pw.flush();
    }

    static int[] R;

    static int[] solve() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if( j != 0 ) {
                    D[i][j] += D[i][j-1];
                }
            }
        }

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                if( i != 0 ) {
                    D[i][j] += D[i-1][j];
                }
            }
        }

        R = new int[N*N+1];
        Arrays.fill(R, -1);

        for (int h = 1; h <= N; h++) {
            for (int w = 1; w <= N; w++) {
                R[h*w] = Math.max(calc(h, w), R[h*w]);
            }
        }

        int[] M = new int[N*N+1];
        for (int i = 1; i <= N*N; i++) {
            M[i] = Math.max(R[i], M[i-1]);
        }

        int[] ans = new int[Q.length];
        for (int i = 0; i < Q.length; i++) {
            ans[i] = M[Q[i]];
        }
        return ans;
    }

    static int calc(int h, int w) {
        int max = -1;
        for (int i = 0; i < N - h + 1; i++) {
            for (int j = 0; j < N - w + 1; j++) {
                int a = D[i+h-1][j+w-1];
                int b;
                if( i > 0 ) {
                    b = D[i-1][j+w-1];
                } else {
                    b = 0;
                }
                int c;
                if( j > 0 ) {
                    c = D[i+h-1][j-1];
                } else {
                    c = 0;
                }
                int d;
                if( i > 0 && j > 0 ) {
                    d = D[i-1][j-1];
                } else {
                    d = 0;
                }

                max = Math.max(a - b - c + d, max);
            }
        }

        return max;
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