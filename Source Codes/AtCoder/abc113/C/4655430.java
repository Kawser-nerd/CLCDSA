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
        int m = in.nextInt();

        HashMap<Integer, TreeSet<Integer>> c = new HashMap<>();
        int[][] d = new int[2][m];
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            int u = in.nextInt();
            d[0][i] = t;
            d[1][i] = u;
            TreeSet<Integer> x = c.getOrDefault(t, new TreeSet<>());
            x.add(u);
            c.put(t, x);
        }

        HashMap<Integer, ArrayList<Integer>> h = new HashMap<>();
        for (Map.Entry<Integer, TreeSet<Integer>> e : c.entrySet()) {
            h.put(e.getKey(), new ArrayList<>(e.getValue()));
        }

        for (int i = 0; i < m; i++) {

            ArrayList<Integer> x = h.get(d[0][i]);
            int index = Collections.binarySearch(x, d[1][i]);

            out.printf("%06d%06d\n", d[0][i], index + 1);
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