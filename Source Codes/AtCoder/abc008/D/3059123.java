import java.awt.*;
import java.awt.geom.Rectangle2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {

    static int W;
    static int H;
    static int N;
    static int[] X;
    static int[] Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        W = sc.nextInt();
        H = sc.nextInt();
        N = sc.nextInt();
        X = new int[N];
        Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt() - 1;
            Y[i] = sc.nextInt() - 1;
        }
        System.out.println( solve() );
    }

    static Map<Rectangle, Integer> MEMO = new HashMap<>();

    static int solve() {
        return dfs(new Rectangle(W, H));
    }

    static int dfs(Rectangle rect) {
        if( MEMO.containsKey(rect) ) return MEMO.get(rect);
        int max = 0;
        for (int i = 0; i < N; i++) {
            int x = X[i];
            int y = Y[i];
            if( !rect.contains(x, y) ) continue;

            int u = y - rect.y;
            int d = (rect.y + rect.height - 1) - y;
            int l = x - rect.x;
            int r = (rect.x + rect.width - 1) - x;
            int gold = u + d + l + r + 1;

            if( u > 0 && l > 0 ) {
                gold += dfs(new Rectangle(rect.x, rect.y, l, u));
            }
            if( u > 0 && r > 0 ) {
                gold += dfs(new Rectangle(x+1, rect.y, r, u));
            }
            if( d > 0 && l > 0 ) {
                gold += dfs(new Rectangle(rect.x, y+1, l, d));
            }
            if( d > 0 && r > 0 ) {
                gold += dfs(new Rectangle(x+1, y+1, r, d));
            }

            max = Math.max(gold, max);
        }

        MEMO.put(rect, max);
        return max;
    }

    static class Key {
        int x1, y1, x2, y2;

        public Key(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Key key = (Key) o;
            return x1 == key.x1 &&
                    y1 == key.y1 &&
                    x2 == key.x2 &&
                    y2 == key.y2;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x1, y1, x2, y2);
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