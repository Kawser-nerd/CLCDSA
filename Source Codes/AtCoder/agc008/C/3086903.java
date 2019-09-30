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
        int I = A[0];
        int J = A[3];
        int L = A[4];

        if( I > 0 && J > 0 && L > 0 ) {
            return Math.max(use(I, J, L), notUse(I, J, L)) + A[1];

        } else {
            return notUse(I, J, L) + A[1];
        }
    }

    static long use(int i, int j, int l) {
        return notUse(i-1, j-1, l-1) + 3;
    }

    static long notUse(int i, int j, int l) {
        long ret = 0;
        ret += i/2*2;
        ret += j/2*2;
        ret += l/2*2;
        return ret;
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