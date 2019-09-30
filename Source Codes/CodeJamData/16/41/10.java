package round2;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round2/A-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round2/A-small-attempt0.in"), new FileOutputStream("round2/A-small-0.out"));
        io = new Kattio(new FileInputStream("round2/A-large.in"), new FileOutputStream("round2/A-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }

    private String smallest(char c, int depth) {
        if (depth == 0) return "" + c;
        String left, right;
        if (c == 'P') {
            left = smallest('P', depth - 1);
            right = smallest('R', depth - 1);
        } else if (c == 'R') {
            left = smallest('R', depth - 1);
            right = smallest('S', depth - 1);
        } else if (c == 'S') {
            left = smallest('P', depth - 1);
            right = smallest('S', depth - 1);
        } else {
            throw new RuntimeException();
        }
        if (left.compareTo(right) > 0) {
            return right + left;
        } else {
            return left + right;
        }
    }

    private int[] cnt(String s) {
        int[] res = new int[3];
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'P': res[0]++; break;
                case 'R': res[1]++; break;
                case 'S': res[2]++; break;
            }
        }
        return res;
    }

    private void solve(Kattio io) {
        int n = io.getInt(), r = io.getInt(), p = io.getInt(), s = io.getInt();

        int[] pcnt = cnt(smallest('P', n));
        int[] rcnt = cnt(smallest('R', n));
        int[] scnt = cnt(smallest('S', n));
        if (pcnt[0] == p && pcnt[1] == r && pcnt[2] == s) {
            io.println(smallest('P', n));
        } else if (rcnt[0] == p && rcnt[1] == r && rcnt[2] == s) {
            io.println(smallest('R', n));
        } else if (scnt[0] == p && scnt[1] == r && scnt[2] == s) {
            io.println(smallest('S', n));
        } else {
            io.println("IMPOSSIBLE");
        }
    }
}
