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
        int n = in.nextInt();

        if (n < 10) {
            out.println(0);
            return;
        }

        List<Integer> a = new ArrayList<>();
        Map<Integer, List<Integer>> m = new HashMap<>();

        for (int i = 2; i <= n; i++) {
            List<Integer> t = new ArrayList<>();
            int x = i;
            int c = 2;
            while (x != 1) {
                if (m.containsKey(x)) {
                    t.addAll(m.get(x));
                    break;
                }
                if (x % c == 0) {
                    t.add(c);
                    x /= c;
                } else {
                    c++;
                }
            }
            a.addAll(t);
            m.put(i, t);
        }

        Collections.sort(a);
        int[] r = new int[a.get(a.size() - 1) + 1];
        for (int i = a.get(0); i <= a.get(a.size() - 1); i++) {
            if (a.contains(i)) {
                r[i] = a.lastIndexOf(i) - a.indexOf(i) + 1;
            }
        }

        out.println(count(r, 75) + count(r, 25) * (count(r, 3) - 1) + count(r, 15) * (count(r, 5) - 1)
                + count(r, 5) * (count(r, 5) - 1) * (count(r, 3) - 2) / 2);
    }

    private int count(int[] r, int n) {
        int c = 0;
        for (int i = 0; i < r.length; i++) {
            if (r[i] >= n - 1) {
                c++;
            }
        }
        return c;
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