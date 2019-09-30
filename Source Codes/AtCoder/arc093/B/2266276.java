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
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;

            out.println("100 100");


            char[][] res = new char[100][100];
            for (int s = 0; s < 50; s++) {
                Arrays.fill(res[s], '.');
                Arrays.fill(res[s + 50], '#');
            }

            for (int i = 0; i < 50; i += 2) {
                for (int r = 0; r < 100; r += 2) {
                    if (b > 0) {
                        res[i][r] = '#';
                        b--;
                    }
                }
            }

            for (int i = 51; i < 100; i += 2) {
                for (int r = 0; r < 100; r += 2) {
                    if (a > 0) {
                        res[i][r] = '.';
                        a--;
                    }
                }
            }


            for (char[] l : res) {
                out.println(new String(l));
            }


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
}