import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.util.ArrayList;
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
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();


            List<Interval> d1 = new ArrayList<>();
            List<Interval> d2 = new ArrayList<>();

            for (int s = 0; s < n; s++) {
                int s1 = in.nextInt();
                int s2 = in.nextInt();
                d1.add(new Interval(s1, s2, s));
                d2.add(new Interval(s1, s2, s));
            }
            d1.sort(Interval.start().reversed());
            d2.sort(Interval.end());


            out.println(Math.max(mm(new List[]{d1, d2}, 0), mm(new List[]{d1, d2}, 1)));

        }

        private long mm(List<Interval>[] lists, int cur) {
            int n = lists[0].size();
            boolean[] deleted = new boolean[n];
            int last = 0;
            long ans = 0;

            int[] k = new int[]{0, 0};
            for (int l = 0; l < n; l++) {
                while (deleted[lists[cur].get(k[cur]).index]) {
                    k[cur]++;
                }
                Interval curItem = lists[cur].get(k[cur]);
                cur = 1 - cur;
                deleted[curItem.index] = true;
                if (last >= curItem.from && last <= curItem.to) {
                    continue;
                }

                if (last > curItem.to) {
                    ans += Math.abs(last - curItem.to);
                    last = curItem.to;
                } else {
                    ans += Math.abs(last - curItem.from);
                    last = curItem.from;
                }
            }
            return Math.abs(last) + ans;
        }

    }

    static class Interval {
        public int from;
        public int to;
        public int index;

        public Interval(int from, int to, int index) {
            this.from = from;
            this.to = to;
            this.index = index;
        }

        public static Comparator<Interval> end() {
            return Comparator.comparingInt(s -> s.to);
        }

        public static Comparator<Interval> start() {
            return Comparator.comparingInt(s -> s.from);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.