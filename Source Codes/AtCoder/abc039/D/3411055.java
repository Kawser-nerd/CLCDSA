import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int H;
    static int W;
    static char[][] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        C = new char[H][];
        for (int i = 0; i < H; i++) {
            C[i] = sc.next().toCharArray();
        }

        boolean ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        if( ans ) {
            pw.println("possible");
            for (int i = 0; i < H; i++) {
                pw.println( new String(C[i]) );
            }

        } else {
            pw.println("impossible");
        }
        pw.flush();
    }

    static boolean solve() {
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == '#' && existsAround(h, w, '.') ) {
                    C[h][w] = '?';
                }
            }
        }

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == '?' && !existsAround(h, w, '#') ) {
                    return false;
                }
            }
        }

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if( C[h][w] == '?' ) {
                    C[h][w] = '.';
                }
            }
        }
        return true;
    }

    static int[] DH = {1, 1, 0, -1, -1, -1,  0,  1};
    static int[] DW = {0, 1, 1,  1,  0, -1, -1, -1};

    static boolean existsAround(int h, int w, char c) {
        for (int i = 0; i < 8; i++) {
            int dh = h + DH[i];
            int dw = w + DW[i];
            if( inRange(dh, dw) && C[dh][dw] == c ) return true;
        }
        return false;
    }

    static boolean inRange(int h, int w) {
        return 0 <= h && h < H && 0 <= w && w < W;
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