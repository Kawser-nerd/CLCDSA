import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
import java.util.Optional;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        Map<Integer, TreeSet<Long>> data = new HashMap<>();

        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.na(n);
            int[] b = in.na(n);
            long res = 0;

            List<TreeSet<Long>> res0 = new ArrayList<>();
            for (int s = 0; s < n; s++) {
                if (b[s] == a[s]) continue;
                if (2 * b[s] >= a[s]) {
                    out.println(-1);
                    return;
                }

                TreeSet<Long> a1 = tt(a[s], b[s]);
                res0.add(new TreeSet<>(a1));
            }


            while (res0.size() > 0) {
                long nm = nm(res0);
                res += nm;
                res0 = filter(nm, res0);
            }
            out.println(res);
        }

        private long nm(List<TreeSet<Long>> res0) {
            return res0.stream().max(Comparator.comparingLong(TreeSet::first)).get().first();
        }

        private List<TreeSet<Long>> filter(long nm, List<TreeSet<Long>> res0) {
            List<TreeSet<Long>> ret = new ArrayList<>();
            long mask = ~nm;
            for (TreeSet<Long> r : res0) {
                TreeSet<Long> nn = new TreeSet<>();
                for (long x : r) {
                    nn.add(x & mask);
                }
                if (nn.first() != 0)
                    ret.add(nn);
            }
            return ret;

        }

        private TreeSet<Long> tt(int v, int t) {


            if (v == t) return new TreeSet<>();

            int kk = v * 1000 + t;
            if (data.containsKey(kk)) {
                return data.get(kk);
            }

            TreeSet<Long> ret = new TreeSet<>();
            for (int s = v; s >= 1; s--) {
                int r = v % s;
                if (r == t) {
                    ret.add(1L << s);
                } else {
                    if (2 * t < r) {
                        TreeSet<Long> ans = tt(r, t);
                        for (long x : ans) {
                            ret.add((1L << s) | (x));
                        }
                    }
                }
            }
            data.put(kk, ret);
            return ret;
        }

    }

    static class MyScan {
        private final InputStream in;
        private byte[] inbuf = new byte[1024];
        public int lenbuf = 0;
        public int ptrbuf = 0;

        public MyScan(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = nextInt();
            }
            return k;
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}