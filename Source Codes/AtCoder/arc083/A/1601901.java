import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

    int A,B,C,D,E,F;

    public void solve() {
        A = nextInt();
        B = nextInt();
        C = nextInt();
        D = nextInt();
        E = nextInt();
        F = nextInt();

        boolean[] a = new boolean[3000 + 1];
        boolean[] b = new boolean[3000 + 1];

        for(int i = 0;i <= 30;i++) {
            for(int j = 0;j <= 30;j++) {
                int k = i * A * 100 + j * B * 100;
                if (k > 0 && k <= F) {
                    a[k] = true;
                }
            }
        }

        for(int i = 0;i <= 3000;i++) {
            for(int j = 0;j <= 3000;j++) {
                int k = i * C + j * D;
                if (k <= F) {
                    b[k] = true;
                }
            }
        }

        double max = 0;
        int ansA = 100 * A;
        int ansB = 0;

        for(int i = 0;i <= 3000;i++) {
            for(int j = 0;j <= 3000;j++) {
                if (a[i] && b[j] && i + j <= F && i / 100 * E >= j) {
                    double k = 100.0 * j / (i + j);
                    if (k >= max) {
                        max = k;
                        ansA = i + j;
                        ansB = j;
                    }
                }
            }
        }

        out.println(ansA + " " + ansB);
    }

    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[2048];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}