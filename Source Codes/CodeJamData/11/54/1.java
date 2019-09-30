import java.util.*;
import java.io.*;

class DEasy {
    Scanner in;
    PrintWriter out;

    String s;
    int l;
    long ans;

    boolean check(long v) {
        long s = Math.round(Math.sqrt(v));

        if (s * s == v) {
            ans = v;
            return true;
        }
        return false;
    }

    boolean bt(int p, long v) {
        if (p == l) {
            return check(v);
        }
        char c = s.charAt(p);
        if (c == '0') {
            return bt(p + 1, 2 * v);
        } else if (c == '1') {
            return bt(p + 1, 2 * v + 1);
        } else {
            return bt(p + 1, 2 * v) || bt(p + 1, 2 * v + 1);
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            s = in.next();
            l = s.length();
            bt(0, 0);
            out.println("Case #" + test + ": " + Long.toBinaryString(ans));
        }
    }

    public void run() {
        try {
            in = new Scanner(new File("D-small-attempt0.in"));
            out = new PrintWriter(new File("D-small-attempt0.out"));

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new DEasy().run();
    }
}