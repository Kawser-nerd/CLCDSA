import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {

    static int N;
    static int K;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println( solve() );
    }

    static long solve() {
        if( K == 1 ) {
            return case_1();
        } else {
            return case_n();
        }
    }

    static long case_1() {
        long sum = 0;
        for (int i = 0; i < N; i++) {
            if( A[i] > 0 ) {
                sum += A[i];
            }
        }
        return sum;
    }

    static long case_n() {
        // ???????K???????????
        // ???????????

        long sum = 0;
        for (int i = 0; i < N; i++) {
            if( A[i] > 0 ) {
                sum+=A[i];
            }
        }

        long prev_kp = 0;
        long prev_km = 0;
        for (int i = 0; i < K; i++) {
            if(A[i] > 0 ) {
                prev_kp += A[i];
            } else {
                prev_km += -1 * A[i];
            }
        }

        long min_kp = prev_kp;
        long min_km = prev_km;
        for (int i = K; i < N; i++) {
            long current_kp = prev_kp;
            long current_km = prev_km;
            if( A[i] > 0 ) {
                current_kp += A[i];
            } else {
                current_km += -1 * A[i];
            }
            if( A[i-K] > 0 ) {
                current_kp -= A[i-K];
            } else {
                current_km -= -1 * A[i-K];
            }

            min_kp = Math.min(current_kp, min_kp);
            min_km = Math.min(current_km, min_km);
            prev_kp = current_kp;
            prev_km = current_km;
        }

        return sum - Math.min(min_kp, min_km);
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