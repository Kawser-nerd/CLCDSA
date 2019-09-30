import java.io.*;
import java.util.*;

public class B {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    int getStart(int sum) {
        int n = (int)Math.sqrt(sum);
        while (n > 1 && n * (n + 1) / 2 >= sum) {
            n--;
        }
        while (n * (n + 1) / 2 < sum) {
            n++;
        }
        return n;
    }

    String solveOne(int x, int y, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = n; i >= 1; i--) {
            if (Math.abs(x) > Math.abs(y)) {
                if (x < 0) {
                    x += i;
                    sb.append('E');
                } else {
                    x -= i;
                    sb.append('W');
                }
            } else {
                if (y < 0) {
                    y += i;
                    sb.append('N');
                } else {
                    y -= i;
                    sb.append('S');
                }
            }
        }
        if (x == 0 && y == 0) {
            sb.reverse();
            return sb.toString();
        } else {
            return null;
        }
    }

    void check(int xR, int yR, String s) {
        int x = 0;
        int y = 0;
        for (int i = 1; i <= s.length(); i++) {
            char c = s.charAt(i - 1);
            if (c == 'N') {
                y += i;
            } else if (c == 'S') {
                y -= i;
            } else if (c == 'E') {
                x += i;
            } else if (c == 'W') {
                x -= i;
            } else {
                throw new Error();
            }
        }
        Assert.check(x == xR && y == yR);
    }

    String solveOne(int x, int y) {
        int n0 = getStart(Math.abs(x) + Math.abs(y));
        for (int n = n0; ; n++) {
            String s = solveOne(-x, -y, n);
            if (s != null) {
                check(x, y, s);
                return s;
            }
        }
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.printf("Case #%d: %s%n", i, solveOne(in.nextInt(), in.nextInt()));
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new B().run();
    }
}
