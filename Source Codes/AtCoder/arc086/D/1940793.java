import java.io.*;
import java.util.*;

public class Main {
    private FastScanner in;
    private PrintWriter out;

    long smallestNumberOfBits(long from, long to) {
        long res = 0;
        for (int i = 61; i >= 0; i--) {
            long x = 1L << i;
            if ((to & x) == 0) {
                continue;
            }
            if ((from & x) != (to & x)) {
                if (from != res)
                    res |= x;
                break;
            }
            res |= x;
        }
        return res;
    }

    final int mod = (int) 1e9 + 7;

    private void solve() {
        int n = in.nextInt();
        long k = in.nextLong();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        HashMap<Diffs, ArrayList<Segment>> answers = new HashMap<>();
        Arrays.sort(a);
        for (int shift = 0; shift <= 60; shift++) {
            long mod = 1L << shift;
            ArrayList<Long> pos = new ArrayList<>();
            pos.add(0L);
            pos.add(mod);
            for (long value : a) {
                long cur = value & (mod - 1);
                pos.add(cur + 1);
            }
            Collections.sort(pos);
            for (int i = 0; i + 1 < pos.size(); i++) {
                long from = pos.get(i), to = pos.get(i + 1);
                if (from == to) {
                    continue;
                }
                if (from > a[0]) {
                    continue;
                }
                long sub = smallestNumberOfBits(from, to - 1);
                int cost = Long.bitCount(sub) + shift;
                if (cost > k) {
                    continue;
                }
                long[] nvals = new long[n];
                for (int j = 0; j < n; j++) {
                    nvals[j] = (a[j] - sub) >> shift;
                }
                Diffs d = new Diffs(nvals);
                ArrayList<Segment> ar = answers.get(d);
                if (ar == null) {
                    ar = new ArrayList<>();
                }
                long fr = Math.max(0, nvals[0] - (k - cost));
                ar.add(new Segment(fr, nvals[0]));
                answers.put(d, ar);
            }
        }
        long ans = 0;
        for (Map.Entry<Diffs, ArrayList<Segment>> entry : answers.entrySet()) {
            ArrayList<Segment> segs = entry.getValue();
            Collections.sort(segs);
            long to = -1;
            for (Segment s : segs) {
                if (s.to <= to) {
                    continue;
                }
                ans += s.to - Math.max(to + 1, s.from) + 1;
                to = s.to;
            }
        }
        out.println(ans % mod);
    }

    class Segment implements Comparable<Segment> {
        long from, to;

        public Segment(long from, long to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public int compareTo(Segment o) {
            return Long.compare(from, o.from);
        }
    }

    class Diffs {
        long[] d;

        Diffs(long[] vals) {
            d = new long[vals.length - 1];
            for (int i = 0; i + 1 < vals.length; i++) {
                d[i] = vals[i + 1] - vals[i];
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Diffs diffs = (Diffs) o;

            return Arrays.equals(d, diffs.d);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(d);
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("ARC_086_D.in"));
            out = new PrintWriter(new File("ARC_086_D.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}