import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N, P;
    static Sweet[] S;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        P = fc.nextInt();
        S = new Sweet[N];
        for (int i = 0; i < N; i++) {
            S[i] = new Sweet(fc.nextInt(), fc.nextInt());
        }
        System.out.println(solve());
    }

    static class Sweet {
        int p, s;

        public Sweet(int p, int s) {
            this.p = p;
            this.s = s;
        }
    }

    static int solve() {
        // ???????
        Arrays.sort(S, Comparator.comparingInt(s -> -s.p));

        int DP_MAX = P + 105;
        int[] curr = new int[DP_MAX];
        int[] prev = new int[DP_MAX];
        Arrays.fill(curr, -1);
        curr[0] = 0;

        for (int i = 0; i < N; i++) {
            int[] t = curr;
            curr = prev;
            prev = t;
            Arrays.fill(curr, -1);

            Sweet s = S[i];
            for (int p = DP_MAX-1; p >= 0; p--) {
                if( prev[p] != -1 ) {
                    curr[p] = Math.max(prev[p], curr[p]);

                    if( p <= P ) {
                        curr[p + s.p] = Math.max(prev[p] + s.s, curr[p + s.p]);
                    }
                }
            }
        }

        int ans = -1;
        for (int p = 0; p < DP_MAX; p++) {
            ans = Math.max(curr[p], ans);
        }
        return ans;
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