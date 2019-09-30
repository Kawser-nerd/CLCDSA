import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static char[][] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        C = new char[19][];
        for (int i = 0; i < 19; i++) {
            C[i] = sc.next().toCharArray();
        }
        System.out.println(solve() ? "YES" : "NO");
    }

    static boolean solve() {
        int b = 0;
        int w = 0;
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                if( C[i][j] == 'o' ) {
                    b++;
                } else if(C[i][j] == 'x') {
                    w++;
                }
            }
        }

        int d = b - w;
        if( d != 0 && d != 1 ) {
            return false;
        }

        if( d == 1 ) {
            // ???????????
            return isOk('o', 'x');

        } else {
            // ???????????
            return isOk('x', 'o');
        }
    }

    static boolean isOk(char current, char prev) {
        // 1. prev?5??????x
        if( exists5(prev) ) {
            return false;
        }

        // 2. current??????5???????????x
        //  => ??????????5???????????ok
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                char t = C[i][j];
                C[i][j] = '.';
                if( !exists5(current) ) {
                    return true;
                }
                C[i][j] = t;
            }
        }
        return false;
    }

    static boolean exists5(char c) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                if( C[i][j] == c ) {
                    // 14, 15, 16, 17 18
                    if (i < 15 && C[i+1][j] == c && C[i+2][j] == c && C[i+3][j] == c && C[i+4][j] == c) return true;
                    if (j < 15 && C[i][j+1] == c && C[i][j+2] == c && C[i][j+3] == c && C[i][j+4] == c) return true;
                    if (i < 15 && j < 15 && C[i+1][j+1] == c && C[i+2][j+2] == c && C[i+3][j+3] == c && C[i+4][j+4] == c ) return true;
                    if (i > 3 && j < 15 && C[i-1][j+1] == c && C[i-2][j+2] == c && C[i-3][j+3] == c && C[i-4][j+4] == c ) return true;
                }
            }
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