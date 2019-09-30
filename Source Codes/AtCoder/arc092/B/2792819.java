import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;
    static int[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);

        N = sc.nextInt();
        A = sc.nextIntArray(N);
        B = sc.nextIntArray(N);

        System.out.println( solve() );
    }

    static int solve() {
        boolean[] result = new boolean[29];
        for (int i = 0; i < 29; i++) {
            // ??4?????????????
            // => ab?4,2,1 bit?????????????(?????bit??????)
            int t = (int)Math.pow(2, i);

            int[] BT = Arrays.copyOf(B, N);
            for (int j = 0; j < N; j++) {
                BT[j] %= 2*t;
            }
            Arrays.sort(BT);

            int cnt = 0;
            for (int j = 0; j < N; j++) {
                int at = A[j] % (2*t);
                // at + bt ? [t, 2t) [3t, 4t] ????t???????????
                cnt += search(t-at, 2*t-at, BT);
                cnt += search(3*t-at, 4*t-at, BT);
                cnt %= 2; // 20? * 20????????????
            }

            if( cnt % 2 == 1 ) {
                result[i] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 29; i++) {
            if( result[i] ) {
                ans += 1 << i;
            }
        }
        return ans;
    }

    static int search(int from, int to, int[] BT) {
        int f = lowerBound(from, BT);
        int t = lowerBound(to, BT);
        return t - f;
    }

    static int lowerBound(int a, int[] array) {
        int low = 0;
        int high = array.length;
        while( low < high ) {
            int mid = (low + high) / 2;
            if( array[mid] < a ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

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