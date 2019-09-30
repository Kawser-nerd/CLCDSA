import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.IntBinaryOperator;
import java.util.function.IntFunction;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;

public class Main {

    static String S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        S = sc.next();

        System.out.println( solve() );
    }

    static int solve() {
        int[] C = new int[S.length()];
        for (int i = S.length()-1; i >= 1; i--) {
            char c = S.charAt(i);
            C[i-1] = C[i];
            if( c == '+' ) {
                C[i-1]++;

            } else if( c == '-' ) {
                C[i-1]--;
            }
        }

        List<Integer> L = new ArrayList<>();
        List<Integer> R = new ArrayList<>();
        for (int i = 0; i < S.length(); i++) {
            if( S.charAt(i) == 'M') {
                L.add(-C[i]);
                R.add(C[i]);
            }
        }

        Comparator.<Integer>naturalOrder().reversed();
        L.sort(Comparator.<Integer>naturalOrder().reversed());
        R.sort(Comparator.<Integer>naturalOrder().reversed());

        int ans = 0;
        for (int i = 0; i < L.size() / 2; i++) {
            ans += L.get(i);
        }
        for (int i = 0; i < R.size() / 2; i++) {
            ans += R.get(i);
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