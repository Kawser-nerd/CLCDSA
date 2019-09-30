import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A, B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();

        A = new int[N-1];
        B = new int[N-1];
        for (int i = 0; i < N - 1; i++) {
            A[i] = i+1;
            B[i] = fc.nextInt();
        }

        int[] answer = solve();
        PrintWriter pw = new PrintWriter(System.out);
        for (int i : answer) {
            pw.println(i);
        }
        pw.flush();
    }

    static int[] solve() {
        // ????????????(leaf=1)
        int[][] G = adjB(N, A, B);
        int[] dp = new int[N];
        int[] answer = new int[N];
        for (Node node : orderFromLeaf(N, G, 0)) {
            int max = -1;
            int notParent = 1; // 1 == self
            for (int next : G[node.a]) {
                if( next == node.parent ) continue;

                notParent += dp[next];
                max = Math.max(dp[next], max);
            }

            // parent??????????????????
            int parent = N - notParent;
            max = Math.max(parent, max);
            dp[node.a] = notParent;
            answer[node.a] = max;
        }
        return answer;
    }

    static Node[] orderFromLeaf(int N, int[][] G, int root) {
        ArrayDeque<Node> q = new ArrayDeque<>();
        Node[] ret = new Node[N];
        int idx = N-1;
        q.add(new Node(-1, root));
        while(!q.isEmpty()) {
            Node n = q.poll();
            ret[idx--] = n;
            for (int next : G[n.a]) {
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

    static int[][] adjB(int n, int[] from, int[] to) {
        int[][] adj = new int[n][];
        int[] cnt = new int[n];
        for (int f : from) {
            cnt[f]++;
        }
        for (int t : to) {
            cnt[t]++;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new int[cnt[i]];
        }
        for (int i = 0; i < from.length; i++) {
            adj[from[i]][--cnt[from[i]]] = to[i];
            adj[to[i]][--cnt[to[i]]] = from[i];
        }
        return adj;
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