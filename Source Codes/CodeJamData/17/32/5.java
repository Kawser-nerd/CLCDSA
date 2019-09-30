import java.io.*;
import java.util.*;


public class Solution {
    private static String inputFilename = "input.txt";
    private static String outputFilename = "output.txt";
    private BufferedReader in;
    private StringTokenizer line;
    private PrintWriter out;
    private boolean isDebug;

    public Solution(boolean isDebug) {
        this.isDebug = isDebug;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        A[] a = new A[n + m];
        for (int i = 0; i < n; i++) {
            A cr = a[i] = new A();
            cr.owner = 0;
            cr.from = nextInt();
            cr.to = nextInt();
        }
        for (int i = 0; i < m; i++) {
            A cr = a[n + i] = new A();
            cr.owner = 1;
            cr.from = nextInt();
            cr.to = nextInt();
        }
        Arrays.sort(a, new Comparator<A>() {
            @Override
            public int compare(A o1, A o2) {
                return o1.from - o2.from;
            }
        });
        n = n + m;
        ArrayList<Integer>[] d = new ArrayList[]{new ArrayList<Integer>(), new ArrayList<Integer>()};
        int[] s = new int[]{0, 0};
        int res = 0;
        for (int i = 0; i < n; i++) {
            A cr = a[i];
            A nx = a[(i + 1) % n];
            s[cr.owner] += cr.to - cr.from;
            if (cr.owner == nx.owner) {
                int dff = i + 1 < n ? (nx.from - cr.to) : (24 * 60 - cr.to + nx.from);
                s[cr.owner] += dff;
                d[cr.owner].add(dff);
            } else {
                res++;
            }
        }
        if (s[0] > 12 * 60 || s[1] > 12 * 60) {
            int bd = s[0] > 12 * 60 ? 0 : 1;
            int toSub = s[bd] - 12 * 60;
            ArrayList<Integer> dd = d[bd];
            Collections.sort(dd, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2 - o1;
                }
            });
            for (int i : dd) {
                toSub -= i;
                res += 2;
                if (toSub <= 0) break;
            }
        }
        out.println(res);
    }

    private static class A {
        int owner;
        int from;
        int to;
    }

    public static void main(String[] args) throws IOException {
        new Solution(Arrays.asList(args).contains("DEBUG_MODE")).run(args);
    }

    public void run(String[] args) throws IOException {
        if (isDebug) {
            in = new BufferedReader(new InputStreamReader(new FileInputStream(inputFilename)));
//            in = new BufferedReader(new InputStreamReader(System.in));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
        }
//        out = new PrintWriter(System.out);
        out = new PrintWriter(outputFilename);

        int t = nextInt();
//        int t = 1;
        for (int i = 0; i < t; i++) {
            out.print("Case #" + (i + 1) + ": ");
            solve();
        }

        in.close();
        out.flush();
        out.close();
    }

    private int[] nextIntArray(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    private long[] nextLongArray(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (line == null || !line.hasMoreTokens()) {
            line = new StringTokenizer(in.readLine());
        }
        return line.nextToken();
    }
}
