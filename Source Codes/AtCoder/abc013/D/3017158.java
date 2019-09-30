import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int D;
    static int[] A;

    static int D_MAX_BIT;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        D = sc.nextInt();
        A = sc.nextIntArray(M);

        PrintWriter pw = new PrintWriter(System.out);
        for (int each : solve()) {
            pw.println(each);
        }
        pw.flush();
    }

    static int[] solve() {
        D_MAX_BIT = Integer.toBinaryString(D).length();

        int[] B = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = i;
        }
        for (int a : A) {
            int t = B[a];
            B[a] = B[a-1];
            B[a-1] = t;
        }

        int[] T = new int[N];
        for (int i = 0; i < N; i++) {
            int b = B[i];
            T[b] = i;
        }

        int[][] TS = new int[D_MAX_BIT][];
        TS[0] = T;
        for (int b = 1; b < D_MAX_BIT; b++) {
            int[] prev = TS[b-1];
            int[] curr = new int[N];

            for (int i = 0; i < N; i++) {
                // i -> prev[i] -> prev[prev[i]]
                curr[i] = prev[prev[i]];
            }
            TS[b] = curr;
        }

        int[] ANS = new int[N];
        for (int i = 0; i < N; i++) {
            ANS[i] = calc(i, TS) + 1;
        }
        return ANS;
    }

    static int calc(int i, int[][] TS) {
        int cur = i;
        for (int b = 0; b < D_MAX_BIT; b++) {
            if( (D & 1 << b) > 0 ) {
                cur = TS[b][cur];
            }
        }
        return cur;
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