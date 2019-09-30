import java.util.Scanner;
import java.math.BigDecimal;

/**
 * Author: Vitaly Goldshteyn
 */
public class Small implements Runnable {
    Scanner in;
    public static void main(String[] args) {
        new Small().run();
    }

    BigDecimal k5;

    BigDecimal sqrtfive() {
        BigDecimal l = new BigDecimal(0).setScale(100),
                   r = new BigDecimal(5).setScale(100),
                   five = new BigDecimal(5);
        for(int i = 0; i <= 400; ++i) {
            BigDecimal m = l.add(r).divide(new BigDecimal(2), BigDecimal.ROUND_DOWN);
            if (m.multiply(m).compareTo(five) <= 0) l = m; else r = m;
        }
        System.err.println("sqrt(5) = " + l);
        return l;
    }

    public void run() {
        in = new Scanner(System.in);
        k5 = sqrtfive().add(new BigDecimal(3));
        int tst = in.nextInt();
        for(int i = 1; i <= tst; ++i) {
            System.out.print("Case #" + i + ": ");
            test();
        }
    }

    private void test() {
        int n = in.nextInt();
        BigDecimal res = k5.pow(n);
        String c = res.toString();
        c = c.split("\\.")[0];
        while (c.length() < 3) c = "0" + c;
        c = c.substring(c.length() - 3);
        System.out.println(c);
    }
}
