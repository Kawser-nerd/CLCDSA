import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int A;
    static int B;
    static int C;
    static int D;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        D = sc.nextInt();

        System.out.println( solve() ? "YES" : "NO" );
    }

    static boolean solve() {
        // G?goal?G
        int G = Math.abs(A-B);
        int times = N - 1;

        // C*q D*q G ??????????
        int q = G / D;
        int r = G % D;
        times -= q;

        // ?????????
        if( times < 0 ) return false;
        // ????????(???????????????)
        if( times == 0 ) return r == 0;

        if( times % 2 == 0 ) {
            // +D -C?????? D-C??????????????
            long available = (times / 2) * (long)(D-C);
            return r <= available;

        } else {
            // ??????
            // G C1 D1 or C1 G D1
            long C1 = C * (q+1);
            long D1 = D * (q+1);
            times -= 1;

            // C1 <= G <= D1 ?????????(0?????????)
            if( C1 <= G && G <= D1 ) return true;

            // G C1 D1 ???????? C1??G???????????????OK
            long r1 = C1 - G;
            long available = (times / 2) * (long)(D-C);
            return r1 <= available;
        }
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

        double nextDouble() {
            return Double.parseDouble(next());
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