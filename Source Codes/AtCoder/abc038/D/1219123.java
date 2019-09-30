import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int n;
        ArrayList<Pair> list = new ArrayList<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int w = in.nextInt();
                int h = in.nextInt();
                list.add(new Pair(w, h));
            }

            Collections.sort(list);

            int ans = 0;

            RMQ rmq = new RMQ(100010);

            for (int i = 0; i < n; i++) {
                int lower = rmq.query(0, list.get(i).y - 1);
                rmq.update(list.get(i).y, lower + 1);

                ans = Math.max(ans, lower + 1);
            }

            out.println(ans);
        }

        public class Pair implements Comparable<Pair> {
            int x;
            int y;

            public Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return x == p.x ? p.y - y : x - p.x;
            }

        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }

    static class RMQ {
        int n;
        int[] dat;

        public RMQ(int n1) {
            n = 1;
            while (n < n1) {
                n <<= 1;
            }
            dat = new int[2 * n - 1];
            //Arrays.fill(dat, Integer.MAX_VALUE);
        }

        public void update(int k, int a) {
            k += n - 1;
            dat[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                //dat[k] = Math.min(dat[k * 2 + 1], dat[k * 2 + 2]);
                dat[k] = Math.max(dat[k * 2 + 1], dat[k * 2 + 2]);
            }
        }

        public int query(int a, int b) {
            return query(a, b + 1, 0, 0, n);
        }

        private int query(int a, int b, int k, int l, int r) {
            //if (r <= a || b <= l) return Integer.MAX_VALUE;
            if (r <= a || b <= l) return 0;

            if (a <= l && r <= b) {
                return dat[k];
            } else {
                int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                //return Math.min(vl, vr);
                return Math.max(vl, vr);
            }
        }

    }
}