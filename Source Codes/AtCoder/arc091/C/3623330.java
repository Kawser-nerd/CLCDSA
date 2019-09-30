import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N, A, B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();

        int[] arr = solve();
        if( arr == null ) {
            System.out.println(-1);
        } else {
            StringJoiner j = new StringJoiner(" ");
            for (int i : arr) {
                j.add(String.valueOf(i));
            }
            System.out.println(j.toString());
        }
    }

    static int[] solve(int n, int a, int b) {
        N = n;
        A = a;
        B = b;
        return solve();
    }

    static int[] solve() {
        if( A + B > N + 1 ) return null;
        if( N > (long)A * B ) return null;


        // LIS??????????????
        // ????????LDS?????
        //
        // ? N = 14, A = 5, B = 3???
        // 10 11 12 13 14
        //  2  6  7  8  9
        //  1  3  4  5
        // -> [11 12 13 14 15 2 7 8 9 10 1 3 4 5 6]

        int[] arr = new int[N];

        // ?? LIS????????
        for (int i = 0; i < A; i++) {
            arr[i] = N - A + i + 1;
        }

        if( B == 1 ) return arr;

        // ???????LDS
        // ?????????????????????
        int H = B - 1;
        int W = ((N - A) + (H - 1)) / H;

        // [from, to)
        int idx = A;
        int from = H + 1;
        int to = N - A + 1;
        for (int h = 0; h < H; h++) {
            arr[idx++] = H - h ;
            if( from == to ) continue;
            int f = Math.max(to - (W-1), from);
            int t = to;
            to = f;

            int cur = f;
            for (int w = 1; w < W; w++) {
                if( cur < t ) {
                    arr[idx++] = cur++;
                }
            }
        }

        return arr;
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