import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static String A;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        A = fc.next();
        System.out.println(solve());
    }

    static int solve() {
        int diff = countDiff();
        if( diff == 0 ) {
            // ?????????????
            // ????????????????
            if( A.length() % 2 == 0 ) {
                return A.length() * 25;
            } else {
                return (A.length()-1) * 25;
            }

        } else if( diff == 1 ) {
            // ???????????????????????
            return (A.length()-2) * 25 + 24 * 2;

        } else {
            // ?????????????
            return A.length() * 25;
        }
    }

    static int countDiff() {
        int n = A.length();
        int diff = 0;
        for (int i = 0; i < n/2; i++) {
            char a = A.charAt(i);
            char b = A.charAt(n-i-1);

            if( a != b ) diff++;
        }
        return diff;
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