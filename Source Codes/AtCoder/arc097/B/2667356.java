import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] data = new int[n];
            for (int s = 0; s < n; s++) {
                data[s] = in.nextInt() - 1;
            }
            DS ds = new DS(n);
            for (int f = 0; f < m; f++) {
                ds.union(in.nextInt() - 1, in.nextInt() - 1);
            }
            int l = 0;
            for (int s = 0; s < n; s++) {
                if (ds.root(s) == ds.root(data[s])) {
                    l++;
                }
            }
            out.println(l);
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

    static class DS {
        int[] par;
        int[] ct;

        public DS(int n) {
            par = new int[n];
            ct = new int[n];
            clear();
        }

        public void clear() {
            Arrays.fill(ct, 1);
            Arrays.setAll(par, i -> i);
        }

        public int root(int a) {
            int q = a;
            while (q != par[q]) {
                q = par[q];
            }
            while (a != q) {
                int next = par[a];
                par[a] = q;
                a = next;
            }
            return q;
        }

        public void union(int l1, int l2) {
            int r1 = root(l1);
            int r2 = root(l2);
            if (r1 == r2) return;
            if (ct[r2] < ct[r1]) {
                int s = r1;
                r1 = r2;
                r2 = s;
            }

            par[r1] = r2;
            ct[r2] += ct[r1];
        }

    }
}