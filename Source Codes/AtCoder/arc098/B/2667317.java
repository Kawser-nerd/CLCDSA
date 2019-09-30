import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
            int[] values = in.na(n);
            long res = 0;
            int start = -1;
            int curf = 0;
            for (int t = 0; t < n; t++) {
                while ((curf & values[t]) != 0) {
                    curf -= values[++start];
                }
                curf += values[t];
                res += t - start;
            }
            out.println(res);
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