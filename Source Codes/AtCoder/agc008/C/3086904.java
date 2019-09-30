import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        A = sc.nextIntArray(7);

        System.out.println(solve());
    }

    static long solve() {
        long ans = 0;
        ans += A[1];

        int I = A[0];
        int J = A[3];
        int L = A[4];

        // ???????????????
        if( I > 2 ) {
            if( I % 2 == 0 ) {
                int pair = (I - 2) / 2;
                ans += pair * 2;
                I -= pair * 2;
            } else {
                int pair = I / 2;
                ans += pair * 2;
                I -= pair * 2;
            }
        }

        if( J > 2 ) {
            if( J % 2 == 0 ) {
                int pair = (J - 2) / 2;
                ans += pair * 2;
                J -= pair * 2;
            } else {
                int pair = J / 2;
                ans += pair * 2;
                J -= pair * 2;
            }
        }

        if( L > 2 ) {
            if( L % 2 == 0 ) {
                int pair = (L - 2) / 2;
                ans += pair * 2;
                L -= pair * 2;
            } else {
                int pair = L / 2;
                ans += pair * 2;
                L -= pair * 2;
            }
        }

        // (2, 2, 2)
        if( I == 2 && J == 2 && L == 2 ) {
            ans += 6;

            // (2, 2, ?)
        } else if( I == 2 && J == 2 || I == 2 && L == 2 || J == 2 && L == 2 ) {
            ans += 4;

            // (1, 1, 1)
        } else if( I >= 1 &&  J >= 1 && L >= 1 ) {
            ans += 3;

            // (2, ?, ?)
        } else if( I == 2 || J == 2 || L == 2 ) {
            ans += 2;
        }

        return ans;
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