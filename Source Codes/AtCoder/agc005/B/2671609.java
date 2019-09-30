import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);
        System.out.println( solve() );
    }

    private static long solve() {
        Node first = build();

        long sum = 0;
        ArrayDeque<Node> q = new ArrayDeque<>();
        q.add(first);

        while(!q.isEmpty()) {
            Node node = q.poll();
            int prev = 0;
            while(node != null) {
                int time = prev + 1;
                int size = node.underSize() + 1;
                sum += (long)node.a * time * size;

                if( node.under != null ) {
                    q.add(node.under);
                }
                prev += size;
                node = node.right;
            }
        }

        return sum;
    }

    static Node build() {
        Focus focus = new Focus(A[0]);
        for (int i = 1; i < N; i++) {
            focus.add(A[i]);
        }
        return focus.first;
    }

    static class Focus {

        private Node first;
        private Node[] nodes = new Node[N];
        private int len;

        public Focus(int a) {
            first = new Node(a);
            nodes[0] = first;
            len = 1;
        }

        public void add(int a) {
            Node arg = new Node(a);

            int low = 0;
            int high = len;
            while(low < high) {
                int mid = (low + high)/2;
                if( nodes[mid].a < a ) {
                    low = mid+1;
                } else {
                    high = mid;
                }
            }

            if( low < len ) {
                nodes[low].right = arg;
                nodes[low] = arg;
                len = low + 1;

            } else {
                nodes[len-1].under = arg;
                nodes[len] = arg;
                len++;
            }
        }
    }

    static class Node {
        int a;
        private Node right;
        private Node under;

        private int size = -1;

        public Node(int a) {
            this.a = a;
        }

        public int size() {
            if( size == -1 ) {
                int sum = 1;
                if( right != null ) {
                    sum += right.size();
                }
                sum += underSize();
                size = sum;
            }
            return size;
        }

        public int underSize() {
            if( under != null ) {
                return under.size();
            } else {
                return 0;
            }
        }
    }

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