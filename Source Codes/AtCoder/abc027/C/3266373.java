import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.function.IntBinaryOperator;
import java.util.function.IntFunction;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

public class Main {

    static long N;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextLong();

        System.out.println( solve() ? "Takahashi" : "Aoki" );
    }

    static boolean solve() {
        long border = 4;
        boolean takahasi = true;
        while(N >= border) {
            border *= 2;
            takahasi = !takahasi;
        }

        if( takahasi ) {
            return simu(i -> 2 * i, i -> 2 * i + 1);
        } else {
            return simu(i -> 2 * i + 1, i -> 2 * i);
        }
    }

    static boolean simu(LongUnaryOperator t, LongUnaryOperator a) {
        long x = 1;
        boolean first = true;
        while( x <= N ) {
            x = (first ? t : a).applyAsLong(x);
            if( x > N ) {
                return !first;
            }
            first = !first;
        }
        throw new RuntimeException("wtf");
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