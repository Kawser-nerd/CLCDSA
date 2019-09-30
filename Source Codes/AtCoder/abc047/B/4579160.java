import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        InputStreamScanner in = new InputStreamScanner(System.in);
        new Main().solve(in, out);
        out.flush();
    }

    private void solve(InputStreamScanner in, PrintWriter out) {
        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        int[][] c = new int[h][w];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int a = in.nextInt();

            if (a == 1) {
                for (int j = 0; j < h; j++) {
                    for (int k = 0; k < x; k++) {
                        c[j][k] = 1;
                    }
                }
            } else if (a == 2) {
                for (int j = 0; j < h; j++) {
                    for (int k = x; k < w; k++) {
                        c[j][k] = 1;
                    }
                }
            } else if (a == 3) {
                for (int j = 0; j < y; j++) {
                    for (int k = 0; k < w; k++) {
                        c[j][k] = 1;
                    }
                }
            } else if (a == 4) {
                for (int j = y; j < h; j++) {
                    for (int k = 0; k < w; k++) {
                        c[j][k] = 1;
                    }
                }
            }
        }

        int r = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (c[i][j] == 0) {
                    r++;
                }
            }
        }

        out.println(r);
    }

    static class InputStreamScanner {

        private InputStream in;

        private byte[] buf = new byte[1024];
        private int len = 0;
        private int off = 0;

        InputStreamScanner(InputStream in)	{
            this.in = in;
        }

        String next() {
            StringBuilder sb = new StringBuilder();
            for (int b = skip(); !isSpace(b);){
                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        char nextChar() {
            return (char)skip();
        }

        int skip() {
            for (int b; (b = read()) != -1;) {
                if (!isSpace(b)) {
                    return b;
                }
            }
            return -1;
        }

        private boolean isSpace(int c) {
            return c < 33 || c > 126;
        }

        private int read() {
            if (len == -1) {
                throw new InputMismatchException("End of Input");
            }
            if (off >= len){
                off = 0;
                try {
                    len = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException(e.getMessage());
                }
                if (len <= 0) {
                    return -1;
                }
            }
            return buf[off++];
        }
    }
}