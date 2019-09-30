import java.awt.geom.Line2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static Line2D AB;
    static int AX, AY;
    static int BX, BY;
    static int N;
    static int[] X;
    static int[] Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        AX = sc.nextInt();
        AY = sc.nextInt();
        BX = sc.nextInt();
        BY = sc.nextInt();
        AB = new Line2D.Double(AX, AY, BX, BY);
        N = sc.nextInt();
        X = new int[N];
        Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            Y[i] = sc.nextInt();
        }

        System.out.println( solve() );
    }

    static int solve() {
        int cross = 0;
        for (int i = 0; i < N; i++) {
            int next = (i+1) % N;
            if( isCross(X[i], Y[i], X[next], Y[next]) ) {
                cross++;
            }
        }
        return cross / 2 + 1;
    }

    static boolean isCross(int cx, int cy, int dx, int dy) {
        return AB.intersectsLine(cx, cy, dx, dy);
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