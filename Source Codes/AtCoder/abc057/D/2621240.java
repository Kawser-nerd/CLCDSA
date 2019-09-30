import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.*;

public class Main {

    static int N;
    static int A;
    static int B;
    static long[] V;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        V = sc.nextLongArray(N);

        Answer ans = solve();
        System.out.println( BigDecimal.valueOf(ans.avg).toPlainString() );
        System.out.println( ans.comb );
    }

    private static Answer solve() {
        ValueComb[][] dp = new ValueComb[N+1][N+1];
        dp[0][0] = new ValueComb(0, 1);
        for (int n = 1; n <= N; n++) {
            long v = V[n-1];
            dp[n][0] = new ValueComb(0, 1);

            for (int i = 1; i <= n; i++) {
                ValueComb prev_before = dp[n-1][i-1];
                ValueComb prev_eq = dp[n-1][i];

                if( prev_eq == null ) {
                    dp[n][i] = new ValueComb(prev_before.value + v, prev_before.comb);

                } else {
                    if( prev_before.value + v > prev_eq.value ) {
                        dp[n][i] = new ValueComb(prev_before.value + v, prev_before.comb);
                    } else if( prev_before.value + v < prev_eq.value ) {
                        dp[n][i] = prev_eq;

                    } else {
                        long value = prev_before.value + v;
                        long comb = prev_before.comb + prev_eq.comb;
                        dp[n][i] = new ValueComb(value, comb);
                    }
                }
            }
        }

        long maxAvg_value = 0;
        long maxAvg_dividor = 0;
        for (int i = A; i <= B; i++) {
            ValueComb vc = dp[N][i];

            if( maxAvg_value == 0 ) {
                maxAvg_value = vc.value;
                maxAvg_dividor = i;

            } else {
                if( maxAvg_value * i < vc.value * maxAvg_dividor ) {
                    maxAvg_value = vc.value;
                    maxAvg_dividor = i;
                }
            }
        }

        long comb = 0;
        for (int i = A; i <= B; i++) {
            ValueComb vc = dp[N][i];
            if( maxAvg_value * i == vc.value * maxAvg_dividor ) {
                comb += vc.comb;
            }
        }

        return new Answer((double)maxAvg_value/ maxAvg_dividor, comb);
    }

    static class ValueComb {
        long value;
        long comb;

        public ValueComb(long value, long comb) {
            this.value = value;
            this.comb = comb;
        }
    }

    static class Answer {
        double avg;
        long comb;

        public Answer(double avg, long comb) {
            this.avg = avg;
            this.comb = comb;
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