
import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class C2 {

    private static final int SIZE = 500000;
    long[] a = new long[SIZE];
    long[] b = new long[SIZE];
    int n;

    class Event implements Comparable<Event> {
        int i;
        int s;
        long t;

        public Event(int i, int s, long t) {
            this.i = i;
            this.s = s;
            this.t = t;
        }

        public int compareTo(Event o) {
            if (t != o.t) {
                return Long.compare(t, o.t);
            }
            if (s != o.s) {
                return Integer.compare(o.s, s);
            }
            return Integer.compare(o.i, i);
        }
    }

    private int solveTest2() {

        TreeSet<Event> set = new TreeSet<Event>();

        for (int i = 0; i < n; i++) {
            long t = b[i] * (360 - a[i]);
            set.add(new Event(i, -1, t));
        }

        int q = 0;
        int res = n;
        int s = n;
        while (!set.isEmpty()) {
            Event e = set.pollFirst();
            s += e.s;
            if (e.s > 0) q++;
            if (q == n) break;
            res = Math.min(res, s);
            e.s = 1;
            e.t += (b[e.i] * 360);
            set.add(e);
        }
        return res;
    }


    private int solveTest() throws IOException {
        int m = nextInt();
        n = 0;
        for (int i = 0; i < m; i++) {
            int d = nextInt();
            int h = nextInt();
            int mm = nextInt();
            for (int j = 0; j < h; j++) {
                a[n] = d;
                b[n] = mm++;
                n++;
            }
        }
        return solveTest2();
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C2().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}