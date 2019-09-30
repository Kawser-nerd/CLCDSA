import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {

    int N,A,B;
    int[] S;

    private void solve() {
        N = nextInt();
        A = nextInt();
        B = nextInt();
        S = new int[N];
        for(int i = 0;i < N;i++) {
            S[i] = nextInt();
        }

        double min = Double.MAX_VALUE;
        double max = Double.MIN_VALUE;
        for(int i = 0;i < N;i++) {
            min = Math.min(min,S[i]);
            max = Math.max(max,S[i]);
        }

        double E = max - min;

        if (E == 0) {
            out.println(-1);
            return;
        }

        double P = B / E;

        double sum = 0;
        for(int i = 0;i < N;i++) {
            sum += S[i] * P;
        }

        double avg = sum / N;
        double Q = A - avg;

        out.println(P + " " + Q);

    }
    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[4096];
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