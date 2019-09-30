import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.function.LongPredicate;

public class Main {

    static long R, B;
    static int X, Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        R = sc.nextLong();
        B = sc.nextLong();
        X = sc.nextInt();
        Y = sc.nextInt();

        System.out.println(solve());
    }

    static long solve() {
        // (X, 1)????a, (1, Y)????b????
        // aX + b <= R
        // a + bY <= B
        // ????a, b????
        // f = a + b
        // ??????
        // ??????????????????????????????????????
        // ??????????????????????????

        // aX + b <= R ?? aXY + bY <= RY (1)
        // a + bY <= B ?? bY = B - a (2)
        // aXY + B - a <= RY
        // => a(XY-1) <= RY - B
        // => a <= (RY - B)(XY-1)
        BigInteger num = BigInteger.valueOf(R).multiply( BigInteger.valueOf(Y) ).subtract(BigInteger.valueOf(B));
        if( num.compareTo(BigInteger.ZERO) < 0 ) {
            return caseZero();
        }
        BigInteger den = BigInteger.valueOf((long)X * Y - 1);
        long a = num.divide(den).longValue();

        if( B - a < 0 ) {
            return caseZero();
        } else {
            long RR = R - a * X;
            long BB = B - a;

            // b?R?B??????????
            long b = Math.min(RR, BB/Y);
            RR -= b;
            BB -= b*Y;

            // ??????????(a+1, b) or (a, b+1)??????????
            if( RR >= X && BB > 0 ) {
                return a+1 + b;
            } else if( BB >= Y && RR > 0 ) {
                return a + b+1;
            } else {
                return a + b;
            }
        }
    }

    static long caseZero() {
        // ??????? or ????????
        long red = Math.min(R/X, B);
        long blue = Math.min(R, B/Y);
        return Math.max(red, blue);
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