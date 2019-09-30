import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt() + 1;
        parent = new int[n];
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 1 ; i < n; i++) {
            parent[i] = in.nextInt();
            graph[parent[i]].add(i);
        }

        ptr = new int[n];
        for (int i = 0; i < n ; i++) {
            ptr[i] = i;
        }
        deq = new Deque[n];
        for (int i = 0; i < n ; i++) {
            deq[i] = new ArrayDeque<>();
        }
        depth = new int[n];
        for (int i = n-1 ; i >= 0 ; i--) {
            for (int to : graph[i]) {
                depth[i] = Math.max(depth[i], depth[to]);
            }
            depth[i]++;
        }
        height = new int[n];
        
        for (int i = n-1 ; i >= 0 ; i--) {
            int cn = graph[i].size();
            if (cn == 0) {
                deq[ptr[i]].add(new long[]{1, 1, 0});
            } else if (cn == 1) {
                int c = graph[i].get(0);
                ptr[i] = ptr[c];
                deq[ptr[i]].addFirst(new long[]{1, 1, 0});
            } else {
                int[][] dn = new int[cn][2];
                for (int j = 0; j < cn ; j++) {
                    dn[j][0] = graph[i].get(j);
                    dn[j][1] = depth[dn[j][0]];
                }
                Arrays.sort(dn, Comparator.comparingInt(a -> a[1]));

                for (int j = 0; j < cn-1 ; j++) {
                    int u = dn[j][0];
                    int v = dn[j+1][0];
                    merge(deq[ptr[u]], deq[ptr[v]], j+1 == cn-1);
                }
                ptr[i] = ptr[dn[cn-1][0]];
                deq[ptr[i]].addFirst(new long[]{1, 1, 0});
            }
        }


        dfs(0, 0);

        int[] heightCount = new int[n+1];
        for (int i = 0; i < n ; i++) {
            heightCount[height[i]]++;
        }

        long[] pow2 = new long[n+1];
        pow2[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            pow2[i] = pow2[i-1] * 2 % MOD;
        }


        int maxD = deq[ptr[0]].size();
        long ans = 0;
        for (int i = 0 ; i < maxD ; i++) {
            long ways = deq[ptr[0]].pollFirst()[1];
            int left = n - heightCount[i];
            ans += ways * pow2[left] % MOD;
            ans %= MOD;
        }
        out.println(ans);
        out.flush();
    }


    static int MOD = 1000000007;
    static int[] depth;
    static int[] height;
    static int[] ptr;
    static int[] parent;
    static List<Integer>[] graph;
    static Deque<long[]>[] deq;

    static void dfs(int now, int h) {
        height[now] = h;
        for (int to : graph[now]) {
            dfs(to, h+1);
        }
    }

    static void merge(Deque<long[]> a, Deque<long[]> b, boolean isLast) {
        int n = Math.min(a.size(), b.size());

        Deque<long[]> ab = new ArrayDeque<>();
        for (int i = 0 ; i < n ; i++) {
            long[] aa = a.pollFirst();
            long[] bb = b.pollFirst();
            long all = ((aa[0] + aa[1] + aa[2]) % MOD) * ((bb[0] + bb[1] + bb[2]) % MOD) % MOD;
            long zero = aa[0] * bb[0] % MOD;
            long one = (aa[0] * bb[1] + aa[1] * bb[0]) % MOD;
            long two = (all + MOD + MOD - zero - one) % MOD;
            if (isLast) {
                zero += two;
                zero %= MOD;
                two = 0;
            }
            ab.add(new long[]{zero, one, two});
        }
        for (int i = 0; i < n ; i++) {
            b.addFirst(ab.pollLast());
        }
    }


    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.