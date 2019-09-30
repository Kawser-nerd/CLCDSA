import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextIntArray(N);
        System.out.println(solve() ? "Possible" : "Impossible");
    }

    static boolean solve() {
        Arrays.sort(A);
        int diameter = A[N-1];
        int center = A[0];
        int[] cnt = new int[diameter+1];
        for (int i = 0; i < N; i++) {
            cnt[A[i]]++;
        }

        if( diameter % 2 == 1 ) {
            // 5 - 4 - 3 - 3 - 4 - 5
            if( diameter/2 + 1 != center ) return false;
            if( cnt[center] != 2 ) return false;
            return validPath(cnt, center+1, diameter);

        } else {
            // 4 - 3 - 2 - 3 - 4
            if( diameter/2 != center ) return false;
            if( cnt[center] != 1 ) return false;
            return validPath(cnt, center+1, diameter);
        }
    }

    // [from, to]
    private static boolean validPath(int[] cnt, int from, int to) {
        for (int i = from; i <= to; i++) {
            if( cnt[i] < 2 ) return false;
        }
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