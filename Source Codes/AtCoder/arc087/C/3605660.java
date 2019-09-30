import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static long L;
    static String[] S;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        L = sc.nextLong();

        S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.next();
        }

        System.out.println(solve() ? "Alice" : "Bob");
    }

    static boolean solve() {
        Node root = new Node(0);

        for (int i = 0; i < N; i++) {
            String s = S[i];
            Node curr = root;

            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if( c == '0' ) {
                    curr = curr.left();
                } else {
                    curr = curr.right();
                }
            }
        }

        piles = new ArrayList<>();
        dfs(root);
        // System.out.println( piles );
        long xor = calcXor();
        // System.out.println( xor );
        return xor != 0;
    }

    static List<Long> piles;

    static void dfs(Node curr) {
        // ?????????????????
        if( curr.l != null && curr.r == null || curr.l == null && curr.r != null ) {
            piles.add(L - curr.depth);
        }
        if( curr.l != null ) {
            dfs(curr.l);
        }
        if( curr.r != null ) {
            dfs(curr.r);
        }
    }

    static long calcXor() {
        long xor = 0;
        for (Long pile : piles) {
            xor ^= toGlundy(pile);
        }
        return xor;
    }

    // ?????2?????????????????
    static long toGlundy(long pile) {
        // ??????????????...
        long glundy = 1;
        while( pile % 2 == 0 ) {
            pile /= 2;
            glundy *= 2;
        }
        return glundy;
    }

    static class Node {
        int depth;

        Node l;
        Node r;

        public Node(int depth) {
            this.depth = depth;
        }

        public Node left() {
            if( l == null ) {
                l = new Node(depth+1);
            }
            return l;
        }

        public Node right() {
            if( r == null ) {
                r = new Node(depth+1);
            }
            return r;
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