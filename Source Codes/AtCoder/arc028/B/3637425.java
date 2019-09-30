import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int[] X;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        X = sc.nextIntArray(N);

        int[] ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        for (int i : ans) {
            pw.println(i);
        }
        pw.flush();
    }

    static int[] solve() {
        Human[] H = new Human[N];
        for (int i = 0; i < N; i++) {
            H[i] = new Human(i+1, X[i]);
        }

        PriorityQueue<Human> q = new PriorityQueue<>(Comparator.comparingInt(h -> -h.x));
        for (int i = 0; i < K; i++) {
            q.add(H[i]);
        }

        int[] ans = new int[N-K+1];
        ans[0] = q.peek().i;

        for (int i = 1; i < N-K+1; i++) {
            q.add( H[i+K-1] );
            q.poll(); // K+1?????
            ans[i] = q.peek().i;
        }
        return ans;
    }

    static class Human {
        int i, x;

        public Human(int i, int x) {
            this.i = i;
            this.x = x;
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