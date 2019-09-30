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

    int[] r = new int[]{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    private void solve(InputStreamScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            l.add(in.nextInt());
        }
        if (l.contains(9)) {
            if (l.contains(6)) {
                l.remove(new Integer("6"));
            }
        }
        if (l.contains(5)) {
            if (l.contains(3)) {
                l.remove(new Integer("3"));
            }
            if (l.contains(2)) {
                l.remove(new Integer("2"));
            }
        } else if (l.contains(3)) {
            if (l.contains(2)) {
                l.remove(new Integer("2"));
            }
        }

        int[] a = new int[l.size()];
        for (int i = 0; i < l.size(); i++) {
            a[i] = l.get(i);
        }

        String[] dp = new String[n + 1];
        Arrays.fill(dp, "");

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < a.length; j++) {
                int c = r[a[j]];
                if (c <= i && (!dp[i - c].equals("") || c == i)) {
                    String t = dp[i - c] + a[j];
                    if (dp[i] == "" || t.length() > dp[i].length()
                            || (t.length() == dp[i].length() && t.compareTo(dp[i]) > 0)) {
                        dp[i] = t;
                    }
                }
            }
        }

        out.println(dp[n]);
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