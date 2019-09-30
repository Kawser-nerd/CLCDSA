import java.io.*;
import java.util.*;

public class Main {
    static MyScanner sc;
    private static PrintWriter out;
    static long M2 = 1_000_000_000L + 7;

    public static void main(String[] s) throws Exception {
        StringBuilder stringBuilder = new StringBuilder();


//        stringBuilder.append("1000000 10000 ");
//        for (int l = 0; l < 10000; l++) {
//            stringBuilder.append((l + 1) + "   " + (l + 2) + " 100000 ");
//        }

//        stringBuilder.append("4 5\n" +
//                "1 2\n" +
//                " 1 2 18\n" +
//                "                1 3 3\n" +
//                "                3 4 9\n" +
//                "                1 4 12\n" +
//                "                2 4 6");

//        stringBuilder.append("8 13\n" +
//                "4 2\n" +
//                "7 3 9\n" +
//                "6 2 3\n" +
//                "1 6 4\n" +
//                "7 6 9\n" +
//                "3 8 9\n" +
//                "1 2 2\n" +
//                "2 8 12\n" +
//                "8 6 9\n" +
//                "2 5 5\n" +
//                "4 2 18\n" +
//                "5 3 7\n" +
//                "5 1 515371567\n" +
//                "4 8 6");

        if (stringBuilder.length() == 0) {
            sc = new MyScanner(System.in);
        } else {
            sc = new MyScanner(new BufferedReader(new StringReader(stringBuilder.toString())));
        }


        out = new PrintWriter(new OutputStreamWriter(System.out));
        initData();
        solve();
        out.flush();
    }


    private static void initData() {

    }


    private static void solve() throws IOException {

        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt() - 1;
        int t = sc.nextInt() - 1;

        HashMap<Integer, Integer>[] ne = new HashMap[n];
        Arrays.setAll(ne, l -> new HashMap<>());
        for (int i = 0; i < m; i++) {
            int l1 = sc.nextInt() - 1;
            int l2 = sc.nextInt() - 1;
            int d = sc.nextInt();
            ne[l1].put(l2, d);
            ne[l2].put(l1, d);
        }
        long[][] l1 = dks(s, ne);
        long[][] l2 = dks(t, ne);


        long totalP = l1[1][t];
        totalP = (totalP * (totalP - 1)) % M2;

        long dist = l1[0][t];
        for (int r = 0; r < n; r++) {
            if (l1[0][r] + l2[0][r] != dist || l1[0][r] * 2 > dist) continue;

            if (l1[0][r] * 2 == dist) {
                // mid vertex
                long r0 = (l1[1][r] * l2[1][r]) % M2;
                r0 = (r0 * (r0 - 1)) % M2;
                totalP = (totalP - r0 + M2) % M2;
                continue;
            }

            long toThis = l1[0][r];
            for (Map.Entry<Integer, Integer> edge : ne[r].entrySet()) {
                if (dist != toThis + edge.getValue() + l2[0][edge.getKey()] || (toThis + edge.getValue()) * 2 <= dist)
                    continue;

                // mid edge
                long r0 = (l1[1][r] * l2[1][edge.getKey()]) % M2;
                r0 = (r0 * (r0 - 1)) % M2;
                totalP = (totalP - r0 + M2) % M2;

            }
        }

        out.println(totalP % M2);
    }

    /*
                2 4 18

                2 6 3
                6 8 9

                2 8 12
                4 8 6
                */
    private static long[][] dks(int start, HashMap<Integer, Integer>[] neig) {
        int n = neig.length;
        Heap heap = new Heap(n + 1, true);
        boolean[] visited = new boolean[n];
        visited[start] = true;

        heap.add(start, 0);
        long[] length = new long[n];
        long[] ct = new long[n];
        ct[start] = 1;
        while (heap.size() > 0) {
            int topIndex = heap.topIndex();
            long val = heap.removeTop();
            visited[topIndex] = true;
            length[topIndex] = val;

            for (Map.Entry<Integer, Integer> entry : neig[topIndex].entrySet()) {
                if (visited[entry.getKey()]) continue;
                if (heap.exists(entry.getKey())) {
                    if (heap.get(entry.getKey()) > val + entry.getValue()) {
                        heap.update(entry.getKey(), val + entry.getValue());
                        ct[entry.getKey()] = ct[topIndex];
                    } else if (heap.get(entry.getKey()) == val + entry.getValue()) {
                        ct[entry.getKey()] += ct[topIndex];
                        ct[entry.getKey()] %= M2;
                    }
                } else {
                    heap.add(entry.getKey(), entry.getValue() + val);
                    ct[entry.getKey()] = ct[topIndex];
                }
            }

        }

        return new long[][]{length, ct};
    }


    private static final class Heap {
        long[] vals;
        int[] indexesForw;
        boolean[] indexesExist;
        int[] indexesBack;
        int size;
        boolean min;

        public Heap(int n, boolean min) {
            vals = new long[n + 1];
            indexesForw = new int[n + 1];
            indexesBack = new int[n + 1];
            indexesExist = new boolean[n + 1];
            this.min = min;
        }

        public long get(int index) {
            return vals[indexesForw[index]];
        }

        public void add(int index, long p) {
            size++;
            vals[size] = p;
            indexesForw[index] = size;
            indexesBack[size] = index;
            indexesExist[index] = true;
            up(size);
        }

        public int size() {
            return size;
        }

        public long top() {
            return vals[1];
        }

        public int topIndex() {
            return indexesBack[1];
        }

        public long removeTop() {
            long val = vals[1];
            swap(1, size);
            indexesExist[indexesBack[size]] = false;
            size--;
            down(1);
            return val;
        }

        void down(int v) {
            int l = v * 2;
            int r = v * 2 + 1;
            if (l > size) {
                return;
            }
            if (r > size && leftUpIndex(l, v)) {
                swap(l, v);
            }
            if (size > l) {
                if (leftUpIndex(r, l)) {
                    if (leftUpIndex(r, v)) {
                        swap(r, v);
                        down(r);
                    }

                } else {
                    if (leftUpIndex(l, v)) {
                        swap(l, v);
                        down(l);
                    }
                }
            }

        }

        void swap(int i1, int i2) {
            long prev = vals[i1];
            vals[i1] = vals[i2];
            vals[i2] = prev;

            int prev1 = indexesBack[i1];
            indexesBack[i1] = indexesBack[i2];
            indexesBack[i2] = prev1;

            indexesForw[indexesBack[i1]] = i1;
            indexesForw[indexesBack[i2]] = i2;

        }

        void up(int p) {
            if (p == 1) {
                return;
            }
            if (leftUpIndex(p, p / 2)) {
                swap(p, p / 2);
                up(p / 2);
            }
        }

        boolean leftUpIndex(int a, int b) {
            return leftUp(vals[a], vals[b]);
        }

        boolean leftUp(long a, long b) {
            return min ? a < b : a > b;
        }


        public void update(int index, long value) {
            int valll = indexesForw[index];
            long oldVal = vals[valll];
            vals[valll] = value;
            if (leftUp(oldVal, value)) {
                down(valll);
            } else {
                up(valll);
            }

        }

        public boolean exists(int index) {
            return indexesExist[index];
        }
    }


    static boolean bpm(boolean[][] bpGraph, int u, boolean seen[],
                       int matchR[]) {
        // Try every job one by one
        for (int v = 0; v < bpGraph.length; v++) {
            // If applicant u is interested in job v and v
            // is not visited
            if (bpGraph[u][v] && !seen[v]) {
                seen[v] = true; // Mark v as visited

                // If job 'v' is not assigned to an applicant OR
                // previously assigned applicant for job v (which
                // is matchR[v]) has an alternate job available.
                // Since v is marked as visited in the above line,
                // matchR[v] in the following recursive call will
                // not get job 'v' again
                if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                        seen, matchR)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    // Returns maximum number of matching from M to N
    static int[] maxBPM(boolean[][] bpGraph) {
        // An array to keep track of the applicants assigned to
        // jobs. The value of matchR[i] is the applicant number
        // assigned to job i, the value -1 indicates nobody is
        // assigned.
        int matchR[] = new int[bpGraph.length];

        // Initially all jobs are available
        for (int i = 0; i < bpGraph.length; ++i)
            matchR[i] = -1;

        int result = 0; // Count of jobs assigned to applicants
        for (int u = 0; u < bpGraph.length; u++) {
            // Mark all jobs as not seen for next applicant.
            boolean seen[] = new boolean[bpGraph.length];
            for (int i = 0; i < bpGraph.length; ++i)
                seen[i] = false;

            // Find if the applicant 'u' can get a job
            if (bpm(bpGraph, u, seen, matchR))
                result++;
        }
        return matchR;
    }

    private static final int[][] mm(int[][] v1, int[][] v2) {
        int[][] res = new int[v1.length][v1.length];
        for (int s = 0; s < v1.length; s++)
            for (int s1 = 0; s1 < v1.length; s1++) {
                for (int k = 0; k < v1.length; k++) {
                    res[s1][s] += v1[k][s] * v2[s1][k];
                }
            }
        return res;
    }


    private static int ccw(int[] i1, int[] i2) {
        return ccw(i1, i2, new int[]{0, 0});
    }

    private static int ccw(int[] s1, int[] s2, int[] right) {
        long xa = s1[0] - right[0];
        long xb = s1[1] - right[1];
        long ya = s2[0] - right[0];
        long yb = s2[1] - right[1];
        return Long.compare(xb * ya, xa * yb);
    }


    private static void solveT() throws IOException {
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }

    private static long gcd(long l, long l1) {
        if (l > l1) return gcd(l1, l);
        if (l == 0) return l1;
        return gcd(l1 % l, l);
    }

    private static long pow(long a, long b, long m) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long pp = pow(a, b / 2, m);
        pp *= pp;
        pp %= m;
        return (pp * (b % 2 == 0 ? 1 : a)) % m;
    }


    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        MyScanner(BufferedReader br) {
            this.br = br;
        }

        public MyScanner(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        String next() {
            findToken();
            return st.nextToken();
        }

        Integer[] nab(int n) {
            Integer[] k = new Integer[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.fi();
            }
            return k;
        }

        int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.fi();
            }
            return k;
        }

        long[] nl(int n) {
            long[] k = new long[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextLong();
            }
            return k;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int fi() {
            String t = next();
            int cur = 0;
            boolean n = t.charAt(0) == '-';
            for (int a = n ? 1 : 0; a < t.length(); a++) {
                cur = cur * 10 + t.charAt(a) - '0';
            }
            return n ? -cur : cur;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }


} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.