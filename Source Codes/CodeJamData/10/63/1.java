package y2010.finals;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        long k = in.nextLong();
        long c = in.nextLong();
        long s = k;
        long d = k;
        for (long q = 2; q <= c; q = Math.max(q + 1, s / k)) {
            long z = s / q;
            if (z < k) {
                z = k - z;
                s += q * z;
                d += z;
            }
        }
        return "" + d;
    }
}