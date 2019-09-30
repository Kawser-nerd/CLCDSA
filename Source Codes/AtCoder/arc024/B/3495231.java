import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static int solve() {
        int[] B;
        if( A[0] != A[N-1] ) {
            B = A;
        } else {
            int kireme = findKireme();
            if( kireme == -1 ) return -1;

            B = new int[N];
            System.arraycopy(A, kireme, B, 0, N-kireme);
            System.arraycopy(A, 0, B, N-kireme, kireme);
        }

        int maxCont = 0;
        int prev = -1;
        int cont = 0;
        for (int i = 0; i < N; i++) {
            if( B[i] == prev ) {
                cont++;
            } else {
                cont = 1;
            }
            maxCont = Math.max(cont, maxCont);
            prev = B[i];
        }
        maxCont = Math.max(cont, maxCont);

        // 3 -> 1
        // 4 -> 2
        // 5 -> 3 -> 1
        // 6 -> 4 -> 2
        if( maxCont <= 2 ) {
            return 1;

        } else {
            // maxCont - 2(day-1) <= 2
            // day >= maxCont / 2
            return maxCont % 2 == 0 ? maxCont / 2 : maxCont / 2 + 1;
        }
    }

    static int findKireme() {
        for (int i = 1; i < N; i++) {
            if( A[i-1] != A[i] ) {
                return i;
            }
        }
        return -1;
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