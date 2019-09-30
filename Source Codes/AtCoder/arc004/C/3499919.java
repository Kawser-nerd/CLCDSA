import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.function.IntPredicate;
import java.util.function.LongPredicate;
import java.util.function.LongToIntFunction;

public class Main {

    static long X;
    static int Y;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        String s = fc.next();
        int idx = s.indexOf('/');
        X = Long.parseLong(s.substring(0, idx));
        Y = Integer.parseInt(s.substring(idx+1));

        List<Answer> answers = solve();
        if( answers.isEmpty() ) {
            System.out.println("Impossible");

        } else {
            PrintWriter pw = new PrintWriter(System.out);
            for (Answer ans : answers) {
                pw.println(ans.n + " " + ans.m);
            }
            pw.flush();
        }
    }

    static List<Answer> solve() {
        // ?????????
        int g = (int)gcd(X, Y);
        X = X/g;
        Y = Y/g;

        // X/Y??????
        // [N/2-0.5, N/2+0.5)
        // ??????????????????
        // ???????????????????????...
        // ???N????????
        // X/Y = [N/2-0.5, N/2+0.5)
        // => 2X/Y = [N-1, N+1)
        List<Answer> ans = new ArrayList<>();
        long n = 2*X/Y; // ???? 4.32 -> 4 ???????????
        calcM(n).ifPresent( m -> ans.add( new Answer(n, m) ));
        
        long n1 = n+1;
        calcM(n1).ifPresent( m1 -> ans.add( new Answer(n1, m1) ));
        return ans;
    }

    static OptionalLong calcM(long n) {
        // (sum - M) / N = X / Y
        // => sum - M = NX / Y
        // => M = sum - NX / Y

        // NX/Y???????????????????
        // X/Y?gcd?????N?????
        if( n % Y != 0 ) return OptionalLong.empty();

        BigInteger sum = BigInteger.valueOf(n)
                .multiply(BigInteger.valueOf(n+1))
                .divide(BigInteger.valueOf(2));
        // M = sum - NX/Y
        BigInteger nx_div_y = BigInteger.valueOf(n)
                .multiply(BigInteger.valueOf(X))
                .divide(BigInteger.valueOf(Y));
        BigInteger m = sum.subtract( nx_div_y );

        if( m.compareTo(BigInteger.valueOf(Long.MAX_VALUE)) > 0 ) return OptionalLong.empty();
        if( m.compareTo(BigInteger.ZERO) <= 0 ) return OptionalLong.empty();
        return OptionalLong.of(m.longValue());
    }

    static long gcd(long a, long b) {
        while (b > 0) {
            long c = a;
            a = b;
            b = c % b;
        }
        return a;
    }

    static class Answer {
        long n, m;

        public Answer(long n, long m) {
            this.n = n;
            this.m = m;
        }
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