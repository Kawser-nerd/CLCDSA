import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int[] W;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        K = fc.nextInt();
        W = fc.nextIntArray(N);

        System.out.println( solve() );
    }

    static int solve() {
        int A = N/2;
        int B = N - A;

        long[] SUMA = new long[1 << A];
        Map<Integer, Integer> bitAW = new HashMap<>();
        for (int i = 0; i < A; i++) {
            bitAW.put( 1 << i, W[i] );
        }
        for (int s = 1; s < 1 << A; s++) {
            int high = Integer.highestOneBit(s);
            int prev = s - high;
            SUMA[s] = SUMA[prev] + bitAW.get(high);
        }

        long[] SUMB = new long[1 << B];
        Map<Integer, Integer> bitBW = new HashMap<>();
        for (int i = 0; i < B; i++) {
            bitBW.put( 1 << i, W[A + i] );
        }
        for (int s = 1; s < 1 << B; s++) {
            int high = Integer.highestOneBit(s);
            int prev = s - high;
            SUMB[s] = SUMB[prev] + bitBW.get(high);
        }
        Arrays.sort(SUMB);

        // ???????????????...
        int ans = 0;

        for (long a : SUMA) {
            if( a > K ) {
                // ignore

            } else if( a == K ) {
                ans += 1;

            } else {
                ans += count(SUMB, K-a);
            }
        }

        return ans;
    }

    static int count(long[] arr, long val) {
        return upperBound(arr, val) - lowerBound(arr, val);
    }

    static int lowerBound(long[] array, long value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] < value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static int upperBound(long[] array, long value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid] <= value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
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