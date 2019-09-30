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
        String n = in.next();

        if (n.length() == 1) {
            out.println(n);
            return;
        }
        if (n.substring(1).replace("9", "").length() == 0) {
            int x = 0;
            for (int i = 0; i < n.length(); i++) {
                x += Integer.parseInt(n.substring(i, i + 1));
            }
            out.println(x);
            return;
        }

        if (n.charAt(1) != '9') {
            int x = 0;
            if (n.charAt(0) != '1') {
                x += Character.getNumericValue(n.charAt(0) - 1);
            }
            for (int i = 0; i < n.length() - 1; i++) {
                x += 9;
            }
            out.println(x);
            return;
        }

        List<Integer> a =  new ArrayList<>();
        a.add(Character.getNumericValue(n.charAt(0)));
        int x = -1;
        for (int i = 1; i < n.length(); i++) {
            if (n.charAt(i) != '9') {
                for (int j = 0; j < x; j++) {
                    a.add(9);
                }
                a.add(8);
                for (int j = i; j < n.length(); j++) {
                    a.add(9);
                }
            } else {
                x++;
            }
        }

        int r = 0;
        for (int m : a) {
            r += m;
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