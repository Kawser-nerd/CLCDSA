
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class ManyPrizes implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new ManyPrizes(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            // out = new PrintWriter("manyprizes.out");

            Locale.setDefault(Locale.US);
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

    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }
    static final char EMPTY = '.';

    void solveTestCase(int number) throws IOException {
        int rounds = readInt();
        long n = (1L << rounds);
        long p = readLong();
        long l = 0;
        long r = n - 1;
        long m1 = -1;
        while (l <= r) {
            m1 = (l + r) / 2;
            if (alwaysWin(m1, rounds, n, p) && (m1 == (n - 1) || !alwaysWin(m1 + 1, rounds, n, p))) {
                break;
            } else if (alwaysWin(m1, rounds, n, p)) {
                l = m1 + 1;
            } else {
                r = m1 - 1;
            }
        }
        l = 0;
        r = n - 1;
        long m2 = -1;
        while (l <= r) {
            m2 = (l + r) / 2;
            if (mayhapsWin(m2, rounds, n, p) && (m2 == (n - 1) || !mayhapsWin(m2 + 1, rounds, n, p))) {
                break;
            } else if (mayhapsWin(m2, rounds, n, p)) {
                l = m2 + 1;
            } else {
                r = m2 - 1;
            }
        }

        out.println("Case #" + number + ": " + m1 + " " + m2);
    }

    boolean alwaysWin(long team, int rounds, long n, long prizes) {
        long mask = 0;
        long betterTeams = team;
        for (int i = rounds - 1; i >= 0; i--) {
            if (betterTeams > 0) {
                mask += (1L << i);
                betterTeams -= 1;//played with us and won
                betterTeams /= 2;//lower half loses
            }
        }
        return mask < prizes;
    }

    boolean mayhapsWin(long team, int rounds, long n, long prizes) {
        long mask = 0;
        long worseTeams = n - team - 1;
        for (int i = rounds - 1; i >= 0; i--) {
            if (worseTeams > 0) {
                worseTeams -= 1;//played with us and lost
                worseTeams /= 2;//lower half wins
            } else {
                mask += (1L << i);
            }
        }
        return mask < prizes;
    }
}