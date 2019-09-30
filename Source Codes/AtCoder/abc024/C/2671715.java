import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static Scanner sc;
    private static int[][] neg8 = new int[][]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    private static int[][] neg4 = new int[][]{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    private static int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) {
        Main instance = new Main();
        sc = instance.new Scanner();
        instance.solve();
    }

    private void solve() {
        try {
            int N=sc.nextInt();
            int D=sc.nextInt();
            int K=sc.nextInt();

            D[] migrations = new D[D];
            for (int i = 0; i < D; i++) {
                int l = sc.nextInt();
                int r = sc.nextInt();
                migrations[i] = new D(l, r);
            }

            for (int i = 0; i < K; i++) {
                int current = sc.nextInt();
                int T = sc.nextInt();
                boolean toMin = current > T;

                int count=0;
                for (Main.D m : migrations) {
                    count++;
                    if (current >= m.f && current <= m.s) {
                        current = toMin ? m.f : m.s;
                    }
                    if ((!toMin && current >= T) || (toMin && current <= T)) {
                        System.out.println(count);
                        break;
                    }
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static class D extends Pair<Integer, Integer>{

        public D(int i, int i1) {
            super(i, i1);
        }
    }

    private class Scanner {
        String[] s;
        int i;
        BufferedReader br;
        String regex = " ";

        public Scanner() {
            s = new String[0];
            i = 0;
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        @Override
        protected void finalize() throws Throwable {
            try {
                super.finalize();
            } finally {
                destruction();
            }
        }

        private void destruction() throws IOException {
            if (br != null) br.close();
        }

        public String next() throws IOException {
            if (i < s.length) return s[i++];
            String st = br.readLine();
            while (st == "") st = br.readLine();
            s = st.split(regex, 0);
            i = 0;
            return s[i++];
        }

        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(next());
        }

        public Long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(next());
        }

        public Double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(next());
        }
    }

    private static double distance(int x1, int x2, int y1, int y2) {
        return Math.sqrt((Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2)));
    }

    private static boolean nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        boolean swap = false;
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
            swap = true;
        }
        reverse(nums, i + 1);
        return swap;
    }

    private static void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static ArrayList filledList(int n, int fill) {
        return new ArrayList<>(Collections.nCopies(n, fill));
    }

    // ?????`??`???????????????
    private static int lower_bound(List<Integer> list, int val) {
        return ~Collections.binarySearch(list, val, (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);
    }

    // ?????`?????`???????????????
    private static int upper_bound(List<Integer> list, int val) {
        return ~Collections.binarySearch(list, val, (x, y) -> x.compareTo(y) > 0 ? 1 : -1);
    }

    private static class Pair<F, S> {
        F f;
        S s;

        Pair() {
        }

        Pair(F f, S s) {
            this.f = f;
            this.s = s;
        }

        Pair(Pair<F, S> p) {
            f = p.f;
            s = p.s;
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair) o;
                return f == p.f && s == p.s;
            }
            return false;
        }

        @Override
        public int hashCode() {
            return Objects.hash(f, s);
        }


        @Override
        public String toString() {
            return "{" + f.toString() + ", " + s.toString() + "}";
        }
    }

    // https://atc001.contest.atcoder.jp/tasks/unionfind_a
    private static class UnionFind {
        private int par[] = new int[100005];

        private UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        // ???????
        private int find(int x) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }

        // x?y?????????
        private void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;

            par[x] = y;
        }

        // x?y??????????
        private boolean same(int x, int y) {
            return find(x) == find(y);
        }
    }

    private static class Edge {
        final int from;
        final int to;
        final int cost;

        private Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    private static class BellmanFord {

        /**
         * @param v     ????
         * @param edges
         */
        private BellmanFord(int v, Edge[] edges) {
            this.distances = new int[v];
            this.edges = edges;
        }

        private final int[] distances; //???????
        private final Edge[] edges;

        private int shortestPath(int start, int end) throws NegativeLoopException {
            Arrays.fill(distances, INF);
            distances[start] = 0;
            int count = 0;

            boolean updated = true;
            while (updated) {
                updated = false;
                for (Edge edge : edges) {
                    int u = edge.from;
                    int v = edge.to;
                    int c = edge.cost;
                    // "u????????????" + "u->v?????" ? "v????????????"?????????
                    if (distances[u] != INF && distances[u] + c < distances[v]) {
                        distances[v] = distances[u] + c;
                        updated = true;
                        if (count == distances.length - 1) throw new NegativeLoopException();
                    }
                }
                count++;
            }

            return distances[end];
        }

        private static class NegativeLoopException extends Exception {
        }
    }

    /**
     * ??????
     */
    private static class Dijkstra {

        private final List<List<Edge>> G; // ?????????????
        private static int[] dist; // ???????????

        private Dijkstra(List<List<Edge>> G, int v) {
            this.G = G;
            dist = new int[v];
        }

        // ?????
        private static class Candidate implements Comparable<Candidate> {
            int d; // ??
            int v; // ??

            Candidate(int v, int d) {
                this.d = d;
                this.v = v;
            }

            // ???????????
            @Override
            public int compareTo(Candidate o) {
                return d - o.d;
            }
        }

        private int shortestPath(int sv, int ev) {
            Arrays.fill(dist, INF);
            dist[sv] = 0;

            // ???????????
            Queue<Candidate> candidates = new PriorityQueue<>();
            candidates.offer(new Candidate(sv, 0)); // ????????0?????????

            while (!candidates.isEmpty()) {
                // ???????
                Candidate c = candidates.poll();
                int v = c.v;
                int d = c.d;

                // ???????????
                if (dist[v] < d) {
                    continue;
                }

                // ???????????????????????
                List<Edge> edges = G.get(v);
                for (Edge e : edges) {
                    if (dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        candidates.offer(new Candidate(e.to, dist[e.to]));
                    }
                }
            }

            return dist[ev];
        }
    }

    private static class Kruskal {

        private final int v;// ???
        private final Edge[] edges;
        private final UnionFind unionFind;

        private Kruskal(int v, Edge[] edges) {
            this.v = v;
            this.edges = edges;
            this.unionFind = new UnionFind(v);
        }

        private int kruskal() {
            // edge.cost?????????
            Arrays.sort(edges, Comparator.comparingInt(o -> o.cost));

            int res = 0;
            for (Edge edge : edges) {
                if (!unionFind.same(edge.from, edge.to)) {
                    unionFind.unite(edge.from, edge.to);
                    res += edge.cost;
                }
            }
            return res;
        }
    }

    private static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        int g = gcd(a, b);
        return a / g * b;
    }

    private static boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // ?????????
    private static int[] eratosthenes(int n) {
        // false?????
        boolean dp[] = new boolean[n + 1];

        dp[0] = true;
        dp[1] = true;

        List<Integer> primes = new LinkedList<>();
        for (int i = 2; i <= n; i++) {
            if (dp[i]) continue;// ???????????
            primes.add(i);
            // i??????????
            for (int j = i * 2; j <= n; j += i) {
                dp[j] = true;
            }
        }

        int[] ret = new int[primes.size()];
        int count = 0;
        for (Integer prime : primes) {
            ret[count++] = prime;
        }

        return ret;
    }
}