import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        A = fc.nextInt();
        B = fc.nextInt();
        System.out.println(solve() ? "Takahashi" : "Aoki");
    }

    static boolean solve() {
        if( A >= N ) return true;

        if( A > B ) {
            return true;

        } else if( A < B ) {
            return false;

        } else {
            // A == B?????? [1, A] ??, A+1 ?????????????
            return N % (A+1) != 0;
        }


        // ??????????
//        int[] AW = new int[N+1];
//        int[] BW = new int[N+1];
//        for (int i = 1; i <= Math.min(A, N); i++) {
//            AW[i] = 1;
//        }
//        for (int i = 1; i <= Math.min(A, N); i++) {
//            BW[i] = 1;
//        }
//
//        if( A > B ) {
//            for (int i = B+1; i <= Math.min(A, N); i++) {
//                BW[i] = -1;
//            }
//        } else {
//            for (int i = A+1; i <= Math.min(B, N); i++) {
//                AW[i] = -1;
//            }
//        }
//
//        for (int i = Math.max(A, B)+1; i <= N; i++) {
//            if( isAnyLose(BW, i-A, i-1) ) {
//                AW[i] = 1;
//            } else {
//                AW[i] = -1;
//            }
//
//            if( isAnyLose(AW, i-B, i-1) ) {
//                BW[i] = 1;
//            } else {
//                BW[i] = -1;
//            }
//        }
//
//        System.out.println( Arrays.toString(AW) );
//        System.out.println( Arrays.toString(BW) );
//
//        return AW[N] == 1;
    }

    static boolean isAnyLose(int[] W, int from, int to) {
        for (int i = from; i <= to ; i++) {
            if( W[i] == -1 ) return true;
        }
        return false;
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