import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int H;
    static long A;
    static long B;
    static long C;
    static long D;
    static long E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        H = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        D = sc.nextInt();
        E = sc.nextInt();

        System.out.println(solve());
    }

    static long solve() {
        long ans = Long.MAX_VALUE;

        for (int i = 0; i <= N; i++) {
            // j*D - k*E > -H - i*B (H + i*B + j*D - k*E > 0 ??)
            // N = i + j + k
            // ????j???????

            // k = N - i - j
            // j*D - (N-i-j)*E > -H - i*B
            // j*D - N*E + i*E + j*E > -H - i*B
            // j*D + j*E > N*E - H - i*B - i*E
            // j * (D + E) > N*E - H - i*B - i*E
            // j > (N*E - H - i*B - i*E) / (D + E)

            long R = N*E - H - i*B - i*E;
            long j = (R+D+E) / (D+E);

            if( j < 0 ) j = 0; // i???????

            long cost = i*A + j*C;
            ans = Math.min(cost, ans);
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