import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int K;
    static int Q;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        Q = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static int solve() {
        int[] S = Arrays.copyOf(A, N);
        Arrays.sort(S);

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int a = A[i];

            ans = Math.min(calc(a), ans);
        }
        return ans;
    }

    static int calc(int min) {
        List<Integer> values = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if( A[i] < min ) {
                // K????????size-k+1?????
                if( cur.size() >= K ) {
                    cur.sort(Comparator.naturalOrder());
                    for (int j = 0; j < cur.size()-K+1; j++) {
                        values.add(cur.get(j));
                    }
                }
                cur.clear();

            } else {
                cur.add(A[i]);
            }
        }

        if( cur.size() >= K ) {
            cur.sort(Comparator.naturalOrder());
            for (int j = 0; j < cur.size()-K+1; j++) {
                values.add(cur.get(j));
            }
        }

        values.sort(Comparator.naturalOrder());

        // Q??????????
        if( values.size() < Q ) {
            return Integer.MAX_VALUE;
        } else {
            int max = values.get(Q - 1);
            return max - min;
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