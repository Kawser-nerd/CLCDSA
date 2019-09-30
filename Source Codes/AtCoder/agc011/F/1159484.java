import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.SortedSet;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        long period;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            period = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }
            TreeSet<TaskF.ControlPoint> points = new TreeSet<>();
            points.add(new TaskF.ControlPoint(0, 0));
            long offset = 0;
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    offset = ((offset - a[i - 1] - a[i]) % period + period) % period;
                }
                if (b[i] == 1) {
                    if (2 * a[i] > period) {
                        out.println(-1);
                        return;
                    }
                    int left = (int) ((offset - a[i] + period) % period);
                    int right = (int) ((offset + a[i]) % period);
                    TaskF.ControlPoint pl = ensurePoint(points, left);
                    TaskF.ControlPoint pr = ensurePoint(points, right);
                    if (pl.when < pr.when) {
                        NavigableSet<TaskF.ControlPoint> after = points.tailSet(pl, false);
                        while (!after.isEmpty() && after.first().when < pr.when) {
                            points.remove(after.first());
                        }
                    } else {
                        NavigableSet<TaskF.ControlPoint> after = points.tailSet(pl, false);
                        while (!after.isEmpty()) {
                            points.remove(after.first());
                        }
                        NavigableSet<TaskF.ControlPoint> before = points.headSet(pr, false);
                        while (!before.isEmpty()) {
                            points.remove(before.last());
                        }
                    }
                    long mid = 2L * a[i] - 1;
                    if (!points.add(new TaskF.ControlPoint((int) ((left + mid) % period), pl.value + mid)))
                        throw new RuntimeException();
                }
            }
            long res = Long.MAX_VALUE;
            for (TaskF.ControlPoint p : points) {
                res = Math.min(res, p.value);
            }
            for (int i = 0; i < n; ++i) res += 2L * a[i];
            out.println(res);
        }

        private TaskF.ControlPoint ensurePoint(TreeSet<TaskF.ControlPoint> points, int at) {
            TaskF.ControlPoint us = new TaskF.ControlPoint(at, 0);
            NavigableSet<TaskF.ControlPoint> tail = points.tailSet(us, true);
            TaskF.ControlPoint next = tail.isEmpty() ? points.first() : tail.first();
            if (next.when == us.when) return next;
            NavigableSet<TaskF.ControlPoint> head = points.headSet(us, true);
            TaskF.ControlPoint prev = head.isEmpty() ? points.last() : head.last();
            int dx = next.when - prev.when;
            if (dx < 0) dx += period;
            long dv = next.value - prev.value;
            if (dv != 0) {
                if (Math.abs(dx) != Math.abs(dv)) throw new RuntimeException();
                long step = dv / dx;
                int odx = at - prev.when;
                if (odx < 0) odx += period;
                us.value = prev.value + odx * step;
            } else {
                us.value = prev.value;
            }
            points.add(us);
            return us;
        }

        static class ControlPoint implements Comparable<TaskF.ControlPoint> {
            int when;
            long value;

            public ControlPoint(int when, long value) {
                this.when = when;
                this.value = value;
            }


            public int compareTo(TaskF.ControlPoint o) {
                return when - o.when;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}