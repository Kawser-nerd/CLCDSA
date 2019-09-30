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
        if( Math.abs(Y) >= Math.abs(X) ) {
            int time = 0;
            if( Y < 0 ) time++;
            if( X < 0 ) time++;
            time += Math.abs(Y) - Math.abs(X);
            return time;

        } else {
            int time = 0;
            if( Y > 0 ) time++;
            if( X > 0 ) time++;
            time += Math.abs(X) - Math.abs(Y);
            return time;
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