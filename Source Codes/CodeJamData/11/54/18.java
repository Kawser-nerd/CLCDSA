import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        String s = next();
        long certain = 0;
        long uncertainMask = 0;
        for (int i = 0; i < s.length(); ++i) {
            certain <<= 1;
            uncertainMask <<= 1;
            switch (s.charAt(i)) {
                case '0':
                    break;
                case '1':
                    certain |= 1;
                    break;
                case '?':
                    uncertainMask |= 1;
                    break;
            }
        }
//        System.err.println(Long.toBinaryString(certain) + " " + Long.toBinaryString(uncertainMask));
        boolean first = true;
        for (long t = uncertainMask; first || t != uncertainMask; t = (t - 1) & uncertainMask) {
//            System.err.println(t + "?");
            first = false;
            long v = certain | t;
            long sqrt = (long) Math.sqrt(v);
            if (sqrt * sqrt == v || (sqrt - 1) * (sqrt - 1) == v || (sqrt + 1) * (sqrt + 1) == v) {
                out.println(prefix + Long.toBinaryString(v));
                return;
            }
        }

        throw new AssertionError();
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(D.class.getSimpleName() + ".in"));
        out = new PrintWriter(D.class.getSimpleName() + ".out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d: ", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }
}
