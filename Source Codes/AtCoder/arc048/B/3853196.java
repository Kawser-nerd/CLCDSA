import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.HashMap;
import java.io.IOException;
import java.util.NoSuchElementException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();

            TreeMap<Integer, Integer> wr = new TreeMap<>();
            HashMap<Integer, Integer> rh1 = new HashMap<>();
            HashMap<Integer, Integer> rh2 = new HashMap<>();
            HashMap<Integer, Integer> rh3 = new HashMap<>();

            int[] r = new int[n];
            int[] h = new int[n];
            for (int i = 0; i < n; i++) {
                r[i] = in.nextInt();
                h[i] = in.nextInt();
                wr.put(r[i], 0);
                switch (h[i]) {
                    case 1:
                        rh1.put(r[i], rh1.getOrDefault(r[i], 0) + 1);
                        break;
                    case 2:
                        rh2.put(r[i], rh2.getOrDefault(r[i], 0) + 1);
                        break;
                    case 3:
                        rh3.put(r[i], rh3.getOrDefault(r[i], 0) + 1);
                }
            }

            int pre = 0;
            for (int cr : wr.keySet()) {
                wr.put(cr, pre);
                pre += rh1.getOrDefault(cr, 0);
                pre += rh2.getOrDefault(cr, 0);
                pre += rh3.getOrDefault(cr, 0);
            }

            for (int i = 0; i < n; i++) {
                int cr = r[i];
                int ch = h[i];
                int chw = 0;
                int cd = 0;
                switch (ch) {
                    case 1:
                        chw = rh2.getOrDefault(cr, 0);
                        cd = rh1.get(cr) - 1;
                        break;
                    case 2:
                        chw = rh3.getOrDefault(cr, 0);
                        cd = rh2.get(cr) - 1;
                        break;
                    case 3:
                        chw = rh1.getOrDefault(cr, 0);
                        cd = rh3.get(cr) - 1;
                }
                int cw = wr.get(cr) + chw;
                int cl = n - 1 - cw - cd;
                out.printf("%d %d %d\n", cw, cl, cd);
            }
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            buffer = new byte[1024];
        }

        private boolean hasNextByte() {
            if (bufPointer < bufLength) return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        private int readByte() {
            return hasNextByte() ? buffer[bufPointer++] : -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer]))
                bufPointer++;
            return hasNextByte();
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || b > '9')
                throw new NumberFormatException();

            while (true) {
                if (b >= '0' && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

    }
}