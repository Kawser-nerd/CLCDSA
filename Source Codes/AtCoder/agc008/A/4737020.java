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
        int x = in.nextInt();
        int y = in.nextInt();

        int absx = Math.abs(x);
        int absy = Math.abs(y);

        if (absx < absy) {
            if (x > 0 && y > 0) {
                out.println(absy - absx);
                return;
            } else if (x < 0 && y > 0) {
                out.println(absy - absx + 1);
                return;
            } else if (x > 0 && y < 0) {
                out.println(absy - absx + 1);
                return;
            } else if (x < 0 && y < 0) {
                out.println(absy - absx + 2);
                return;
            } else {
                if (y > 0) {
                    out.println(absy - absx);
                    return;
                } else if (y < 0) {
                    out.println(absy - absx + 1);
                    return;
                }
            }
        } else if (absx > absy) {
            if (x > 0 && y > 0) {
                out.println(absx - absy + 2);
                return;
            } else if (x < 0 && y > 0) {
                out.println(absx - absy + 1);
                return;
            } else if (x > 0 && y < 0) {
                out.println(absx - absy + 1);
                return;
            } else if (x < 0 && y < 0) {
                out.println(absx - absy);
                return;
            } else {
                if (x > 0) {
                    out.println(absx - absy + 1);
                    return;
                } else if (x < 0) {
                    out.println(absx - absy);
                    return;
                }
            }

        } else {
            out.println(1);
            return;
        }
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