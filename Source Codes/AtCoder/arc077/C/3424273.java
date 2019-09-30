import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt() - 1;
        }

        System.out.println(solve());
    }

    static long solve() {
        // a -> b ??????x????????????????imos????????
        // ? a = 2, b = 7
        // => 3 -> 0, 4 -> 1, 5 -> 2, 6 -> 3, 7 -> 4

        int[] imos = new int[M*2];
        int[] fin = new int[M*2];
        for (int i = 0; i < N-1; i++) {
            int a = A[i];
            int b = A[i+1];
            if( b < a ) {
                b += M;
            }
            if( b - a == 1 ) continue;
            imos[a+2]++;
            imos[b+1]--;
            fin[b+1] += b - a - 1;
        }

        int[] kouka = new int[M];
        int q = 0;
        int r = 0;
        for (int i = 0; i < M*2; i++) {
            q += imos[i];
            r += q;
            r -= fin[i];
            kouka[i%M] += r;
        }

        int high = kouka[0];
        int x = 0;
        for (int i = 1; i < M; i++) {
            if( kouka[i] > high ) {
                x = i;
                high = kouka[i];
            }
        }

        int x2 = x + M;
        long ans = 0;
        for (int i = 0; i < N-1; i++) {
            int a = A[i];
            int b = A[i+1];
            if( b < a ) {
                b += M;
            }

            // a = 2, b = 7, x = 5????
            // 2 -> 5 -> 6 -> 7 ? 3??????
            // -> b - x + 1
            if( a + 1 < x && x <= b ) {
                ans += b - x + 1;
            } else if (a + 1 < x2 && x2 <= b) {
                ans += b - x2 + 1;
            } else {
                ans += b - a;
            }
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