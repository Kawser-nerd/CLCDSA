package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1b/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1b/B-small-attempt0.in"), new FileOutputStream("round1b/B-small-0.out"));
        io = new Kattio(new FileInputStream("round1b/B-large.in"), new FileOutputStream("round1b/B-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new B().solve(io);
        }
        io.close();
    }

    private long best = Long.MAX_VALUE;
    private long besta, bestb;

    private long maximize(String a, long an, int pos, long p) {
        if (pos >= a.length()) return an;
        boolean wilda = a.charAt(pos) == '?';
        if (wilda) return maximize(a, an+9*p, pos+1, p/10);
        int ac = a.charAt(pos) - '0';
        return maximize(a, an+ac*p, pos+1, p/10);
    }

    private long minimize(String a, long an, int pos, long p) {
        if (pos >= a.length()) return an;
        boolean wilda = a.charAt(pos) == '?';
        if (wilda) return minimize(a, an, pos+1, p/10);
        int ac = a.charAt(pos) - '0';
        return minimize(a, an+ac*p, pos+1, p/10);
    }

    private void solve(String a, String b, int pos, long an, long bn, long p) {
        long dif = an-bn;
        if (pos >= a.length()) {
            if (Math.abs(dif) < best) {
                best = Math.abs(an-bn);
                besta = an;
                bestb = bn;
            } else if (Math.abs(dif) == best) {
                if (an < besta || (an == besta && bn < bestb)) {
                    besta = an;
                    bestb = bn;
                }
            }
            return;
        }

        if (dif < 0) {
            an = maximize(a, an, pos, p);
            bn = minimize(b, bn, pos, p);
            solve(a, b, a.length(), an, bn, 1);
            return;
        }
        if (dif > 0) {
            an = minimize(a, an, pos, p);
            bn = maximize(b, bn, pos, p);
            solve(a, b, a.length(), an, bn, 1);
            return;
        }

        int ac = a.charAt(pos) - '0';
        int bc = b.charAt(pos) - '0';
        boolean wilda = a.charAt(pos) == '?';
        boolean wildb = b.charAt(pos) == '?';

        if (!wilda && !wildb) {
            solve(a, b, pos+1, an+ac*p, bn+bc*p,p/10);
        } else if (wilda && wildb) {
            solve(a, b, pos+1, an, bn,p/10); // 0 0
            solve(a, b, pos+1, an+p, bn,p/10); // 1 0
            solve(a, b, pos+1, an, bn+p,p/10); // 0 1
        } else if (wilda) {
            solve(a, b, pos+1, an+bc*p, bn+bc*p,p/10); // x x
            if (bc > 0) solve(a, b, pos+1, an+(bc-1)*p, bn+bc*p,p/10); // (x-1) x
            if (bc < 9) solve(a, b, pos+1, an+(bc+1)*p, bn+bc*p,p/10); // (x+1) x
        } else if (wildb) {
            solve(a, b, pos+1, an+ac*p, bn+ac*p,p/10); // x x
            if (ac > 0) solve(a, b, pos+1, an+ac*p, bn+(ac-1)*p,p/10); // x (x-1)
            if (ac < 9) solve(a, b, pos+1, an+ac*p, bn+(ac+1)*p,p/10); // x (x+1)
        }
/*
        for (int i = 0; i < 10; i++) {
            if (!wilda && ac!=i) continue;
            for (int j = 0; j < 10; j++) {
                if (!wildb && bc!=j) continue;
                solve(a, b, pos+1, an+i*p, bn+j*p,p/10);
            }
        }
*/
    }

    private void solve(Kattio io) {
        String a = io.getWord(), b = io.getWord();
        long p = 1;
        for (int i = 1; i < a.length(); i++) {
            p *= 10;
        }
        solve(a,b,0,0,0,p);
        String formatString = "%0" + a.length() + "d %0" + b.length() + "d";
        io.println(String.format(formatString, besta, bestb));
    }
}
