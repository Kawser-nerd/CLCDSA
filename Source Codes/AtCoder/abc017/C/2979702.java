import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static Dangeon[] D;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        D = new Dangeon[N];
        for (int i = 0; i < N; i++) {
            D[i] = new Dangeon(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }
        System.out.println( solve() );
    }

    static int solve() {
        int[] imos = new int[M+1]; // M???
        int total = 0;
        for (Dangeon d : D) {
            imos[d.l] += d.s;
            imos[d.r+1] -= d.s;
            total+= d.s;
        }
        int min = imos[0];
        for (int i = 1; i < M; i++) {
            imos[i] += imos[i-1];
            min = Math.min(imos[i], min);
        }
        return total - min;
    }

    static class Dangeon {
        int l, r, s;

        public Dangeon(int l, int r, int s) {
            this.l = l;
            this.r = r;
            this.s = s;
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