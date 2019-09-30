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
                InputReader in = new InputReader(inputStream);
                PrintWriter out = new PrintWriter(outputStream);
                TaskC solver = new TaskC();
                solver.solve(1, in, out);
                out.close();
        }

        static class TaskC {
                public void solve(int testNumber, InputReader in, PrintWriter out) {
                        int n = in.i();
                        int[][] arr = new int[2][n];
                        for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < n; j++) arr[i][j] = in.i();
                        }
                        long[] first = new long[n + 1];
                        long[] sec = new long[n + 1];
                        for (int i = 1; i <= n; i++) first[i] = first[i - 1] + arr[0][i - 1];
                        for (int i = 1; i <= n; i++) sec[i] = sec[i - 1] + arr[1][i - 1];
                        long max = 0;
                        for (int i = 1; i <= n; i++) {
                                max = Math.max(max, first[i] + sec[n] - sec[i - 1]);
                        }
                        out.println(max);
                }

        }

        static class InputReader {
                InputStream is;
                private byte[] inbuf = new byte[1024];
                public int lenbuf = 0;
                public int ptrbuf = 0;

                public InputReader(InputStream is) {
                        this.is = is;
                }

                private int readByte() {
                        if (lenbuf == -1) throw new InputMismatchException();
                        if (ptrbuf >= lenbuf) {
                                ptrbuf = 0;
                                try {
                                        lenbuf = is.read(inbuf);
                                } catch (IOException e) {
                                        throw new InputMismatchException();
                                }
                                if (lenbuf <= 0) return -1;
                        }
                        return inbuf[ptrbuf++];
                }

                public int i() {
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