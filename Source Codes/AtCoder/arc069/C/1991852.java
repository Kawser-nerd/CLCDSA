import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        Solver s = new Solver();
        for (int i = 1; i <= t; i++) {
            s.solve(i, in, out);
        }
        out.close();
    }

}

class Solver {

    private static final int INF = (int) 1e9;

    static class Pair {
        int val, idx;
    }

    void solve(int test, InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        Pair[] a = new Pair[n + 1];
        a[0] = new Pair();
        a[0].val = 0;
        a[0].idx = INF;
        for (int i = 1; i <= n; i++) {
            a[i] = new Pair();
            a[i].val = in.nextInt();
            a[i].idx = i;
        }
        Arrays.sort(a, 1, n + 1, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.val != o2.val) return Integer.compare(o1.val, o2.val);
                return Integer.compare(o1.idx, o2.idx);
            }
        });
//        for (int i = 1; i <= n; i++) out.print(a[i].val + " ");
//        out.println();
//        for (int i = 1; i <= n; i++) out.print(a[i].idx + " ");
//        out.println();
        TreeMap<Integer, Long> map = new TreeMap<>();
        int it = n, size = 1, minIndex = Integer.MAX_VALUE;
        while (it >= 1) {
            if (a[it].val > a[it - 1].val) {
                minIndex = Math.min(minIndex, a[it].idx);
                map.put(minIndex, map.get(minIndex) == null ?  size * (long) (a[it].val - a[it - 1].val) : map.get(minIndex) + size * (long) (a[it].val - a[it - 1].val));
            }
//            out.println("Min Index " + minIndex);
            it--;
            size++;
        }
        for (int i = 1; i <= n; i++) {
            if (map.containsKey(i)) {
                out.println(map.get(i));
            } else {
                out.println(0);
            }
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = null;
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}