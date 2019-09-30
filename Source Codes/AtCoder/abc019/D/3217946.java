import java.io.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int N;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();


        PrintWriter pw = new PrintWriter(System.out);
        pw.println("! " + solve((a, b) -> {
            pw.println("? " + a + " " + b);
            pw.flush();
            return sc.nextInt();
        }));
        pw.flush();
    }

    static int solve(Query q) {
        int du = -1;
        int u = -1;
        for (int i = 2; i <= N; i++) {
            int d = q.dist(1, i);
            if( d > du ) {
                du = d;
                u = i;
            }
        }

        int dv = -1;
        int v = -1;
        for (int i = 1; i <= N; i++) {
            if( i == u ) continue;

            int d = q.dist(u, i);
            if( d > dv ) {
                dv = d;
                v = i;
            }
        }

        return q.dist(u, v);
    }

    interface Query {
        int dist(int a, int b);
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