import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static Node[] A, B;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();

        A = new Node[N];
        B = new Node[N];
        for (int i = 0; i < N; i++) {
            A[i] = new Node(i, sc.nextInt(), true);
            B[i] = new Node(i, sc.nextInt(), false);
        }

        System.out.println(solve());
    }

    static long solve() {
        Node[] all = new Node[N*2];
        System.arraycopy(A, 0, all, 0, N);
        System.arraycopy(B, 0, all, N, N);

        Arrays.sort(all, Comparator.comparingInt(n -> n.n));

        long half = 0;
        Set<Integer> found = new HashSet<>();
        int a = 0;
        int b = 0;
        boolean ab = false;
        for (int i = 0; i < N; i++) {
            Node node = all[i];
            half += node.n;
            if( node.a ) {
                a++;
            } else {
                b++;
            }
            if( found.contains(node.i) ) {
                ab = true;
            } else {
                found.add( node.i );
            }
        }
        if( a == 0 || b == 0 || ab ) {
            return half;

        } else {
            Node x1 = all[N-1];
            Node y1 = all[N];

            if( x1.i != y1.i ) {
                return half - x1.n + y1.n;
            } else {
                Node x2 = all[N-2];
                Node y2 = all[N+1];
                if( y1.n - x2.n < y2.n - x1.n ) {
                    return half - x2.n + y1.n;
                } else {
                    return half - x1.n + y2.n;
                }
            }
        }
    }

    static class Node {
        int i;
        int n;
        boolean a;

        public Node(int i, int n, boolean a) {
            this.i = i;
            this.n = n;
            this.a = a;
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