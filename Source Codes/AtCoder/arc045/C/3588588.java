import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, X;
    static Edge[] E;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        X = sc.nextInt();
        E = new Edge[N-1];
        for (int i = 0; i < N - 1; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }

        System.out.println(solve());
    }

    static long solve() {
        Edge[][] G = adjB(N, E);

        int[] dp = new int[N];
        for (Node n : orderFromRoot(N, G, 0)) {
            Map<Integer, Integer> map = new HashMap<>();

            for (Edge e : G[n.a]) {
                int next = e.opposite(n.a);
                if( next == n.parent ) continue;

                dp[next] = dp[n.a] ^ e.c;
            }
        }

        Map<Integer, Integer> paths = new HashMap<>();
        for (int path : dp) {
            add(paths, path, 1);
        }

        if( X == 0 ) {
            // p1 ^ p2 == 0 => p1 == p2
            long ans = 0;
            for (Map.Entry<Integer, Integer> entry : paths.entrySet()) {
                int p1 = entry.getKey();
                int cnt = entry.getValue();
                // comb(cnt, 2)
                if( cnt >= 2 ) {
                    ans += (long)cnt * (cnt-1) / 2;
                }
            }
            return ans;

        } else {
            long ans = 0;
            for (Map.Entry<Integer, Integer> entry : paths.entrySet()) {
                int p1 = entry.getKey();
                int cnt = entry.getValue();
                // p1 ^ p2 = X
                int p2 = p1 ^ X;
                if( paths.containsKey(p2) ) {
                    ans += (long)cnt * paths.get(p2);
                }
            }
            // ???????????
            return ans / 2;
        }
    }

    static void add(Map<Integer, Integer> map, int key, int value) {
        if( map.containsKey(key) ) {
            map.put(key, map.get(key) + value);
        } else {
            map.put(key, value);
        }
    }

    static Node[] orderFromRoot(int N, Edge[][] G, int root) {
        ArrayDeque<Node> q = new ArrayDeque<>();
        Node[] ret = new Node[N];
        int idx = 0;
        q.add(new Node(-1, 0));
        while(!q.isEmpty()) {
            Node n = q.poll();
            ret[idx++] = n;
            for (Edge e : G[n.a]) {
                int next = e.opposite(n.a);
                if( next == n.parent ) continue;

                q.add(new Node(n.a, next));
            }
        }
        return ret;
    }

    static class Node {
        int parent, a;

        public Node(int parent, int a) {
            this.parent = parent;
            this.a = a;
        }
    }

    static Edge[][] adjB(int n, Edge[] E) {
        Edge[][] adj = new Edge[n][];
        int[] cnt = new int[n];
        for (Edge e : E) {
            cnt[e.a]++;
            cnt[e.b]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new Edge[cnt[i]];
        }
        for (Edge e : E) {
            adj[e.a][--cnt[e.a]] = e;
            adj[e.b][--cnt[e.b]] = e;
        }
        return adj;
    }

    static class Edge {
        int a, b, c;

        public Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        int opposite(int x) {
            return a == x ? b : a;
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