import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, D, K;
    static int[] L, R;
    static int[] S, T;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        D = sc.nextInt();
        K = sc.nextInt();
        L = new int[D];
        R = new int[D];
        for (int i = 0; i < D; i++) {
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
        }
        S = new int[K];
        T = new int[K];
        for (int i = 0; i < K; i++) {
            S[i] = sc.nextInt();
            T[i] = sc.nextInt();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (int i : solve()) {
            pw.println(i);
        }
        pw.flush();
    }

    static int[] solve() {
        int[] ans = new int[K];
        for (int i = 0; i < K; i++) {
            ans[i] = calc(S[i], T[i]);
        }
        return ans;
    }

    static int calc(int s, int t) {
        int from = -1;
        int to = -1;
        for (int i = 0; i < D; i++) {
            if( from == - 1 ) {
                if( L[i] <= s && s <= R[i] ) {
                    from = L[i];
                    to = R[i];
                }

            } else {
                if( intersects(from, to, L[i], R[i]) ) {
                    from = Math.min(from, L[i]);
                    to = Math.max(to, R[i]);
                }
            }

            if( from <= t && t <= to ) {
                return i+1;
            }
        }
        throw new IllegalArgumentException("wtf");
    }

    static boolean intersects(int from1, int to1, int from2, int to2) {
        if( to1 < from2 ) return false;
        if( to2 < from1 ) return false;
        return true;
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