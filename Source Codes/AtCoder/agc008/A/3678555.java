import sun.text.resources.cldr.ha.FormatData_ha;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int X, Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        X = sc.nextInt();
        Y = sc.nextInt();

        System.out.println(solve());
    }

    static int solve() {

        if( Y > 0 ) {
            if( Y < X ) { // (Y, ...)
                // flip -> move -> flip
                return X - Y + 2;

            } else if( 0 <= X && X <= Y ) { // [0, Y]
                // move
                return Y - X;

            } else if( -Y < X && X < 0 ) { // (-Y, 0)
                // flip -> move
                return Y - Math.abs(X) + 1;

            } else { // (..., -Y]
                // move -> flip
                return Math.abs(X) - Y + 1;
            }
        } else if( Y < 0 ) {
            if( X <= Y ) {
                // move
                return Math.abs(X) - Math.abs(Y);

            } else if( X < 0 ) {
                // flip -> move -> flip
                return Math.abs(Y) - Math.abs(X) + 2;

            } else if( X <= -Y ) {
                // move -> flip
                return Math.abs(Y) - Math.abs(X) + 1;

            } else {
                // flip -> move
                return Math.abs(X) - Math.abs(Y) + 1;
            }

        } else {
            if( X > 0 ) {
                // flip -> move
                return 1 + X;

            } else {
                // move
                return -X;
            }
        }
    }

    static int min(int... values) {
        int min = Integer.MAX_VALUE;
        for (int value : values) {
            min = Math.min(value, min);
        }
        return min;
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