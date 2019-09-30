
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class ObservationWheel implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new ObservationWheel(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/D-small.in"));
            out = new PrintWriter("src/D-small.out");
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    // solution
    void solve() throws IOException {
        int n = readInt();
        for (int i = 1; i <= n; i++) {
            solveTestCase(i);
        }
    }

    void solveTestCase(int testcase) throws IOException {
        String s = readString();
        int mask = 0;
        for (int i = 0; i < s.length(); i++) {
            mask *= 2;
            if (s.charAt(i) == 'X') {
                mask++;
            }
        }
        f = new double[1 << s.length()];
        out.println("Case #" + testcase + ": " + calculate(mask, s.length()));
    }

    double calculate(int mask, int size) {
        if (mask == ((1 << size) - 1)) {
            return 0;
        }
        if (f[mask] != 0) {
            return f[mask];
        }
        double result = 0;
        for (int i = 0; i < size; i++) {
            Point p = attempt(i, mask, size);
            result += 1.0 / size * (p.x + calculate(p.y, size));
        }
        f[mask] = result;
        return f[mask];
    }
    double[] f;

    private Point attempt(int x, int mask, int size) {
        int cost = size;
        for (;; x--) {
            x = (x + size) % size;
            if ((mask & (1 << x)) == 0) {
                return new Point(cost, mask + (1 << x));
            }
            cost--;
        }
    }
}