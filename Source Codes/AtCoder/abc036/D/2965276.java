import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] A;
    static int[] B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = new int[N-1];
        B = new int[N-1];
        for (int i = 0; i < N - 1; i++) {
            A[i] = sc.nextInt() -1;
            B[i] = sc.nextInt() -1;
        }
        System.out.println(solve());
    }

    final static int MOD = 1_000_000_007;

    static List<Integer>[] RIN;

    static int solve() {
        RIN = new List[N];
        for (int i = 0; i < N; i++) {
            RIN[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            RIN[A[i]].add(B[i]);
            RIN[B[i]].add(A[i]);
        }

        int b = bfs(0, -1, true);
        int w = bfs(0, -1, false);

        return (b + w) % MOD;
    }

    static Map<Integer, Integer> MEMO = new HashMap<>();

    static int bfs(int a, int parent, boolean bw) {
        int key = a + (bw ? 0 : 1_000_000);
        if( MEMO.containsKey(key) ) return MEMO.get(key);

        long ret = 1;
        if( bw ) {
            for (int to : RIN[a]) {
                if( to == parent ) continue;
                ret = bfs(to, a, false) * ret % MOD;
            }

        } else {
            for (int to : RIN[a]) {
                if( to == parent ) continue;

                int bb = bfs(to, a, true);
                int ww = bfs(to, a, false);
                ret = ((bb + ww) % MOD) * ret % MOD;
            }
        }

        MEMO.put(key, (int)ret);
        return (int)ret;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.