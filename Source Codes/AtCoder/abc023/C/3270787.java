import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int R, C, K;
    static int N;
    static int[] r, c;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        K = sc.nextInt();
        N = sc.nextInt();
        r = new int[N];
        c = new int[N];
        for (int i = 0; i < N; i++) {
            r[i] = sc.nextInt()-1;
            c[i] = sc.nextInt()-1;
        }
        System.out.println(solve());
    }

    static long solve() {
        int[] cnt_r = new int[R];
        int[] cnt_c = new int[C];
        ColCount[] cc = new ColCount[C];
        for (int c = 0; c < C; c++) {
            cc[c] = new ColCount(c, 0);
        }

        for (int i = 0; i < N; i++) {
            cnt_r[r[i]]++;
            cnt_c[c[i]]++;
            cc[c[i]].cnt++;
        }

        Arrays.sort(cc, Comparator.comparingInt(x -> x.cnt));

        long cnt = 0;
        for (int r = 0; r < R; r++) {
            // cnt_r + cnt_c = K ?????
            int cr = cnt_r[r];

            // [from, to)
            int from = lowerBound(cc, K - cr);
            int to = upperBound(cc, K - cr);
            cnt += to - from;
        }

        // ????????????????
        for (int i = 0; i < N; i++) {
            int k = cnt_r[r[i]] + cnt_c[c[i]];
            if( K == k ) {
                cnt--;
            } else if( K+1 == k ) {
                cnt++;
            }
        }

        return cnt;
    }

    static class ColCount {
        int c;
        int cnt;

        public ColCount(int c, int cnt) {
            this.c = c;
            this.cnt = cnt;
        }

        public String toString() {
            return "(" + c + " " + cnt + ")";
        }
    }

    static int lowerBound(ColCount[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid].cnt < value ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static int upperBound(ColCount[] array, int value) {
        int low = 0;
        int high = array.length;
        int mid;
        while( low < high ) {
            mid = ((high - low) >>> 1) + low; // (high + low) / 2
            if( array[mid].cnt <= value ) {
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