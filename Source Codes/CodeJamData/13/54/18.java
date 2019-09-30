import java.io.*;
import java.util.*;

public class D {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    double solveOne(String pattern) {
        int len = pattern.length();
        double money[] = new double[1 << len];
        for (int code = 1; code < (1 << len); code++) {
            int firstEmptyShift = -1;
            for (int shift = 0; shift < len; shift++) {
                if (((code >> shift) & 1) == 1) {
                    firstEmptyShift = shift;
                    break;
                }
            }
            Assert.check(firstEmptyShift != -1);
            int occupiedCount = 0;
            double curMoney = 0;
            for (int shift = firstEmptyShift + 1; shift < len; shift++) {
                if (((code >> shift) & 1) == 0) {
                    occupiedCount++;
                } else {
                    curMoney += money[code - (1 << shift)] * (occupiedCount + 1) + (len + len - occupiedCount) * (occupiedCount + 1) / 2;
                    occupiedCount = 0;
                }
            }
            for (int shift = 0; shift <= firstEmptyShift; shift++) {
                if (((code >> shift) & 1) == 0) {
                    occupiedCount++;
                } else {
                    curMoney += money[code - (1 << shift)] * (occupiedCount + 1) + (len + len - occupiedCount) * (occupiedCount + 1) / 2;
                    occupiedCount = 0;
                }
            }
            Assert.check(occupiedCount == 0);
            money[code] = curMoney / len;
        }
        int code = 0;
        for (int i = 0; i < len; i++) {
            if (pattern.charAt(i) == '.') {
                code |= 1 << i;
            } else {
                Assert.check(pattern.charAt(i) == 'X');
            }
        }
        return money[code];
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.println("Case #" + i + ": " + solveOne(in.next()));
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
        new D().run();
    }
}