import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int M;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1);
        }

        System.out.println( solve() ? "YES" : "NO" );
    }

    static class Edge {
        int a;
        int b;

        public Edge(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static boolean solve() {
        int[] T = new int[N];
        for (Edge e : E) {
            T[e.a]++;
            T[e.b]++;
        }

        for (int t : T) {
            if( t % 2 == 1 ) return false;
        }
        return true;
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

        double nextDouble() {
            return Double.parseDouble(next());
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