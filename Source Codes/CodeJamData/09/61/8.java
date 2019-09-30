import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter("A.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        List<List<Integer>> d = new ArrayList<List<Integer>>();
        for (int i = 0; i < m; i++) {
            List<Integer> q = new ArrayList<Integer>();
            int l = in.nextInt();
            q.add(0);
            for (int j = 1; j < l; j++) {
                q.add(in.nextInt() - 1);
            }
            d.add(q);
        }

        Number res = new Number(BigInteger.ZERO, BigInteger.ONE);

        for (int i = 0; i < m; i++) {
            List<Integer> q = d.get(i);
            for (int x : q) {
                if (x < n) {
                    res = res.add(new Number(BigInteger.valueOf(n - x), BigInteger.valueOf(n)));
                    for (int j = 0; j < m; j++)
                        if (j != i) {
                            for (int y : d.get(j)) {
                                if (y < n) {
                                    int z = Math.min(n - x, n - y);
                                    res = res.add(new Number(BigInteger.valueOf(z), BigInteger.valueOf(1L * n * n)));
                                }
                            }
                        }
                }
            }
        }

        return res.toString();
    }

    static class Number {
        BigInteger p;
        BigInteger q;

        Number(BigInteger p, BigInteger q) {
            this.p = p;
            this.q = q;
        }

        Number add(Number b) {
            BigInteger qq = q.multiply(b.q);
            BigInteger pp = p.multiply(b.q).add(b.p.multiply(q));
            Number res = new Number(pp, qq);
            res.norm();
            return res;
        }

        void norm() {
            BigInteger d = p.gcd(q);
            p = p.divide(d);
            q = q.divide(d);
        }

        @Override
        public String toString() {
            BigInteger a = p.divide(q);
            BigInteger b = p.mod(q);
            return "" + a + "+" + b + "/" + q;
        }
    }
}
