import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            Segment[] a = new Segment[n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = new Segment(in.nextInt(), in.nextInt(), i);
            }
            a[n] = new Segment(0, 0, n);
            n++;
            List<Event> ev = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ev.add(new Event(a[i].l, -1));
                ev.add(new Event(a[i].r, 1));
            }
            int open = 0, closed = n;
            long ans = 0;
            ev.sort(Event::compareTo);
            for (int i = 0; i < ev.size(); i++) {
                if (i > 0 && Math.min(open, closed) > 0 && ev.get(i).pos > ev.get(i - 1).pos) {
//                System.err.println(Math.min(open, closed) + " " + ev.get(i - 1).pos + " " + ev.get(i).pos);
                    ans += (long) (Math.min(open, closed) * 2) * (ev.get(i).pos - ev.get(i - 1).pos);
                }
                if (ev.get(i).type == -1) {
                    closed--;
                } else {
                    open++;
                }
            }
            out.println(ans);
        }

        class Event implements Comparable<Event> {
            int pos;
            int type;

            public Event(int pos, int type) {
                this.pos = pos;
                this.type = type;
            }


            public int compareTo(Event o) {
                if (pos != o.pos) {
                    return pos - o.pos;
                }
                return type - o.type;
            }

        }

        class Segment {
            int l;
            int r;
            int i;

            public Segment(int l, int r, int i) {
                this.l = l;
                this.r = r;
                this.i = i;
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}