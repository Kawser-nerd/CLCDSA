import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class B {

    double chooseAtLeast(int n, int k) {
        double res = 0;
        for (int i = k; i <= n; i++) {
            double x = choose(n, i);
            res += x;
//            System.err.println("choose n = " + n + " k = " + i + " -> " + x);
        }
        return res;
    }

    double choose(int n, int k) {
        BigInteger res = BigInteger.ONE;
        for (int i = k + 1; i <= n; i++) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        BigInteger div = BigInteger.ONE;
        for (int i = 2; i <= n - k; i++) {
            div = div.multiply(BigInteger.valueOf(i));
        }
        return res.divide(div).doubleValue();
    }

    private double solve(int n, int qx, int qy) {
        int d = (Math.abs(qx) + qy) / 2;
        System.err.println("d = " + d);
        int sub = 1;
        for (int i = 0; i < d; i++) {
            n -= sub;
            sub += 4;
        }

        if (2 * d == qy && n < sub) {
            System.err.println("ret 1");
            return 0;
        }
        if ((sub - 1) / 2 + qy + 1 <= n) {
            return 1;
        }
        System.err.println("n = " + n + " sub = " + sub + " d = " + d + " qy = "+ qy + " qx = " + qx);

        if (n <= 0) {
            System.err.println("ret 2");
            return 0;
        } else if (n >= sub) {
            System.err.println("ret 3");
            return 1;
        }
        return (chooseAtLeast(n, qy + 1) + 0.0) / BigInteger.ONE.shiftLeft(n).doubleValue();
    }

    void run() throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
//        Scanner in = new Scanner(new File("test"));
        int t = in.nextInt();
        for (int it = 0; it < t; it++) {
            System.out.print("Case #" + (it + 1) + ": ");
            int n = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            System.out.println(solve(n, x, y));

        }
    }


    public static void main(String[] args) throws FileNotFoundException {
        long x = System.currentTimeMillis();
        BigInteger r = BigInteger.ONE;
        for (int i = 0; i < 1000000; i++) {
            r = r.multiply(BigInteger.valueOf(i));
        }
        System.err.println(System.currentTimeMillis() - x);
        new B().run();
    }
}
